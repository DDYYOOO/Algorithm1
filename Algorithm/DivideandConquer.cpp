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

// search largest k`th number : k번째로 큰 숫자를 찾는 방법

int QuickSelect(std::vector<int>& nums, int k)
{
	// 사이즈가 1일 경우 nums[0] 값을 리턴
	int length = nums.size();
	if (length == 1) return nums[0];

	// 랜덤한 숫자를 선택해서 그 숫자를 기준으로 잡는다. 
	// 피벗에 해당하는 숫자를 제일 마지막으로 옮긴다.
	int pivotindex = rand() % length;
	int lastindex = length - 1;
	std::swap(nums[pivotindex], nums[lastindex]);

	// 왼쪽은 항상 피벗보다 작고, 오른쪽은 항상 피벗보다 크다
	int leftidx = 0;
	int rightidx = length - 2;	// lastindex - 1
	int pivot = nums[lastindex];

	while (leftidx <= rightidx)
	{
		if (nums[leftidx] <= pivot)	// 비교해서 피벗보다 작거난 같은 수 idx 변경
		{
			leftidx++;
			continue;
		}
		
		if (pivot < nums[rightidx])	// 오른쪽 수가 피벗보다 크면 idx 잘못된 것을 찾을 때까지 변경
		{
			rightidx--;
			continue;
		}

		std::swap(nums[leftidx], nums[rightidx]);	// left(피벗 기준 큰 수), right(피벗 기준 작은 수) 교환
	}

	// nums leftidx와 lastindex 변경
	std::swap(nums[leftidx], nums[lastindex]);

	if (leftidx == length - k)
	{
		return nums[leftidx];
	}
	else if(leftidx < length - k)	// 피벗을 위치가 찾는 위치보다 작은 경우(오른쪽 범위 검색)
	{
		std::vector<int> rightPart(nums.begin() + leftidx + 1, nums.end());
		QuickSelect(rightPart, k);
	}
	else if (leftidx > length - k)	// 피벗을 위치가 찾는 위치보다 큰 경우(왼쪽 범위 검색)
	{
		std::vector<int> leftPart(nums.begin(), nums.begin() + leftidx);
		QuickSelect(leftPart, k - (length - leftidx));
	}

	// k번째 인덱스의 그 수를 return
	return 0;

}

void QuickSort(std::vector<int>& nums, int begin, int end)
{
	// 사이즈가 1일 경우 nums[0] 값을 리턴
	int length = end - begin + 1;
	if (length <= 1) return;

	// 랜덤한 숫자를 선택해서 그 숫자를 기준으로 잡는다. 
	// 피벗에 해당하는 숫자를 제일 마지막으로 옮긴다.
	int pivotindex = rand() % length;
	int lastindex = length - 1;
	std::swap(nums[pivotindex], nums[lastindex]);

	// 왼쪽은 항상 피벗보다 작고, 오른쪽은 항상 피벗보다 크다
	int leftidx = 0;
	int rightidx = length - 2;	// lastindex - 1
	int pivot = nums[lastindex];

	while (leftidx <= rightidx)
	{
		if (nums[leftidx] <= pivot)	// 비교해서 피벗보다 작거난 같은 수 idx 변경
		{
			leftidx++;
			continue;
		}

		if (pivot < nums[rightidx])	// 오른쪽 수가 피벗보다 크면 idx 잘못된 것을 찾을 때까지 변경
		{
			rightidx--;
			continue;
		}

		std::swap(nums[leftidx], nums[rightidx]);	// left(피벗 기준 큰 수), right(피벗 기준 작은 수) 교환
	}

	// nums leftidx와 lastindex 변경
	std::swap(nums[leftidx], nums[lastindex]);
	// 피벗 선택 -> 좌, 우나눈다
	QuickSort(nums, leftidx + 1, lastindex);
	QuickSort(nums, begin, leftidx - 1);

}
