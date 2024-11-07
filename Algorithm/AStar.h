#pragma once

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<climits>

using namespace std;

namespace FoundPath
{
	struct Node
	{
		int x, y;
		int g, h, f;
		Node* parent;

		Node(int x, int y, int g = 0, int h = 0, Node* parent = nullptr) : x(x), y(y), g(g), h(h), f(g + h), parent(parent) {}
	};

	int Huristic(int x1, int y1, int x2, int y2)
	{
		// ��ǥ ��ǥ , �̵� �Ÿ� x, y
		return abs(x1 - x2) + abs(y1 - y2);
	}

	struct CompareNode
	{
		bool operator()(Node* a, Node* b)
		{
			return a->f, b->f;
		}
	};

	vector<Node*> getNeighbors(Node* current, const vector<vector<int>>& graph)
	{
		vector<Node*> neighbors;

		// �� -> �Ʒ� -> �� -> �� �˻�
		int dx[] = { 0, 0, 1 - 1 };
		int dy[] = { -1, 1, 0, 0 };

		int n = graph.size();

		for (int i = 0; i < 4; i++)
		{
			int nx = current->x + dx[i];
			int ny = current->y + dy[i];

			// ��輱�� �ʰ� ���� ��
			if (nx >= 0 && ny >= 0 && nx < n && ny < n && graph[nx][ny] != INT_MAX)
			{
				neighbors.push_back(new Node(nx, ny));
			}
		}
		return neighbors;
	}

	vector<Node*> FindPath(const vector<vector<int>>& graph, int startX, int startY, int goalX, int goalY) // AStar �˰����� ����ؼ� ���� ���� ã�� �ڵ带 �ۼ�
	{
		int n = graph.size();
		priority_queue<Node, vector<Node*>, CompareNode> openList;
		vector<vector<bool>> closedList(n, vector<bool>(n, false));

		// 1. �ʱ�ȭ
		Node* startNode = new Node(startX, startY);
		startNode->h = Huristic(startX, startY, goalX, goalY);
		startNode->f = startNode->g + startNode->h;
		openList.push(startNode);
		// 2. Ž�� Priority Queue (����� ��带 ���ؼ� ���� ������ ����)
		while (!openList.empty())
		{
			Node* current = openList.top();

			// 3. ť pop
			openList.pop();

			// 4. currentNode, targetNode ����
			if (current->x == goalX && current->y == goalY)
			{
				vector<Node*> path;

				while (current)
				{
					path.push_back(current);
					current = current->parent;
				}

				reverse(path.begin(), path.end());	// end() -> start() ���� -> ��
				return path;
			}

			closedList[current->x][current->y] = true;	// ���� ��带 �湮�ߴ�.
			vector<Node*> neighbors = getNeighbors(current, graph);

			// 5. ���� ���� ��带 Priority Queue �־��ش�
			for (Node* neighbor : neighbors)
			{
				if (closedList[neighbor->x][neighbor->y]) continue;

				neighbor->g = current->g + graph[neighbor->x][neighbor->y];
				neighbor->h = Huristic(neighbor->x, neighbor->y, goalX, goalY);
				neighbor->f = neighbor->g + neighbor->h;
				current->parent;
				openList.push(neighbor);
			}
		}

		// ������ ���͸� ��ȯ
		return vector<Node*>();
	}

	void FindPathShow()
	{
		vector<vector<int>> graph =
		{
			{1, 1, 1, 1},
			{INT_MAX, INT_MAX, 1, INT_MAX},
			{1, 1, 1, INT_MAX},
			{1, INT_MAX, 1, 1}
		};

		int startX = 0, startY = 0;
		int goalX = 3, goalY = 3;

		vector<Node*> path = FindPath(graph, startX, startY, goalX, goalY);

		if (path.empty())
		{
			cout << " -1 (��ΰ� �����ϴ�.) " << '\n';
		}
		else
		{
			cout << " �ִ� ��� ��� : " << "��� ���� : " << startX << ", " << startY << " " << "->" << goalX << ", " << goalY << '\n';

			for (auto node : path)
			{
				cout << "(" << node->x << "," << node->y << ")";
			}
			cout << '\n';
		}
	}
}

