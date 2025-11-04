# 깊이/너비 우선 탐색 (DFS, BFS)

> 그래프 탐색 알고리즘의 기본 중의 기본

## DFS (Depth-First Search, 깊이 우선 탐색)

> 한 경로를 끝까지 파고드는 탐색 방식<br/>
> *“가장 깊은 곳까지 내려갔다가, 더 이상 갈 곳이 없으면 되돌아오기(backtracking)"*

<p align="center">
<img src="https://github.com/BOLTB0X/DataStructure-Algorithm/blob/main/Img/DFS.png?raw=true" alt="Example Image" width="70%"/>
</p>

출발 노드에서부터 최대한 깊숙이 들어가 탐색을 진행하고, 

더 이상 갈 곳이 없으면 되돌아 나와(Backtrack) 다른 경로를 탐색하는 알고리즘

### 탐색 순서

- 한 방향으로 갈 수 있는 끝까지 탐색한 후,

- 막다른 길에 도달하면 직전 분기점으로 돌아와(Backtracking) 다른 방향으로 다시 깊숙이 들어감

### 시간복잡도

- `O(V + E)` (`V` : 정점 수, `E` : 간선 수)

### 사용 자료구조

- 경로를 저장하고 되돌아오는 순서를 제어하기 위해 스택(Stack) 사용

- 또는 재귀 함수 호출 사용 *(LIFO: Last-In, First-Out)*

### 장단점

- 장점: 특정 경로가 존재하는지 확인하거나 모든 경로를 탐색하는 경우에 유용하며, BFS보다 메모리 사용량이 적음 (현재 탐색 중인 경로만 저장)

- 단점: 최단 경로를 보장하지 않음, 특히 깊이가 매우 깊고 해답이 가까운 곳에 있는 경우 비효율적일 수 있음

### 동작 구조

<p align="center">
<img src="https://github.com/BOLTB0X/DataStructure-Algorithm/blob/main/Img/%EC%98%88%EC%8B%9C.png?raw=true" alt="Example Image" width="50%"/>

```swift
func dfs(_ graph: [[Int]], _ visited: inout [Bool], _ start: Int) {
    visited[start] = true
    print(start, terminator: " ")

    for next in graph[start] {
        if !visited[next] {
            dfs(graph, &visited, next)
        }
    }
} // dfs

let graph = [
    [],         // 0 (unused)
    [2, 3],     // 1 → 2,3
    [4],        // 2 → 4
    [4],        // 3 → 4
    [],         // 4
]
var visited = Array(repeating: false, count: 5)

dfs(graph, &visited, 1)
```

1. 시작 노드를 방문하고, 방문 표시

2. 인접한 노드 중 아직 방문하지 않은 노드로 재귀(또는 스택) 를 통해 이동

3. 더 이상 방문할 노드가 없으면 이전 단계로 backtrack

---

## BFS (Breadth-First Search, 너비 우선 탐색)

> 시작점에서 가까운 노드부터 차례로 탐색하는 방식<br/>
> * *“한 단계씩 바깥으로 퍼져나가는 탐색”*

<p align="center">
<img src="https://github.com/BOLTB0X/DataStructure-Algorithm/blob/main/Img/DFS.png?raw=true" alt="Example Image" width="70%"/>

너비 방향으로 탐색을 확장하는 알고리즘

### 탐색 순서

- 출발 노드에서부터 거리가 `1인 노드`들을 먼저 모두 탐색한 후,

- 거리가 `2인 노드들` 을 탐색하는 식으로 **같은 깊이(Level** )에 있는 노드들을 먼저 탐색함

### 시간복잡도

- `O(V + E)` (`V` : 정점 수, `E` : 간선 수)

### 사용 자료구조

- 노드를 저장하고 방문 순서를 제어하기 위해 **큐(Queue)**를 사용 (FIFO: First-In, First-Out)

### 장단점

- **장점**

    - **최단 경로(Shortest Path)**를 찾는 데 가장 효율적
    
    - 가중치가 없는 그래프에서 출발 노드로부터 특정 노드까지 가는 최소 간선 수(거리)를 보장

- **단점**

    - 탐색해야 할 노드의 수가 많고 그래프의 너비가 넓을 경우,
    
    - 모든 노드를 저장해야 하므로 메모리 사용량이 많아질 수 있음

### 동작 구조

<p align="center">
<img src="https://github.com/BOLTB0X/DataStructure-Algorithm/blob/main/Img/%EC%98%88%EC%8B%9C.png?raw=true" alt="Example Image" width="50%"/>

```swift
func bfs(_ graph: [[Int]], _ start: Int) {
    var visited = Array(repeating: false, count: graph.count)
    var queue = [start]
    visited[start] = true
    
    while !queue.isEmpty {
        let node = queue.removeFirst()
        print(node, terminator: " ")
        
        for next in graph[node] {
            if !visited[next] {
                visited[next] = true
                queue.append(next)
            }
        } // for
    } //while
} // bfs

let graph = [
    [],         // 0 (unused)
    [2, 3],     // 1 → 2,3
    [4],        // 2 → 4
    [4],        // 3 → 4
    [],         // 4
]

var visited = Array(repeating: false, count: 5)

dfs(graph, &visited, 1) // 1 2 4 3

bfs(graph, 1) // 1 2 3 4 (방문 순서)
```

1. 시작 노드를 큐(Queue)에 넣음

2. 큐에서 하나를 꺼내며, 그 노드의 인접 노드들을 모두 방문하고 큐에 추가

3. 큐가 빌 때까지 `2`를 반복

---

## 미로 탐색 ex

```
0 1 0
0 0 0
1 0 0
```

- 시작점: `(0,0)`

- 도착점: `(2,2)`

| 알고리즘    | 탐색 흐름                           | 결과                   |
| ------- | ------------------------------- | -------------------- |
| **DFS** | 한 경로를 끝까지 가므로 비효율적일 수 있음        | 도착까지의 경로 존재 여부 판별 가능 |
| **BFS** | 한 칸씩 퍼지므로 최단거리(=이동 횟수)를 구할 수 있음 | 최단 거리 보장             |



## 참고

- [유튜브 - DFS BFS 깊이 너비 우선탐색 알고리즘 5분만에 이해하기(개발자로 취직하기)](https://www.youtube.com/watch?v=BsYbdUnKZ-Y)

- [블로그 참고 - 그래프(Graph) 순회 (DFS & BFS)(gliver)](https://gliver.tistory.com/36)