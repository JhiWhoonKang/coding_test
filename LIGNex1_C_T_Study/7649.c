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
int N, M;			// N: 정점의 개수, M: 문자열의 길이
char S[MAX];	// input: 입력 문자열, 좋아하는 산책길 종류 순서

void AddEdge(int u, int v, char c)
{
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->to = v;
    edge->c = c;
    edge->next = *(tree + v);
    *(tree + u) = edge;
}

// 시작점: 항상 1번 정점
// 끝점: 1번 정점을 루트로 봤을 때의 리프 노드 중 하나
int maxHappy = 0;
void DFS(int node, int parent, char* path, int path_len) 
{
    Edge* edge = *(tree + node);
    int is_leaf = 1;        // 리프면 1, 아니면 0 => 0이면 더 DFS

    while (edge)
    {
        if (edge->to != parent) // 부모 노드로 되돌아가지 않음
        {
            is_leaf = 0;
            path[path_len] = edge->c;            
            DFS(edge->to, node, path, ++path_len);
        }
        edge = edge->next;
    }

    if (is_leaf) // 리프까지 왔으니까 문자열 비교
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
    for (int i = 0;i < N - 1;++i)      //u, v, c 순으로 입력
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

// 트리의 간선을 저장할 구조체
typedef struct Edge {
    int to;
    char c;
    struct Edge* next;
} Edge;

// 트리 저장을 위한 배열
Edge* tree[MAX_N + 1];
int N, M;
char S[MAX_M + 1];
int max_happiness = 0;

// 간선 추가 함수
void add_edge(int u, int v, char c) {
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->to = v;
    edge->c = c;
    edge->next = tree[u];
    tree[u] = edge;
}

// LCS 계산 함수 (길이가 len1인 str1과 len2인 str2)
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

// DFS 탐색 함수
void dfs(int node, int parent, char* path, int path_len) {
    Edge* edge = tree[node];
    int is_leaf = 1;

    while (edge) {
        if (edge->to != parent) { // 부모 노드로 되돌아가지 않음
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