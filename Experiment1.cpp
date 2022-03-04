#include<iostream>
using namespace std;
void printArray(int** array,int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << array[i][j];
			if (j != n - 1)
				cout << " ";
		}
		cout << endl;
	}
}
double cluster(int** array,int n,int index)//单个节点的聚集系数
{
	int down=0 , up=0;
	for (int i = 0; i < n; i++)
		if (array[i][index] == 1)
		{
			down++;
			for (int j = i; j < n; j++)
				if (array[j][i] == 1 && array[j][index] == 1)
					up++;
		}
	down = down * (down - 1) / 2;
	return (double)up/down;
}
double* clusterArray(int** array,int n)//计算并返回聚集系数矩阵
{
	double* result = new double [n];
	for (int i = 0; i < n; i++)
		result[i] = cluster(array,n,i);
	return result;
}
double overlap(int** array, int n, int i, int j)
{
	int up = 0;
	for (int k = 0; k < n; k++)
		if (k != i && k != j && array[k][j] == 1 || array[i][k] == 1)
			up++;
	return (double)up/n;
}
int main()
{
	cout << "***输入***" << endl;
	cout << "输入节点数：";
	int n;
	cin >> n;
	int** array = new int*[n];
	for (int i = 0; i < n; i++)
		array[i] = new int[n];
	cout << "输入邻接矩阵：" << endl;
	for (int i = 0; i < n * n; i++)
		cin >> array[i / n][i % n];
	double* array2 = clusterArray(array, n);
	cout << "***聚集系数的计算***" << endl;
	for (int i = 0; i < n; i++)
		cout << "节点" << i << "的聚集系数为：" << array2[i] << endl;
	cout << "***邻里重叠度的计算***" << endl;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			cout << "节点" << i << "和节点" << j << "的邻里重叠度：" << overlap(array, n, i, j) << endl;
	return 0;
}