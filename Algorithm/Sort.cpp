#include "Sort.h"
#include<algorithm>
#include<iostream>

void BubbleSort(int list[], int n)
{
	// i�� �ݺ�
	for (int i = n - 1; i > 0; i--)		// n����Ŭ ����, ��ü�� -1
	{
		// j�� �� �ݺ�
		for (int j = 0; j < i; j++)			// i ����Ŭ ����ŭ �ݺ�
		{
			if (list[j] > list[j + 1])
				std::swap(list[j], list[j + 1]);
		}
	}

	// for(int i = 1; i < n; i++)	���� ���� ����
	

}

void BubbleExample()
{
	int list[] = { 7, 5, 3, 6, 9 };

	BubbleSort(list, 5);

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