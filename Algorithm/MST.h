#pragma once

// �ּ� ���� Ʈ�� (minumum spanning tree)

#include<iostream>
#include<vector>
#include<algorithm>

#define INF 9999

using namespace std;

namespace InputWeight
{
	vector<pair<pair<int, int>, int>> edges;

	void Show()
	{
		edges.push_back({ {1, 2}, 10 });
		edges.push_back({ {1, 3}, 15 });
		edges.push_back({ {2, 3}, 5 });
		edges.push_back({ {2, 4}, 18 });
		edges.push_back({ {3, 4}, 25 });

		for (const auto& edge : edges)
		{
			cout << "Edge : (" << edge.first.first << "," << edge.first.second << "), Weight : " << edge.second << '\n';
		}
		cout << '\n';
	}

	class Edge
	{
	private:
		int node[2]; // node[0] : a, node[1] : b
		int distance;
	public:
		Edge(int node1, int node2, int _distance)
		{
			node[0] = node1;
			node[1] = node2;
			distance = _distance;
		}

		int First_Node() const { return this->node[0]; }
		int Second_Node() const { return this->node[1]; }
		int Get_Distance() const { return this->distance; }

		bool operator < (Edge& edge)
		{
			return this->distance < edge.distance;
		}
	};

	void Show2()
	{
		vector<Edge> edges;

		edges.push_back(Edge(1, 2, 10));
		edges.push_back(Edge(1, 3, 15));
		edges.push_back(Edge(2, 3, 5));
		edges.push_back(Edge(2, 4, 18));
		edges.push_back(Edge(3, 4, 25));

		for (const auto& edge : edges)
		{
			cout << "Edge : (" << edge.First_Node() << "," << edge.Second_Node() << "), Weight : " << edge.Get_Distance() << '\n';
		}
		cout << '\n';

		sort(edges.begin(), edges.end());
		
		for (const auto& edge : edges)
		{
			cout << "Edge : (" << edge.First_Node() << "," << edge.Second_Node() << "), Weight : " << edge.Get_Distance() << '\n';
		}
		cout << '\n';

	}

}

namespace Union_Find
{ 
	// ���� ���μ� ����

	int GetParent(int arr[], int x)	// �׷����� �־����� ��, ��Ʈ(�θ�) ��带 ã�´�
	{
		if (x == arr[x]) { return x; }

		return GetParent(arr, arr[x]);
	}

	void UnionParent(int arr[], int a, int b)		// �ΰ��� �׷����� �ϳ��� ��ģ��
	{
		a = GetParent(arr, a);
		b = GetParent(arr, b);

		if (a < b) 
			arr[b] = a;
		else
			arr[a] = b;

	}

	bool Findparent(int arr[], int a, int b)		// ������ �ƴ��� 
	{
		a = GetParent(arr, a);
		b = GetParent(arr, b);

		if (a == b)
			return true;
		else
			return false;

		return true;
	}
}

namespace InputGraph
{
	// �׷��� �ڵ� ���� ���
	
	void GraphShow()
	{
		int size = 7;
		
		int graph[7][7] = 
		{
			{  0,   67, INF,  28,  17, INF,  12},
			{  67,   0, INF,  24,  62, INF, INF},
			{ INF, INF, 0,   INF,  20,  37, INF},
			{  28,  24, INF,   0, INF, INF,  13},
			{  17,  62, 20,  INF,   0,  45,  73},	
			{ INF, INF, 37,  INF,  45,   0, INF},	
			{  12, INF, INF,  13,  73, INF,   0}
		};

		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				cout << graph[i][j] << ' ';
			}
			cout << '\n';
		}
	}
}
