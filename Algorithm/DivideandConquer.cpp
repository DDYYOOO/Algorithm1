#include "DivideandConquer.h"
#include<iostream>
#include<vector>


// 분할
void MergeSort(int list[], int left, int right)
{
	if (left < right)
	{
		int mid = left + right / 2;
		// 왼쪽 정렬
		MergeSort(list, left, mid);
		// 오른쪽 정렬
		MergeSort(list, mid + 1, right);
		// Merge
		Merge(list, left, mid, right);
	}

}

// 정복, 조합
void Merge(int list[], int left, int mid, int right)
{
	int leftidx = left;
	int rightidx = mid + 1;

	std::vector<int> sorted;
	
	// 왼쪽 파트와 오른쪽 파트를 비교해서, 작은 수부터 정렬된 공간에 저장
	while (leftidx <= mid && rightidx <= right)
	{
		// 왼쪽과 비교해서 왼쪽이 작은 경우에 sorted 현재 index 저장
		// 만약 수가 중복 되면 왼쪽 인덱스에 출력
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

	// 정렬된 데이터를 list값으로 전달
	for (int i = 0; i < sorted.size(); i++)
	{
		list[left + i] = sorted[i];
	}


	// 남은 데이터가 있으면 출력
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
