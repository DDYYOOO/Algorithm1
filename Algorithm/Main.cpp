#include<iostream>
#include"Sort.h"
#include"InputReference.h"
#include"Pow.h"
#include"DivideandConquer.h"

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

}