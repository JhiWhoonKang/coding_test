#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define MAX_N 10
#define MAX_K 10
#define MAX_SCORE 10000

int distance(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

int main(void) 
{
    int N, K, P;    // N: ���� ũ��, K: ȭ�� ����, P: ��ǥ ����
    (void)scanf("%d %d %d", &N, &K, &P);

    int target[MAX_N][MAX_N];   // N*N ���� ũ��
    for (int i = 0; i < N; ++i) 
    {
        for (int j = 0; j < N; ++j)
        {
            (void)scanf("%d", &target[i][j]);
        }
    }
     
    int B[MAX_K + 1];   // ȭ�� ����
    for (int i = 1; i <= K; ++i)
    {
        (void)scanf("%d", &B[i]);
    }
    
    int Score[MAX_K + 1][MAX_N][MAX_N];             // [����][row][col]
    for (int arrowNum = 1; arrowNum <= K; ++arrowNum)        // ȭ�� ���� ��� ������
    {
        for (int _x = 0; _x < N; ++_x)              // ȭ�� �߽� ��ǥ x
        {
            for (int _y = 0; _y < N; ++_y)          // ȭ�� �߽� ��ǥ y
            {
                int sum = 0;
                for (int x = 0; x < N; ++x)         // x ��ŭ ������ �Ÿ�
                {
                    for (int y = 0; y < N; ++y)     // y ��ŭ ������ �Ÿ�
                    {
                        int dist = distance(_x, _y, x, y);
                        if (dist < arrowNum)
                        {
                            sum += target[x][y];
                        }
                    }
                }
                Score[arrowNum][_x][_y] = sum;         // ȭ�� ���� ���� ���� �Ϸ�
            }
        }
    }

    int dp[MAX_K + 1][MAX_SCORE + 1];               // ���� 1 ~ K�� ���� �ּ� ��� ��� [thick][cost]
    for (int thick = 0; thick <= K; ++thick)
    {
        for (int score = 0; score <= P; ++score)
        {
            dp[thick][score] = INT_MAX;
        }
    }
    dp[0][0] = 0;

    for (int arrowNum = 1; arrowNum <= K; ++arrowNum)               // ��� ȭ�� ����
    {
        for (int score = 0; score <= P; ++score)                    // Score ���� 0 ~ P
        {
            if (dp[arrowNum - 1][score] < dp[arrowNum][score])      // ȭ�� ��� X
            {
                dp[arrowNum][score] = dp[arrowNum - 1][score];
            }

            if (dp[arrowNum - 1][score] != INT_MAX)            // ȭ�� ���
            {
                for (int _x = 0; _x < N; ++_x)
                {
                    for (int _y = 0; _y < N; ++_y)
                    {
                        int add = Score[arrowNum][_x][_y];
                        if (score + add <= P)
                        {
                            int newScore = score + add;
                            int newCost = dp[arrowNum - 1][score] + B[arrowNum];
                            if (newCost < dp[arrowNum][newScore])
                            {
                                dp[arrowNum][newScore] = newCost;
                            }
                        }
                    }
                }
            }
        }
    }

    if (dp[K][P] == INT_MAX)
    {
        printf("-1");
    }        
    else
    {
        printf("%d", dp[K][P]);
    }
        
    return 0;
}