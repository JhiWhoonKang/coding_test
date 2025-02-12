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
    int N, K, P;    // N: 과녁 크기, K: 화살 개수, P: 목표 점수
    (void)scanf("%d %d %d", &N, &K, &P);

    int target[MAX_N][MAX_N];   // N*N 과녁 크기
    for (int i = 0; i < N; ++i) 
    {
        for (int j = 0; j < N; ++j)
        {
            (void)scanf("%d", &target[i][j]);
        }
    }
     
    int B[MAX_K + 1];   // 화살 굵기
    for (int i = 1; i <= K; ++i)
    {
        (void)scanf("%d", &B[i]);
    }
    
    int Score[MAX_K + 1][MAX_N][MAX_N];             // [굵기][row][col]
    for (int arrowNum = 1; arrowNum <= K; ++arrowNum)        // 화살 굵기 모두 돌리기
    {
        for (int _x = 0; _x < N; ++_x)              // 화살 중심 좌표 x
        {
            for (int _y = 0; _y < N; ++_y)          // 화살 중심 좌표 y
            {
                int sum = 0;
                for (int x = 0; x < N; ++x)         // x 만큼 떨어진 거리
                {
                    for (int y = 0; y < N; ++y)     // y 만큼 떨어진 거리
                    {
                        int dist = distance(_x, _y, x, y);
                        if (dist < arrowNum)
                        {
                            sum += target[x][y];
                        }
                    }
                }
                Score[arrowNum][_x][_y] = sum;         // 화살 굵기 별로 저장 완료
            }
        }
    }

    int dp[MAX_K + 1][MAX_SCORE + 1];               // 굵기 1 ~ K에 대해 최소 비용 계산 [thick][cost]
    for (int thick = 0; thick <= K; ++thick)
    {
        for (int score = 0; score <= P; ++score)
        {
            dp[thick][score] = INT_MAX;
        }
    }
    dp[0][0] = 0;

    for (int arrowNum = 1; arrowNum <= K; ++arrowNum)               // 사용 화살 개수
    {
        for (int score = 0; score <= P; ++score)                    // Score 점수 0 ~ P
        {
            if (dp[arrowNum - 1][score] < dp[arrowNum][score])      // 화살 사용 X
            {
                dp[arrowNum][score] = dp[arrowNum - 1][score];
            }

            if (dp[arrowNum - 1][score] != INT_MAX)            // 화살 사용
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