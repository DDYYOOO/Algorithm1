#pragma once
#include<iostream>
#include<vector>

// 20�� ī�尡 ���������ִ�
// ī�带 ��� �ո����� ������ ��츦 ���϶�
// �̹� �ո��� ī��� �ٽ� ���� �� �� ���� (�ߺ����úҰ�)
// ���� ���� Ƚ���� ��� ī�带 �ո����� ������ ����� Ƚ�� ���ϱ�


void Case001(int n)
{
	// 1 ~ n������ 
	std::cout << n * (n + 1) / 2;
}

int QuickSlelect(std::vector<int> nums, int n)
{


	return 0;
}

void Case002()
{
	std::vector<int> vec;
	int s;	// ����
	int n;	// ������
	int x;  // x��° ����

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
	//	// n - 1�� other��ġ�� �ű�
	//	// ���� ū ž�� ��ǥ��ġ�� �ű�
	//	std::cout << cnt << ' ' << target << '\n';
	//	// n- 1 �� other ���� ���� ž -> ��ǥ���� �ű�
	//	hanoi(n - 1, other, cnt, target);
	//
	//}
	//
	//int hanoiCount(int n)
	//{
	//	if (n == 1) return 1;
	//
	//	// n - 1�� �ð� x 2
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

