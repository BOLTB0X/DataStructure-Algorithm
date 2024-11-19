# Minimum Spanning Tree, MST

> 무향 그래프에서 모든 노드를 연결하는 간선들의 부분 집합 중에서 총 가중치가 최소가 되는 트리를 의미

<br/>

## Spanning Tree(신장트리)

> 그래프 내의 모든 정점을 포함하지만 사이클이 없는 트리

<br/>

- **정의**

  - Spanning Tree는 그래프의 최소 연결 부분 그래프
  - 최소 연결 = 간선의 수가 가정 적음
  - `n`개의 정점을 가지는 그래프의 최소 간선의 수는 `(n-1)`개
    <br/>

- **특징**

  - 하나의 그래프에는 많은 신장 트리가 존재 가능

  - 모든 정점들이 **연결**되어 있어야 하고 **사이클**을 포함 되서는 X
  - DFS, BFS을 이용하여 그래프에서 Spanning Tree(신장 트리)를 찾기 가능
    <br/>

## Minimum Spanning Tree(최소 신장트리)

- **정의**
  가중치 그래프에서 모든 정점을 연결하면서 가중치의 합이 최소가 되는 트리 구조
  <br/>

- **특징**

  - 트리 구조: 사이클이 없는 연결 그래프
  - 정점 수가 `V` 라면, 간선 수는 `V - 1`
  - 여러 개의 MST가 존재 가능
    <br/>

- **어떠한 그래프에서 MST 만드는 방법**

  - 크루스칼 알고리즘 (Kruskal's Algorithm)

    - _간선을 가중치 순으로 정렬하고, 작은 것부터 차례로 추가하며 사이클이 생기지 않도록 연결_
    - _Union-Find 사용해 사이클 여부를 판단_
    - 시간복잡도 _`O(ElogE)`, `E`는 간선의 수_
      <br/>

  - 프림 알고리즘 (Prim's Algorithm)

    - _특정 정점에서 시작해, 현재 트리에서 연결 가능한 가장 작은 가중치의 간선을 추가_
    - _최소 힙(Priority Queue) 사용_
    - 시간복잡도 _`O(ElogV)`, `V`는 정점의 수_
      <br/>

## 크루스칼 예제

```c
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
```

## 프림 예제

```c
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define INF INT_MAX

// 그래프를 인접 행렬로 표현
int graph[6][6] = {
    {0, 1, 3, INF, INF},
    {1, 0, 8, 4, INF},
    {3, 8, 0, 10, 1},
    {INF, 4, 10, 0, 5},
    {INF, INF, 1, 5, 0}};

// 최소 가중치를 가진 정점을 찾는 함수
int findMinKey(int key[], bool included[], int n)
{
    int min = INF, minIndex;

    for (int v = 0; v < n; v++)
    {
        if (!included[v] && key[v] < min)
        {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// 프림 알고리즘
void primMST(int n)
{
    int parent[6];              // MST의 각 정점의 부모
    int key[6];                 // 최소 가중치 값
    bool included[6] = {false}; // MST에 포함 여부

    // 초기화
    for (int i = 0; i < n; i++)
    {
        key[i] = INF;
        parent[i] = -1;
    }

    // 시작 정점 (0번 정점) 초기화
    key[0] = 0;

    // n개의 정점을 모두 처리할 때까지 반복
    for (int count = 0; count < n - 1; count++)
    {
        // 최소 가중치 정점 선택
        int u = findMinKey(key, included, n);
        included[u] = true;

        // 선택된 정점과 연결된 정점들 갱신
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && !included[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // 결과 출력
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++)
    {
        printf("%d - %d \t%d\n", parent[i], i, graph[parent[i]][i]);
    }
}

int main()
{
    primMST(5);
    return 0;
}
```

## 참고

- [블로그 참조-ansohxxn(최소 신장 트리 MST, 크루스칼 알고리즘, 프림 알고리즘)](https://ansohxxn.github.io/algorithm/mst/)

- [블로그 참조-gmlwjd9405(최소 신장 트리(MST, Minimum Spanning Tree)란)](https://gmlwjd9405.github.io/2018/08/28/algorithm-mst.html)

- [블로그 참조-dongvelop(최소 신장 트리(MST, Minimum Spanning Tree)란)](https://velog.io/@dongvelop/%EC%8A%A4%ED%8C%A8%EB%8B%9D-%ED%8A%B8%EB%A6%AC-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98)
