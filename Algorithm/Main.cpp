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
	std::cout << "A의 제곱 수 구하기" << std::endl;
	std::cout << Pow(3, 5) << std::endl;
	
	std::cout << "병합 정렬" << std::endl;
	
	int list[8] = { 7, 6, 5, 8, 3, 5, 9, 1 };
	
	MergeSort(list, 0, 7);
	
	for (int i = 0; i < 8; i++)
	{
		std::cout << list[i] << " ";
	}
	
	std::cout << "퀵 선택" << std::endl;
	
	srand(time(0));
	
	std::vector<int> someVec = { 10, 5, 8, 2, 7, 4 };
	
	std::cout << QuickSelect(someVec, 2) << std::endl;
	
	std::cout << "퀵 정렬" << std::endl;
	
	QuickSort(someVec, 0, someVec.size() - 1);
	
	for (int num : someVec)
	{
		std::cout << num << " ";
	}

	std::cout << std::endl;

	//Case002();

	system("cls");

	std::cout << "피보나치 수열(재귀 방식)" << std::endl;

	int count = 40;

	std::cout << "피보나치 수 결과 : " << Fibonacci(count) << std::endl;
	std::cout << "피보나치 수 시간 : " << measureExecutionTime(Fibonacci, count) << "ms" << std::endl;

	std::cout << "피보나치 수열(동적 계획법)" << std::endl;

	std::cout << "피보나치 수 결과 : " << Fibonacci(count) << std::endl;
	std::cout << "피보나치 수 시간 : " << measureExecutionTime(Fibonacci_DP, count) << "ms" << std::endl;
}