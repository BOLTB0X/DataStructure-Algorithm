#include <stdio.h>
#include <stdlib.h>

// 간선 구조체 정의
typedef struct
{
    int u, v;   // 간선을 연결하는 두 노드
    int weight; // 간선의 가중치
} Edge;

// 부모 배열
int parents[5 + 1];

// 간선 비교 함수 (가중치 기준 정렬)
int compare(const void *a, const void *b)
{
    Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    return edgeA->weight - edgeB->weight;
}

// Find 연산 (경로 압축 적용)
int Find(int x)
{
    if (x == parents[x])
        return x;
    return parents[x] = Find(parents[x]);
}

// Union 연산
void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x != y)
    {
        parents[y] = x; // 한 쪽을 루트로 병합
    }
}

int main()
{
    // 간선 리스트
    Edge edges[7] = {
        {1, 2, 4},
        {1, 3, 3},
        {1, 4, 8},
        {2, 4, 7},
        {3, 4, 10},
        {3, 5, 1},
        {4, 5, 5},
    };

    // 부모 배열 초기화
    for (int i = 1; i <= 5; i++)
    {
        parents[i] = i;
    }

    // 간선을 가중치 기준으로 정렬
    qsort(edges, 7, sizeof(Edge), compare);

    // 크루스칼 알고리즘 수행
    int mst_weight = 0; // MST의 총 가중치
    printf("선택된 간선들 (MST):\n");
    for (int i = 0; i < 7; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        // 사이클이 생기지 않으면 간선 선택
        if (Find(u) != Find(v))
        {
            Union(u, v);
            mst_weight += weight;
            printf("(%d, %d) - 가중치: %d\n", u, v, weight);
        }
    }

    printf("최소 신장 트리의 총 가중치: %d\n", mst_weight);
    return 0;
}
