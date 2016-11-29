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
 > 이방식으로 하면 bit가 낮은거에서 높은차순으로 차례대로 찍힌다.
 > 10개 짜리는 for loop 10번 돌리면 됨.
   (stk) 더 좋은 방법은 없나? => 2가지 방법있음 (bit열 이용 or  stack이용), stack이용은 stack가서~
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
<연습문제2>
부분집합 합 문제 구현하기
 > 10개의 정수를 입력 받아
 > 10개의 원소로 만들 수 있는 부분집합 중에
 > 부분 집합의 합이 0이 되는 부분 집합을 출력해 보시오
*/

void Process(int arr[], int size)
{
	cout << "정수 10개 입력하세요" << endl;
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
 > 오~ 출력내용 보니 재밌네~
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