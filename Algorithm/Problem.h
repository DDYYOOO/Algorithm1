#pragma once
#include<iostream>
#include<vector>

// 20개 카드가 뒤집어져있다
// 카드를 모두 앞면으로 뒤집는 경우를 구하라
// 이미 앞면인 카든느 다시 뒤집 을 수 없다 (중복선택불가)
// 가장 많은 횟수로 모든 카드를 앞면으로 돌리는 경우의 횟수 구하기


void Case001(int n)
{
	// 1 ~ n번까지 
	std::cout << n * (n + 1) / 2;
}

int QuickSlelect(std::vector<int> nums, int n)
{


	return 0;
}

void Case002()
{
	std::vector<int> vec;
	int s;	// 점수
	int n;	// 응시자
	int x;  // x번째 숫자

	std::cin >> n;
	std::cin >> x;

	for (int i = 0; i < n; i++)
	{
		std::cin >> s;
		vec.push_back(s);
	}

	for (int num : vec)
	{
		std::cout << num << " ";
	}

}

void Case003()
{
	//void hanoi(int n, int cnt, int other, int target)
	//{
	//	if(n == 1)
	//		cout << cnt << ' ' << target << '\n';
	//
	//	hanoi(n - 1, cnt, target, other);
	//	// n - 1츨 other위치게 옮김
	//	// 가장 큰 탑을 목표위치게 옮김
	//	std::cout << cnt << ' ' << target << '\n';
	//	// n- 1 층 other 시작 점인 탑 -> 목표지점 옮김
	//	hanoi(n - 1, other, cnt, target);
	//
	//}
	//
	//int hanoiCount(int n)
	//{
	//	if (n == 1) return 1;
	//
	//	// n - 1층 시간 x 2
	//	return 2 = hanoiCount(n - 1) + 1;
	//}
	//
	//int Main()
	//{
	//	int n;
	//	std::cin >> n;
	//
	//	std::cout << hanoiCount(n);
	//
	//	hanoi(n, 1, 2, 3);
	//}
}

