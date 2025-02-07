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
char S[MAX + 1];	// input: 입력 문자열, 좋아하는 산책길 종류 순서

void AddEdge(int u, int v, char c)
{
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->to = v;
    edge->c = c;
    edge->next = *(tree + u);
    *(tree + u) = edge;
}

// 시작점: 항상 1번 정점
// 끝점: 1번 정점을 루트로 봤을 때의 리프 노드 중 하나
int maxHappy = 0;
char path[MAX + 1];
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
        int happy = LCS(path, S, path_len, M);
        if (happy > maxHappy)
        {
            maxHappy = happy;
        }
    }
}

int maxSearch[MAX + 1][MAX + 1];        // dp 돌릴거
int LCS(char*ss, char *SS, int s_len, int S_len)
{   
    for (int i = 1; i <= s_len; ++i)
    {
        //for (int j = i; j <= S_len; ++j)
        for (int j = 1; j <= S_len; ++j)
        {
        
            if (*(ss + (i - 1)) == *(SS + (j - 1))) // for문 돌리다가 문자 같은거 발견
            {
                maxSearch[i][j] = maxSearch[i - 1][j - 1] + 1;               
                //return;
            }
            else // 다르면 최댁ㅅ밧 적용
            {
                maxSearch[i][j] = (maxSearch[i - 1][j] > maxSearch[i][j - 1]) ? maxSearch[i - 1][j] : maxSearch[i][j - 1];
                //maxSearch[i][j] = maxSearch[i - 1][j - 1];
            }
        }
    }
    return maxSearch[s_len][S_len];
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
    
    DFS(1, -1, path, 0);

    printf("%d\n", maxHappy);

	return 0;
}
#endif