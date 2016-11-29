#include <iostream>
using namespace std;

void PrintIntArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		cout << arr[i];
	}
	cout << endl;
}

void PowerSet01()
{
	int bit[4];

	int i, j, k, l;

	for (i = 0; i <= 1; i++)
	{
		bit[0] = (i % 2 == 0) ? 0 : 1;

		for (j = 0; j <= 1; j++)
		{
			bit[1] = (j % 2 == 0) ? 0 : 1;

			for (k = 0; k <= 1; k++)
			{
				bit[2] = (k % 2 == 0) ? 0 : 1;

				for (l = 0; l <= 1; l++)
				{
					bit[3] = (l % 2 == 0) ? 0 : 1;

					PrintIntArray(bit, 4);
				}
			}
		}
	}

}

/*
(wik)
 > �̹������ �ϸ� bit�� �����ſ��� ������������ ���ʴ�� ������.
 > 10�� ¥���� for loop 10�� ������ ��.
   (stk) �� ���� ����� ����? => 2���� ������� (bit�� �̿� or  stack�̿�), stack�̿��� stack����~
*/


void PowerSetByBit(int arr[], int size)
{
	int i;
	int j;

	for (i = 0; i < (1 << size); i++)
	{
		for (j = 0; j < size; j++)
		//for (j = size-1; j >=0; j--)
		{
			if (i&(1 << j))
			{
				cout << arr[j];
			}
			else
			{
				cout << "_";
			}
		}
		cout << endl;
	}
}


/*
<��������2>
�κ����� �� ���� �����ϱ�
 > 10���� ������ �Է� �޾�
 > 10���� ���ҷ� ���� �� �ִ� �κ����� �߿�
 > �κ� ������ ���� 0�� �Ǵ� �κ� ������ ����� ���ÿ�
*/

void Process(int arr[], int size)
{
	cout << "���� 10�� �Է��ϼ���" << endl;
	int k;
	for (k = 0; k < 10; k++)
	{
		cin >> arr[k];
	}

	int i, j;
	int sum;
	for (i = 0; i < (1 << size); i++)
	{
		sum = 0;
		for (j = 0; j < size; j++)
		{
			if (i&(1 << j))
			{
				sum = sum + arr[j];
			}
		}

		if (sum == 0)
		{
			for (j = 0; j < size; j++)
			{
				if (i&(1 << j))
				{
					cout << arr[j];
				}
				else
				{
					cout << "_";
				}
			}
			cout << endl;
		}
	}

}

/*
(wik)
 > ��~ ��³��� ���� ��ճ�~
*/







int main(void)
{
	//PowerSet01();


	/*
	int arr[] = { 1, 2, 3, 4 };
	PowerSetByBit(arr, 4);
	*/

	int arr[10];
	Process(arr, 10);

	return 0;
}