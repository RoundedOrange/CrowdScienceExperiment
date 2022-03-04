#include<iostream>
#include<iomanip>
using namespace std;
template<class T>
void sort(T* array,int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i; j++)
			if (array[i] < array[i + j])
			{
				T temp = array[i];
				array[i] = array[i + j];
				array[i + j] = temp;
			}
}
double** createMatrix(double* cols,double* rows,int n)
{
	double** matrix = new double* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new double[n];
		for (int j = 0; j < n; j++)
			matrix[i][j] = rows[i] * cols[j];
	}
	return matrix;
}
void gsp(double** matrix,int n)
{
	double* cost = new double[n];
	double* reward = new double[n];
	cout << "商家标号|GSP出价 |回报    " << endl;
	for (int i = 0; i < n - 1; i++)
	{
		cost[i] = matrix[i + 1][i];
		reward[i] = matrix[i][i] - cost[i];
		cout << setw(8)<<i + 1 <<"|" <<setw(8)<< cost[i]<<"|"<<setw(8) << reward[i] << endl;
	}
	cost[n - 1] = 0;
	reward[n - 1] = matrix[n - 1][n - 1];
	cout <<setw(8)<< n <<"|" <<setw(8)<< cost[n - 1] <<"|" <<setw(8)<< reward[n - 1] << endl;
}
void vcg(double** matrix, int n)
{
	double* result = new double[n];
	for (int i = 0; i < n; i++)
		result[i] = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i; j < n - 2; j++)
			result[i] += matrix[j + 1][j] - matrix[j + 1][j + 1];
	result[n - 1] = 0;
	cout << "商家标号|VCG价格 " << endl;
	for (int i = 0; i < n; i++)
		cout << setw(8)<<i + 1 <<"|" <<setw(8)<< result[i] << endl;
}
int main()
{
	int n;
	cout << "输入个数：";
	cin >> n;
	double* rates = new double[n];
	double* values = new double[n];
	cout << "输入各个点击率：" << endl;
	for (int i = 0; i < n; i++)
		cin >> rates[i];
	cout << "输入各个估价：" << endl;
	for (int i = 0; i < n; i++)
		cin >> values[i];
	sort(rates,n);
	sort(values,n);
	double** matrix = createMatrix(rates, values, n);
	cout << "GSP:" << endl;
	gsp(matrix, n);
	cout << "VCG:" << endl;
	vcg(matrix, n);
	system("pause");
	return 0;
}