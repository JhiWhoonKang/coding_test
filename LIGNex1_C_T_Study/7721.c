#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

double F[4];            // �絹�� ��
double PROB = 0.0;      // Ȯ��

// Red vs Blue
// 1�� �絹 vs 2�� | 1�� �絹 vs 3�� | 1�� �絹 vs 4�� | 2�� �絹 vs 3�� | 2�� �絹 vs 4�� | 3�� �絹 vs 4��
int R[6] = { 0, 0, 0, 1, 1, 2 }; // Red ��
int B[6] = { 1, 2, 3, 2, 3, 3 }; // Blude ��

void dfs(int matchIndex, int points[4], double prob) 
{    
    if (matchIndex == 6) // ��� ��⸦ ����
    {
        int cnt = 0;
        for (int i = 1; i < 4; ++i) 
        {
            if (points[i] > points[0])
            {
                ++cnt; // 1�� �絹������ Ŀ => cnt ����
            }
            else if (points[i] == points[0]) // ���� -> 1�� �絹���� ������ �̱�
            {
                continue;
            }
        }
        if (cnt < 2) // 2�� �ȿ� ���� cnt 1�̸� 2��
        {
            PROB += prob;
        }
        return;
    }

    int red = R[matchIndex];        // ���� ��ġ red �� ��
    int blue = B[matchIndex];       // ���� ��ġ blue �� ��

    printf("\n=================\n");
    // red �� �¸� => red point 3�� �߰� => ��� ��� ���� �Ǹ� �ٽ� point �ʱ�ȭ
    double win = ((4 * F[red]) / (5 * F[red] + 5 * F[blue]));    
    points[red] += 3;       // red �� i ��ȣ �絹�� ����Ʈ ����    
    printf("win matchIndex: %d, prob: %.3f\n", matchIndex, prob);
    dfs(matchIndex + 1, points, prob * win);
    printf("win matchIndex: %d, prob: %.3f\n", matchIndex, prob);
    points[red] -= 3;    
    printf("\n=================\n");

    printf("\n=================\n");
    // blue �� �¸�
    double lose = ((4 * F[blue]) / (5 * F[red] + 5 * F[blue]));    
    points[blue] += 3;
    printf("lose matchIndex: %d, prob: %.3f\n", matchIndex, prob);
    dfs(matchIndex + 1, points, prob * lose);
    printf("lose matchIndex: %d, prob: %.3f\n", matchIndex, prob);
    points[blue] -= 3;
    printf("\n=================\n");

    printf("\n=================\n");
    // ���º�
    double draw = ((F[red] + F[blue]) / (5 * F[red] + 5 * F[blue]));    
    points[red] += 1;
    points[blue] += 1;
    printf("draw matchIndex: %d, prob: %.3f\n", matchIndex, prob);
    dfs(matchIndex + 1, points, prob * draw);
    printf("draw matchIndex: %d, prob: %.3f\n", matchIndex, prob);
    points[red] -= 1;
    points[blue] -= 1;    
    printf("\n=================\n");
}

int main()
{
    // �絹�� �� �Է�
    (void)scanf("%lf %lf %lf %lf", &F[0], &F[1], &F[2], &F[3]);

    int points[4] = {0, 0, 0, 0};   // �絹�� ����
    dfs(0, points, 1.0);            // dfs ����

    double result = PROB * 100.0;   // Ȯ�� ���
    printf("%.3f\n", result);

    return 0;
}