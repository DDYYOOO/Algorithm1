#include "Sort.h"
#include<algorithm>
#include<iostream>

void BubbleSort(int list[], int n)
{
	// i번 반복
	for (int i = n - 1; i > 0; i--)		// n사이클 진행, 전체의 -1
	{
		// j번 비교 반복
		for (int j = 0; j < i; j++)			// i 사이클 수만큼 반복
		{
			if (list[j] > list[j + 1])
				std::swap(list[j], list[j + 1]);
		}
	}
}

void BubbleSort2(int list[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)			
		{
			if (list[j] > list[j + 1])
				std::swap(list[j], list[j + 1]);
		}
	}
}

void BubbleExample()
{
	int list[] = { 7, 5, 3, 6, 9 };

	//BubbleSort(list, 5);
	BubbleSort2(list, 5);

	for (int i = 0; i < 5; i++)
	{
		std::cout << list[i] << " ";
	}
 }

void SelectionSort(int list[], int n)
{
	int least = 0;

	for (int i = 0; i < n; i++)
	{
		least = i;

		for (int j = i + 1; j < n; j++)
		{
			if (list[j] < list[least])
			{
				least = j;
			}
		}

		if (least != i)
		{
			std::swap(list[i], list[least]);
		}
	}
	


}

void SelectionExample()
{
	int list[] = { 7, 5, 3, 6, 9 };

	SelectionSort(list, 5);

	for (int i = 0; i < 5; i++)
	{
		std::cout << list[i] << " ";
	}
}

void InsertionSort(int list[], int n)
{
	int j = 0;
	for (int i = 0; i < n - 1; i++)
	{
		j = i;
		while (list[j] > list[j + 1] && j >= 0)
		{
			std::swap(list[j], list[j + 1]);
			j--;
		}
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << list[i] << " ";
	}
}

void InsertionSortExample()
{
	int list[] = { 1, 5, 10, 4, 7, 6, 3};

	InsertionSort(list, 7);
}

void CountSort()
{
	int arr[15] = {3, 0, 4, 0, 2,
				  1, 2, 3, 4, 4,
				  2, 3, 1, 0, 2};

	int count[5];

	for (int i = 0; i < 5; i++)
	{
		count[i] = 0;
	}

	for (int i = 0; i < 15; i++)
	{
		count[arr[i]]++;
	}

	for (int i = 0; i < 5; i++)
	{
		if (count[i] != 0)
		{
			for (int j = 0; j < count[i]; j++)
			{
				std::cout << i + 1 << " ";
			}
		}
	}
}

void CountSortExample()
{

}
