#pragma once

#include<iostream>
#include<vector>

using namespace std;

namespace Virus
{
	int n, m;	// n - 컴퓨터 수, m - 컴퓨터와 이어져 있는 선의 수
	int num;
	int count = 0;

	vector<vector<int>> graph(101);
	bool visited[101] = { false };

	void DFS(int node)	// 현재 연결된 컴퓨터(vertex)
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
			cin >> a >> b;	// 정점

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		// 컴퓨터 1 감염
		visited[1] = true;

		DFS(1);

		cout << count << '\n';

	}
}