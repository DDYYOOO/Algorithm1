#pragma once

#include<iostream>
#include<vector>
#include<algorithm>

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

namespace GraphVec
{
	// n 세로갯수, m 가로갯수
	int n, m;

	vector<vector<int>> graph;

	void Print()
	{
		n = 6, m = 4;

		graph = vector<vector<int>>(n);

		for (int i = 0; i < m; i++)	// i가 선의 갯수만큼 입력값을 받아온다
		{
			int a, b;
			cin >> a >> b;

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		// 정렬
		for (int i = 0; i < n; i++)
		{
			sort(graph[i].begin(), graph[i].end());
		}

		// 출력
		for (int i = 0; i < n; i++)
		{
			cout << "[" << i << "] : ";

			for (int j = 0; j < m; j++)
			{
				// graph[i]. 연결된 데이터가 없을 때 접근 할 방법
				if (j < graph[i].size())
				{
					cout << graph[i][j] << ' ';
				}
				else
				{
					cout << "0";	// 0공백 숫자 1부터 시작
				}
			}
			cout << '\n';
		}
	}
}
