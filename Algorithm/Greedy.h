#pragma once
#include<iostream>
#include <vector>


// �Ž����� ����
// n���� 5���� 2������ �Ž����ش�.
// 5������ �Ž��� �� ��, ���� ���� 2������ �Ž����ְ�, ���࿡ �ܵ��� ������ -1, �ܵ��� �� ���� ���

int CountRemainCoin(int n)
{
	// �Ž��� �� ������ ����
	int money = n;

	// 5���� �ִ밡 �ƴ� ��쿡�� ������ false
	// 13�� ���̽� return ���ֱ� ���ؼ�, 5�� ¥���� �������� �ż��� �� �� �ִ� ���̽��� �˻�
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

	// ���� ��Ȳ 13�� �� �� �� �ڵ�� ��� �Ұ�
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

// ���� ��ȣ 14916 �Ž����� ����
void Case01()
{
 
}

// 
void case02()
{

}


// ���� ��ȣ 11399 ATM ����
void case03()
{

}
