#include<iostream>
using namespace std;
int* friends(int** array,int n)
{
	int* result = new int[n];
	for (int i = 0; i < n; i++)
		result[i] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (array[i][j] == 1 && i != j)
				result[i]++;
	return result;
}
int main()
{
	cout << "***输入***" << endl;
	cout << "输入节点数：";
	int n;
	cin >> n;
	int** array = new int* [n];
	for (int i = 0; i < n; i++)
		array[i] = new int[n];
	cout << "输入邻接矩阵：" << endl;
	for (int i = 0; i < n * n; i++)
		cin >> array[i / n][i % n];
	int* result = friends(array, n);
	int up=0;
	for (int i = 0; i < n; i++)
	{
		int yes = 0;
		int average = 0;
		for (int j = 0; j < n; j++)
			if (array[i][j] == 1 && i != j)
			{
				average+=result[j];
				yes++;
			}
		average /= yes;
		if (result[i] < average)
			up++;
	}
	for (int i = 0; i < n; i++)
		cout << "节点" << i << "的朋友数：" << result[i] << endl;
	cout << "符合友谊悖论的节点占比为："<<(double)up / n<<endl;
	return 0;
}