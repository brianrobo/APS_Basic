#include <iostream>
using namespace std;


int SequencialSearch(int arr[], int size, int key) //me first
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (arr[i] == key)
			return i;
	}

	return -1;
}

int SequencialSearchTeach(int arr[], int size, int key)
{
	int i=0;
	while (i < size)
	{
		if (arr[i] == key)
			return i;

		i++;
	}

	return -1;
}

int SequencialSearchTeachOrdered(int arr[], int size, int key)
{
	int i = 0;
	//while ( (i < size) && (arr[i] < key) )
	while (arr[i] < key) // <-- (me) 0~size만큼 할 필요없이, key값보다 작은 동안만하면됨.
	{
		if (arr[i] == key)
			return i;

		i++;
	}

	return -1;
}


/*
  (stk_01)  startIdx, endIdx, midIndex는 how?
        (spe1)  [0  1  2  3]  <-- In case that 0 base index
		        {0, 1, 2, 3}

				mid = end - start /2

*/

int BinarySearch(int arr[], int start, int end, int key) //me first
{
	if (start == end)
	{
		if (arr[start] == key)
		{
			return start;
		}
		else
		{
			return -1;
		}
	}

	//int mid = end - start / 2; //(stk_02) midIndex는 (start + end) / 2 해야하네.
	int mid = (start + end) / 2;

	if (arr[mid] == key)
	{
		return mid;
	}
	else if(arr[mid] < key)
	{
		int tempStart = mid + 1;
		return BinarySearch(arr, tempStart, end, key);
	}
	else
	{
		int tempEnd = mid - 1;
		return BinarySearch(arr, start, tempEnd, key);
	}
}

int BinarySearchTeach(int arr[], int size, int key) //by teach
{
	int start = 0; 	
	//int end = (sizeof(arr) / sizeof(arr[0])) - 1; //(stk03) function parameter array pointer can't use to check array size.. it's pointer..
	int end = size - 1;

	while (start <= end)
	{
		int mid = (start + end) / 2;

		if (arr[mid] == key)
		{
			return mid;
		}
		else if (arr[mid] < key)
		{
			start = mid + 1;
		}
		else // arr[mid] > key
		{
			end = mid - 1;
		}
	}

	return -1;
}


int main(void)
{

	//int arr[] = { 11, 24, 1, 2, 26, 3, 7, 9 };
	int arr[] = { 1, 2, 3, 7, 9, 11, 24, 26 };
	int findIdx;
	int key = 25;
	//findIdx = BinarySearch(arr, 0, 7, key);

	int size = sizeof(arr) / sizeof(arr[0]);
	findIdx = BinarySearchTeach(arr, size, key);

	cout << "find index = " << findIdx << endl;


	return 0;
}