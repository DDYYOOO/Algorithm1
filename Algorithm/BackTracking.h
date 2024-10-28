#pragma once

#include<iostream>
#include<vector>

using namespace std;

namespace Permutation
{
	// n���� �ڷᰡ �־����� 1 ~ n���� ���Ҹ� �̷�� �ִ�
	// ������ ������ 2���� ���� ���
	// ���� ���ڰ� �ߺ��� �ȵǰ� �ϴ� ��
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
		// ��� ���� ����
		if (length == m)
		{
			Print();
			return;
		}

		for (int i = 0; i < n; i++)
		{
			if (seen[i])
			{
				continue;	// �̹� vec �����͸� �־����� ��� (����ġ��)
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
		// ��� ���� ����
		if (length == m)
		{
			Print();
			return;
		}

		for (int i = start; i < n; i++)
		{
			if (seen[i])
			{
				continue;	// �̹� vec �����͸� �־����� ��� (����ġ��)
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

