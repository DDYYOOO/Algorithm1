#include<iostream>
#include<algorithm>
#include"TimeChecker.h"
#include"Sort.h"
#include"InputReference.h"
#include"Pow.h"
#include"DivideandConquer.h"
#include"Problem.h"
#include"DynamicPrograming.h"

int main()
{
	std::cout << "ad" << std::endl;

	BubbleExample();
	std::cout << std::endl;
	SelectionExample();
	std::cout << std::endl;
	InsertionSortExample();
	std::cout << std::endl;
	CountSort();
	std::cout << std::endl;
	InputExample();
	std::cout << std::endl;
	std::cout << "A�� ���� �� ���ϱ�" << std::endl;
	std::cout << Pow(3, 5) << std::endl;
	
	std::cout << "���� ����" << std::endl;
	
	int list[8] = { 7, 6, 5, 8, 3, 5, 9, 1 };
	
	MergeSort(list, 0, 7);
	
	for (int i = 0; i < 8; i++)
	{
		std::cout << list[i] << " ";
	}
	
	std::cout << "�� ����" << std::endl;
	
	srand(time(0));
	
	std::vector<int> someVec = { 10, 5, 8, 2, 7, 4 };
	
	std::cout << QuickSelect(someVec, 2) << std::endl;
	
	std::cout << "�� ����" << std::endl;
	
	QuickSort(someVec, 0, someVec.size() - 1);
	
	for (int num : someVec)
	{
		std::cout << num << " ";
	}

	std::cout << std::endl;

	//Case002();

	system("cls");

	std::cout << "�Ǻ���ġ ����(��� ���)" << std::endl;

	int count = 40;

	std::cout << "�Ǻ���ġ �� ��� : " << Fibonacci(count) << std::endl;
	std::cout << "�Ǻ���ġ �� �ð� : " << measureExecutionTime(Fibonacci, count) << "ms" << std::endl;

	std::cout << "�Ǻ���ġ ����(���� ��ȹ��)" << std::endl;

	std::cout << "�Ǻ���ġ �� ��� : " << Fibonacci(count) << std::endl;
	std::cout << "�Ǻ���ġ �� �ð� : " << measureExecutionTime(Fibonacci_DP, count) << "ms" << std::endl;
}