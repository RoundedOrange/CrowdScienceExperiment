#include<iostream>
#include<iomanip>
using namespace std;
double* operate(int** array,double* degrees, int n)
{
	double* result = new double[n];
	for (int i = 0; i < n; i++)
		result[i] = 0;
	for (int i = 0; i < n; i++)
	{
		int totalOfI = 0;
		for (int j = 0; j < n; j++)
			if (array[i][j] == 1)
				totalOfI++;
		for (int j = 0; j < n; j++)
			if (array[i][j] == 1)
				result[j] += (double)degrees[i] / totalOfI;
	}
	return result;
}
void display(double* degrees,int n)
{
	cout << setiosflags(ios_base::fixed)<<setprecision(4);
	cout << "节点：";
	for (int i = 0; i < n; i++)
	{
		cout << setw(10)<<i+1;
		if (i != n - 1)
			cout << "|";
	}
	cout << endl;
	cout << "流量：";
	for (int i = 0; i < n; i++)
	{
		cout << setw(10) << degrees[i];
		if (i != n - 1)
			cout << "|";
	}
	cout << endl;
}
bool isBalanced(double* before,double* after,int n)
{
	for (int i = 0; i < n; i++)
		if (abs(before[i] - after[i]) > 0.0001)
			return false;
	return true;
}
void adjust(double* degrees,int n)
{
	double rate = 0.85;
	for (int i = 0; i < n; i++)
		degrees[i] = degrees[i]*rate+1-rate;
}
void toUndirected(int** array,int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j <n ; j++)
			if (array[i][j] == 1)
				array[j][i] = 1;
}
bool satisfy(int** array,int n,int x,int y,int maxStep)
{
	if (x == y)
		return true;
	if (maxStep == 0)
		return false;
	for (int i = 0; i < n; i++)
		if (array[x][i] == 1&& satisfy(array, n, i, y, maxStep - 1))
				return true;
	return false;
}
int main()
{
	cout << "输入节点数：";
	int n;
	cin >> n;
	int** array = new int* [n];
	for (int i = 0; i < n; i++)
		array[i] = new int[n];
	cout << "输入矩阵：" << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> array[i][j];
	double* degrees = new double[n];
	for (int i = 0; i < n; i++)
		degrees[i] = 1;
	int times;
	cout << "输入最多迭代次数：";
	cin >> times;
	double* result;
	for (int i = 0; true; i++)
	{
		result=operate(array,degrees, n);
		if (isBalanced(degrees, result, n))
			break;
		if (i >= times)
		{
			cout << "超出迭代次数" << endl;
			return 1;
		}
		adjust(degrees, n);
		for (int i = 0; i < n; i++)
			degrees[i] = result[i];
	}
	cout << "最终结果：" << endl;
	display(result, n);
	toUndirected(array, n);
	int temp = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (satisfy(array, n, i, j,6))
				temp++;	
	cout << "符合六度空间理论的占比：" << (double)temp / n * 100 << "%" << endl;
	return 0;
}