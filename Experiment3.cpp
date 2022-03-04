#include<iostream>
using namespace std;
int** initialize(int n,int type)
{
	int** array = new int* [n];
	for (int i = 0; i < n; i++)
		array[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			array[i][j] = rand()%(type+1);
	return array;
}
bool move(int** array, int n, int i, int j)
{
	int same = 0;
	if (i - 1 >= 0 && j - 1 >= 0 && array[i - 1][j - 1] == array[i][j])
		same++;
	if (i - 1 >= 0 && array[i - 1][j] == array[i][j])
		same++;
	if (i - 1 >= 0 && j + 1 < n && array[i - 1][j + 1] == array[i][j])
		same++;
	if (j - 1 >= 0 && array[i][j - 1] == array[i][j])
		same++;
	if (j + 1 < n && array[i][j + 1] == array[i][j])
		same++;
	if (i + 1 < n && j - 1 >= 0 && array[i + 1][j - 1] == array[i][j])
		same++;
	if (i + 1 < n && array[i + 1][j] == array[i][j])
		same++;
	if (i + 1 < n && j + 1 < n && array[i + 1][j + 1] == array[i][j])
		same++;
	return same < 3;
}
void option(int** array, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (array[i][j] != 0 && move(array, n, i, j))
			{
				int newI,newJ;
				do
				{
					newI = rand() % n;
					newJ = rand() % n;
				} while (array[newI][newJ] != 0||(i==newI&&j==newJ));
				array[newI][newJ] = array[i][j];
				array[i][j] = 0;
			}
}
void display(int** array,int n)
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
int main()
{
	int n,times,type;
	cout << "输入方阵大小：";
	cin >> n;
	cout << "输入种族个数：";
	cin >> type;
	cout << "输入迭代次数：";
	cin >> times;
	system("cls");
	int** array=initialize(n,type);
	cout << "0次操作后：" << endl;
	display(array, n);
	system("pause");
	for (int i = 1; i <= times; i++)
	{
		option(array, n);
		system("cls");
		cout << i<<"次操作后：" << endl;
		display(array, n);
		system("pause");
	}
	return 0;
 }