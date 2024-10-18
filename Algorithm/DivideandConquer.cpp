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

// search largest k`th number : k��°�� ū ���ڸ� ã�� ���

int QuickSelect(std::vector<int>& nums, int k)
{
	// ����� 1�� ��� nums[0] ���� ����
	int length = nums.size();
	if (length == 1) return nums[0];

	// ������ ���ڸ� �����ؼ� �� ���ڸ� �������� ��´�. 
	// �ǹ��� �ش��ϴ� ���ڸ� ���� ���������� �ű��.
	int pivotindex = rand() % length;
	int lastindex = length - 1;
	std::swap(nums[pivotindex], nums[lastindex]);

	// ������ �׻� �ǹ����� �۰�, �������� �׻� �ǹ����� ũ��
	int leftidx = 0;
	int rightidx = length - 2;	// lastindex - 1
	int pivot = nums[lastindex];

	while (leftidx <= rightidx)
	{
		if (nums[leftidx] <= pivot)	// ���ؼ� �ǹ����� �۰ų� ���� �� idx ����
		{
			leftidx++;
			continue;
		}
		
		if (pivot < nums[rightidx])	// ������ ���� �ǹ����� ũ�� idx �߸��� ���� ã�� ������ ����
		{
			rightidx--;
			continue;
		}

		std::swap(nums[leftidx], nums[rightidx]);	// left(�ǹ� ���� ū ��), right(�ǹ� ���� ���� ��) ��ȯ
	}

	// nums leftidx�� lastindex ����
	std::swap(nums[leftidx], nums[lastindex]);

	if (leftidx == length - k)
	{
		return nums[leftidx];
	}
	else if(leftidx < length - k)	// �ǹ��� ��ġ�� ã�� ��ġ���� ���� ���(������ ���� �˻�)
	{
		std::vector<int> rightPart(nums.begin() + leftidx + 1, nums.end());
		QuickSelect(rightPart, k);
	}
	else if (leftidx > length - k)	// �ǹ��� ��ġ�� ã�� ��ġ���� ū ���(���� ���� �˻�)
	{
		std::vector<int> leftPart(nums.begin(), nums.begin() + leftidx);
		QuickSelect(leftPart, k - (length - leftidx));
	}

	// k��° �ε����� �� ���� return
	return 0;

}

void QuickSort(std::vector<int>& nums, int begin, int end)
{
	// ����� 1�� ��� nums[0] ���� ����
	int length = end - begin + 1;
	if (length <= 1) return;

	// ������ ���ڸ� �����ؼ� �� ���ڸ� �������� ��´�. 
	// �ǹ��� �ش��ϴ� ���ڸ� ���� ���������� �ű��.
	int pivotindex = rand() % length;
	int lastindex = length - 1;
	std::swap(nums[pivotindex], nums[lastindex]);

	// ������ �׻� �ǹ����� �۰�, �������� �׻� �ǹ����� ũ��
	int leftidx = 0;
	int rightidx = length - 2;	// lastindex - 1
	int pivot = nums[lastindex];

	while (leftidx <= rightidx)
	{
		if (nums[leftidx] <= pivot)	// ���ؼ� �ǹ����� �۰ų� ���� �� idx ����
		{
			leftidx++;
			continue;
		}

		if (pivot < nums[rightidx])	// ������ ���� �ǹ����� ũ�� idx �߸��� ���� ã�� ������ ����
		{
			rightidx--;
			continue;
		}

		std::swap(nums[leftidx], nums[rightidx]);	// left(�ǹ� ���� ū ��), right(�ǹ� ���� ���� ��) ��ȯ
	}

	// nums leftidx�� lastindex ����
	std::swap(nums[leftidx], nums[lastindex]);
	// �ǹ� ���� -> ��, �쳪����
	QuickSort(nums, leftidx + 1, lastindex);
	QuickSort(nums, begin, leftidx - 1);

}
