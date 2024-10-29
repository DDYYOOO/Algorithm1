#pragma once

#include<iostream>
#include<vector>

using namespace std;

namespace Virus
{
	int n, m;	// n - ��ǻ�� ��, m - ��ǻ�Ϳ� �̾��� �ִ� ���� ��
	int num;
	int count = 0;

	vector<vector<int>> graph(101);
	bool visited[101] = { false };

	void DFS(int node)	// ���� ����� ��ǻ��(vertex)
	{
		for (int i = 0; i < graph[node].size(); i++)
		{
			int current = graph[node][i];

			if (visited[current]) continue;

			visited[current] = true;
			count++;
			
			DFS(current);
		}
	}

	void Case1()
	{
		cin >> n >> m;

		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;	// ����

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		// ��ǻ�� 1 ����
		visited[1] = true;

		DFS(1);

		cout << count << '\n';

	}
}