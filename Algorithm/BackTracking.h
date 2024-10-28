#pragma once

#include<iostream>
#include<vector>

using namespace std;

namespace Permutation
{
	// n개의 자료가 주어진다 1 ~ n까지 원소를 이루고 있다
	// 원소의 갯수가 2개일 때만 출력
	// 같은 숫자가 중복이 안되게 하는 것
	int n = 3;
	int m = 2;
	int arr[3];
	bool seen[3];
	vector<int> vec;

	void Print()
	{
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << ' ';
		}
		cout << '\n';
	}

	void BT(int length)
	{
		// 출력 조건 설정
		if (length == m)
		{
			Print();
			return;
		}

		for (int i = 0; i < n; i++)
		{
			if (seen[i])
			{
				continue;	// 이미 vec 데이터를 넣었으면 통과 (가지치기)
			}
			
			seen[i] = true;
			vec.push_back(arr[i]);
			BT(length + 1);
			seen[i] = false;
			vec.pop_back();
		}
	}

	void Case01()
	{
		for (int i = 0; i < n; i++)
		{
			arr[i] = i + 1;
			seen[i] = false;
		}

		BT(0);
	}
}

namespace Combine
{
	int n = 3;
	int m = 2;
	int arr[3];
	bool seen[3];
	vector<int> vec;

	void Print()
	{
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << ' ';
		}
		cout << '\n';
	}

	void BT(int length, int start)
	{
		// 출력 조건 설정
		if (length == m)
		{
			Print();
			return;
		}

		for (int i = start; i < n; i++)
		{
			if (seen[i])
			{
				continue;	// 이미 vec 데이터를 넣었으면 통과 (가지치기)
			}

			seen[i] = true;
			vec.push_back(arr[i]);
			BT(length + 1, i + 1);
			seen[i] = false;
			vec.pop_back();
		}
	}

	void Case02()
	{
		for (int i = 0; i < n; i++)
		{
			arr[i] = i + 1;
			seen[i] = false;
		}

		BT(0, 0);
	}
}

