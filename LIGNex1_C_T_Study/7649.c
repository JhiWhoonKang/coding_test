#if 01
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAX 5000

typedef struct _Edge
{
	int to;
	char c;
	struct _Edge* next;
} Edge;

Edge* tree[MAX + 1];
int N, M;			// N: ������ ����, M: ���ڿ��� ����
char S[MAX];	// input: �Է� ���ڿ�, �����ϴ� ��å�� ���� ����

void AddEdge(int u, int v, char c)
{
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->to = v;
    edge->c = c;
    edge->next = *(tree + v);
    *(tree + u) = edge;
}

// ������: �׻� 1�� ����
// ����: 1�� ������ ��Ʈ�� ���� ���� ���� ��� �� �ϳ�
int maxHappy = 0;
void DFS(int node, int parent, char* path, int path_len) 
{
    Edge* edge = *(tree + node);
    int is_leaf = 1;        // ������ 1, �ƴϸ� 0 => 0�̸� �� DFS

    while (edge)
    {
        if (edge->to != parent) // �θ� ���� �ǵ��ư��� ����
        {
            is_leaf = 0;
            path[path_len] = edge->c;            
            DFS(edge->to, node, path, ++path_len);
        }
        edge = edge->next;
    }

    if (is_leaf) // �������� �����ϱ� ���ڿ� ��
    {
        path[path_len + 1] = '\0';
        int happiness = LCS(path, path_len, S, M);
        if (happiness > maxHappy)
        {
            maxHappy = happiness;
        }
    }
}

int LCS()
{
    return;
}

int main(void)
{
    (void)scanf("%d %d", &N, &M);
	(void)scanf("%s ", S);
    for (int i = 0;i < N - 1;++i)      //u, v, c ������ �Է�
    {
        int u, v;
        char c;
        (void)scanf("%d %d %c", &u, &v, &c);
        AddEdge(u, v, c);
        AddEdge(v, u, c);
    }



	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 5000
#define MAX_M 5000

// Ʈ���� ������ ������ ����ü
typedef struct Edge {
    int to;
    char c;
    struct Edge* next;
} Edge;

// Ʈ�� ������ ���� �迭
Edge* tree[MAX_N + 1];
int N, M;
char S[MAX_M + 1];
int max_happiness = 0;

// ���� �߰� �Լ�
void add_edge(int u, int v, char c) {
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->to = v;
    edge->c = c;
    edge->next = tree[u];
    tree[u] = edge;
}

// LCS ��� �Լ� (���̰� len1�� str1�� len2�� str2)
int compute_LCS(char* str1, int len1, char* str2, int len2) {
    int dp[MAX_M + 1][MAX_M + 1] = { 0 };
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }
    return dp[len1][len2];
}

// DFS Ž�� �Լ�
void dfs(int node, int parent, char* path, int path_len) {
    Edge* edge = tree[node];
    int is_leaf = 1;

    while (edge) {
        if (edge->to != parent) { // �θ� ���� �ǵ��ư��� ����
            is_leaf = 0;
            path[path_len] = edge->c;
            path[path_len + 1] = '\0';
            dfs(edge->to, node, path, path_len + 1);
        }
        edge = edge->next;
    }

    if (is_leaf) {
        int happiness = compute_LCS(path, path_len, S, M);
        if (happiness > max_happiness) {
            max_happiness = happiness;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    scanf("%s", S);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        char c;
        scanf("%d %d %c", &u, &v, &c);
        add_edge(u, v, c);
        add_edge(v, u, c);
    }

    char path[MAX_N + 1];
    dfs(1, -1, path, 0);

    printf("%d\n", max_happiness);
    return 0;
}

#endif