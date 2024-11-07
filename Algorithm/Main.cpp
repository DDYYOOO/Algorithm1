#include<iostream>
#include<algorithm>
#include"TimeChecker.h"
#include"Sort.h"
#include"InputReference.h"
#include"Pow.h"
#include"DivideandConquer.h"
#include"Problem.h"
#include"DynamicPrograming.h"
#include"BackTracking.h"
#include"Array2D(two dimension).h"
#include"Graph.h"
#include"MST.h"
//#include"AStar.h"
#include"AStar(solve).h"
#include"Regular Expression.h"


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
	
	system("cls");
	
	std::cout << "피보나치 수열(재귀 방식)" << std::endl;
	
	int count = 10;
	
	std::cout << "피보나치 수 결과 : " << Fibonacci(count) << std::endl;
	std::cout << "피보나치 수 시간 : " << measureExecutionTime(Fibonacci, count) << "ms" << std::endl;
	
	std::cout << "피보나치 수열(동적 계획법)" << std::endl;
	
	std::cout << "피보나치 수 결과 : " << Fibonacci(count) << std::endl;
	std::cout << "피보나치 수 시간 : " << measureExecutionTime(Fibonacci_DP, count) << "ms" << std::endl;
	
	std::cout << "계단 오르기 문제(메모이제이션)" << std::endl;
	
	std::vector<int> stairs = { 10, 20, 15, 25, 10, 20 };
	
	std::cout << "계단 수가 " << stairs.size() << "인 최대의 수 : " << StairCount(stairs);
	std::cout << std::endl;

	std::cout << "순열" << std::endl;
	Permutation::Case01();

	std::cout << "조합" << std::endl;
	Combine::Case02();

	system("cls");

	//Board::Case1();

	//Board::Case2();

	//Board::Case3();

	//Virus::Case1();

	//GraphVec::Print();

	//InputGraph::Show();

	//InputWeight::Show();

	//InputWeight::Show2();

	//InputGraph::GraphShow();

	//FoundPath::FindPathShow();

	FoundPath2::GetBoard();

	Express();
}