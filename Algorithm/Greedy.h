#pragma once
#include<iostream>
#include <vector>


// 거스름돈 문제
// n원을 5원과 2원으로 거슬러준다.
// 5원으로 거슬러 준 후, 남은 돈을 2원으로 거슬러주고, 만약에 잔돈이 남으면 -1, 잔돈의 총 수를 출력

int CountRemainCoin(int n)
{
	// 거슬러 줄 동전의 갯수
	int money = n;

	// 5원이 최대가 아닌 경우에는 무조건 false
	// 13원 케이스 return 해주기 위해서, 5원 짜리를 기준으로 거술러 줄 수 있는 케이스를 검산
	for (int i = 0; i * 5 <= n; i++)
	{
		int remain = n - i * 5;

		if (remain % 2 == 0)
		{
			int totalCoins = i + remain / 2;
			money = std::min(money, totalCoins);
		}
	}

	return money == n ? -1 : money;

	// 예외 상황 13원 일 때 이 코드는 사용 불가
	//int coin5 = money / 5;
	//int remain = money % 5;
	//int coin2 = remain / 2;
	//
	//if (coin2 % 2 != 0)
	//{
	//	return -1;
	//}
	//else
	//{
	//	return coin5 + coin2;
	//}

}

// 문제 번호 14916 거스름돈 문제
void Case01()
{
 
}

// 
void case02()
{

}


// 문제 번호 11399 ATM 문제
void case03()
{

}
