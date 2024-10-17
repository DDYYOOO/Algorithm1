#include "DivideandConquer.h"
#include<iostream>
#include<vector>


// ����
void MergeSort(int list[], int left, int right)
{
	if (left < right)
	{
		int mid = left + right / 2;
		// ���� ����
		MergeSort(list, left, mid);
		// ������ ����
		MergeSort(list, mid + 1, right);
		// Merge
		Merge(list, left, mid, right);
	}

}

// ����, ����
void Merge(int list[], int left, int mid, int right)
{
	int leftidx = left;
	int rightidx = mid + 1;

	std::vector<int> sorted;
	
	// ���� ��Ʈ�� ������ ��Ʈ�� ���ؼ�, ���� ������ ���ĵ� ������ ����
	while (leftidx <= mid && rightidx <= right)
	{
		// ���ʰ� ���ؼ� ������ ���� ��쿡 sorted ���� index ����
		// ���� ���� �ߺ� �Ǹ� ���� �ε����� ���
		if (list[leftidx] <= list[rightidx])
		{
			sorted.push_back(list[leftidx]);
			//sorted[key] = list[leftidx];
			leftidx++;
		}
		else if (list[leftidx] >= list[rightidx])
		{
			sorted.push_back(list[rightidx]);
			//sorted[key] = list[rightidx];
			rightidx++;
		}
	}

	if (rightidx >= left)
	{
		for (int i = leftidx; i <= mid; i++)
		{
			sorted.push_back(list[i]);
		}
	}
	else
	{
		for (int i = rightidx; i <= right; i++)
		{
			sorted.push_back(list[i]);
		}
	}

	// ���ĵ� �����͸� list������ ����
	for (int i = 0; i < sorted.size(); i++)
	{
		list[left + i] = sorted[i];
	}


	// ���� �����Ͱ� ������ ���
	//while (leftidx <= mid)
	//{
	//	sorted[key++] = list[leftidx++];
	//	//for (int i = leftidx; i <= mid; i++)
	//	//{
	//	//	sorted[key] = list[i];
	//	//	key++;
	//	//	leftidx++;
	//	//}
	//}
	//
	//while (rightidx <= right)
	//{
	//	sorted[key++] = list[rightidx++];
	//	//for (int i = rightidx; i <= right; i++)
	//	//{
	//	//	sorted[key] = list[i];
	//	//	key++;
	//	//	rightidx++;
	//	//}
	//}
	//
	//for (int i = 0; i < sorted.size(); i++)
	//{
	//	std::cout << list[i] << std::endl;
	//}

}
