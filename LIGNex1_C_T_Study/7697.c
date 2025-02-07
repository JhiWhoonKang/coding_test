#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node 
{
    int pos;              // �ʱ� ��ġ
    long long size;       // ���� ũ��
    struct Node* prev;
    struct Node* next;
} Node;

// Node ����
Node* createNode(int pos, int size) 
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->pos = pos;
    node->size = size;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

int main() 
{
    int N;
    (void)scanf("%d", &N);
    
    int* arr = (int*)malloc(sizeof(int) * (N + 1));       // size �Է� �迭
    for (int i = 1; i <= N; ++i) 
    {
        (void)scanf("%d", arr + i);
    }
 
    // deque ������
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 1; i <= N; ++i)
    {
        Node* node = createNode(i, *(arr + i));     // 0�� ~ N�� ��� ���� �����
        if (head == NULL) 
        {
            head = tail = node;
        }
        else 
        {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    //      ���� head: node ó��
    //           tail: node ������
    while (head != tail) 
    { 
        for (Node* cur = head; cur != NULL; cur = cur->next) 
        {
            // �̹� turn�� ���� ũ�� (���� turn ���� �� ũ��)
            long long currSize = cur->size;

            if (cur->prev && cur->prev->size <= currSize)       // ���� ��
            {                
                cur->size += cur->prev->size;               // ũ�� ����
                
                Node* removeNode = cur->prev;                 // ���� ��� ����
                if (removeNode->prev)                         // ������ ����� prev�� �����ϸ� ȭ��ǥ �ٽ� �̾��ֱ�
                {
                    removeNode->prev->next = cur;
                    cur->prev = removeNode->prev;
                }
                else                                        // ù ����� ��
                {
                    head = cur;
                    cur->prev = NULL;
                }
                free(removeNode);
            }

            if (cur->next && cur->next->size <= currSize)       // ������ ��
            {
                cur->size += cur->next->size;
                Node* removeNode = cur->next;
                if (removeNode->next)
                {
                    removeNode->next->prev = cur;
                    cur->next = removeNode->next;
                }
                else 
                {
                    tail = cur;
                    cur->next = NULL;
                }
                free(removeNode);
            }
        }
    }

    printf("%lld\n%d\n", head->size, head->pos);
    return 0;
}