#include "DynamicPrograming.h"


#define DEFAULT -1
std::vector<int> stairDP;

int Fibonacci(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int Fibonacci_DP(int n)
{
    // 임시로 저장할 공간 -> 중복되는 사항을 저장하고, 필요할 때마다 사용
    int* dp = new int[n + 1];

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// 계단 0층, (10, 20, 15, 25, 10, 20)
int Max_Stair_Recursive(int i, std::vector<int> stairs)
{
    // stairDP 데이터가 -1이 아니면 (데이터 메모가 되어 있으면)
    // 해당 데이터를 리턴
    if (stairDP[i] != -1)
    {
        return stairDP[i];
    }

    // 계단 1층일 때 최대 값
    if (i == 0)
    {
        return stairs[0];
    }

    // 계단 2층일 때 최대 값
    if (i == 1)
    {
        return stairs[0] + stairs[1];
    }

    // 계단 3층일 때 최대 값
    if (i == 2)
    {
        return std::max(stairs[0] + stairs[2], stairs[1]);
    }

    stairDP[i] = std::max(Max_Stair_Recursive(i - 2, stairs), Max_Stair_Recursive(i - 3, stairs) + stairs[i - 1]) + stairs[i];

    return stairDP[i];
}

int StairCount(std::vector<int> stairs)
{
    int size = stairs.size();

    stairDP.assign(size, DEFAULT);    // Default값이 -1이다.

    return Max_Stair_Recursive(size - 1, stairs);
}

