#include <iostream>
#include <vector>
#include <climits>

#define NUM_NODE 6
#define INT_MAX 2147483647

void floydWarshall(int graph[NUM_NODE][NUM_NODE]) {
    int dist[NUM_NODE][NUM_NODE];

    // Initialize the distance array with the given graph values
    for (int i = 0; i < NUM_NODE; ++i) {
        for (int j = 0; j < NUM_NODE; ++j) {
            dist[i][j] = graph[i][j];
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < NUM_NODE; ++k) {
        for (int i = 0; i < NUM_NODE; ++i) {
            for (int j = 0; j < NUM_NODE; ++j) {
                // 
                if ( dist[i][k] != INT_MAX &&  // ����1. k�� ��ġ�� ���� ����Ǿ� �ְ�
                     dist[k][j] != INT_MAX &&  // ����2. k�� ���� �������� ���±��� ����Ǿ� ������
                    dist[i][j] > dist[i][k] + dist[k][j])  // ����3. i -> j �� ���� ���� 
                {
                    dist[i][j] = dist[i][k] + dist[k][j];  
                }
            }
        }
    }

    // Print the shortest distance matrix
    std::cout << "Shortest distances between every pair of nodes:\n";
    for (int i = 0; i < NUM_NODE; ++i) {
        for (int j = 0; j < NUM_NODE; ++j) {
            if (dist[i][j] == INT_MAX)
                std::cout << "INF ";
            else
                std::cout << dist[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int graph[NUM_NODE][NUM_NODE] = {
        {0, 4, INT_MAX, INT_MAX, INT_MAX, 10},
        {4, 0, 3, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, 3, 0, 2, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, 2, 0, 6, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 6, 0, 1},
        {10, INT_MAX, INT_MAX, INT_MAX, 1, 0},
        // PDF���� ��¿��ô� Ʋ�� ����
    };

    floydWarshall(graph);

    return 0;
}
