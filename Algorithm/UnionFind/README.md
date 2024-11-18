# Union Find

> 두 노드가 같은 그래프에 속하는 지 판별

<br/>

- 여러 노드가 존재할 경우, 특정 두 개의 노드를 같은 집합으로 묶어주고(Union) 어떤 두 노드가 같은 집합에 있는지 확인(Find)
  <br/>

- 주로 그래프에서 연결 요소를 찾거나 합치는데 사용하는 알고리즘
  <br/>

- 각 **부분집합** 을 트리로 나타냄
  <br/>

## 주요 특징

1. **집합(Union)**

   - 여러 개의 요소가 포함된 집합을 관리

   - 특정 요소들이 같은 그룹(집합)에 속해 있는지 확인하거나, 두 집합을 합침
     <br/>

2. **연산(Operations)**

   - `Find`
     - 주어진 요소가 속한 **집합의 대표(루트)** 를 찾음
     - 노드 `x`가 어떤 집합에 포함되어 있는지 찾는 연산
       <br/>
   - `Union`
     - 두 집합을 하나로 합침
     - 노드 `x`와 노드 `y`가 포함되어 있는 집합을 합치는 연산
       <br/>

3. **특징**

   - 크루스칼 알고리즘에서 원소 간의 연결 여부를 판단하는 데에 사용
   - 시간 복잡도: `O(1)`
     <br/>

## 동작 원리

각 노드의 `parents` 배열의 값은 그 노드가 가르키는 노드로 바꿔주는 과정

- `Find`

  - 요소가 속한 **대표 노드(루트)** 를 찾는 function
  - **경로 압축(Path Compression)** 을 통해, 트리 구조를 평탄화

  <br/>

  ```cpp
  int Find(int x)
  {
      if (x == parents[x])
          return;
      return x = Find(parents[x]);
  }
  ```

  <br/>

- `Union`

  - 두 집합을 하나로 합치는 function
  - `x`를 (혹은 `y`를) 포함하는 부분집합을 나타내는 트리를 다른 것의 부트리로 만듬
  - 작은 쪽이 병합됌
    <br/>

  ```cpp
  void Union(int x, int y)
  {
      x = Find(x);
      y = Find(y);

      if (x != y)
      {
          if (x < y)
              parents[y] = x;
          else
              parents[x] = y;
      }

      return;
  }
  ```

  <br/>

## 예시

1. 초기화
2. 병합

```c
#include <stdio.h>

int parents[10001];

int Find(int x)
{
    if (x == parents[x])
        return x;
    return x = Find(parents[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x != y)
    {
        parents[x] = y;
    }

    return;
}

int main(void)
{
    // 부모 배열 초기화
    for (int i = 1; i <= 4; ++i)
        parents[i] = i;

    Union(1, 4);
    Union(2, 4);
    Union(3, 4);

    // 각 노드의 루트를 찾아 출력
    for (int i = 1; i <= 4; ++i)
    {
        printf("노드 %d의 루트: %d\n", i, Find(i));
    }
    return 0;
}
```

```
노드 1의 루트: 4
노드 2의 루트: 4
노드 3의 루트: 4
노드 4의 루트: 4
```

## 연습문제

- [고득점kit-네트워크](https://school.programmers.co.kr/learn/courses/30/lessons/43162)

- [백준-1717(집합의 표현)](https://www.acmicpc.net/problem/1717)

- [백준-1976(여행가자)](https://www.acmicpc.net/problem/1976)

## 참고

- [블로그-참조-(흔들리며 피는 꽃([알고리즘] 유니온 파인드 : Union-Find (Disjoint Set)))](https://eun-jeong.tistory.com/15)

- [블로그 참조 -(aeunhi99:유니온 파인드(Union-Find) 개념)](https://aeunhi99.tistory.com/65)
