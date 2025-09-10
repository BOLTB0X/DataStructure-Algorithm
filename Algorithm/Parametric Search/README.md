# Parametric Search

> 조건에서 최소, 최대를 찾는 문제에서 결정 문제로 변경하여 탐색하는 알고리즘

최적화 문제를 결정문제로 바꾼 뒤 이분 탐색을 이용해 최적해를 찾는 알고리즘

최적 값을 찾기 위해 이진 탐색을 응용한 방식

> 파라메트릭 서치는 이진탐색과 다르게 주어진 일련의 값들이 아니라 주어진 범위 내에서 원하는 값 또는 원하는 조건에 가장 일치하는 값을 찾아내는 알고리즘

- 즉 Parametric Search는 주어진 값을 기준으로 조건을 만족하는지 아닌지 판단하는 과정을 반복하는 방식

- 그 기준이 가능한지 확인한 후, 가능하다면 더 좋은 값을 찾기 위해 범위를 줄여가며 이진 탐색을 수행

---

## 기본 원리

> 특정 값에 대해 "가능한지"를 확인하는 것이고, 이를 통해 이진 탐색을 진행

1. **이진 탐색 범위 설정**

   최소값과 최대값 설정
   
   ---

2. **중간 값 선택**

   1. 범위 안에서 중간 값을 선택하고 그 값이 문제에서 찾는 값으로 가능한지 확인

   2. 가능하다면 더 작은 값에서 탐색하고, 불가능하다면 더 큰 값에서 탐색을 진행

   ---

3. **반복**

   1. 가능 여부를 확인하며 이분 탐색을 반복하면서 범위를 좁혀 나감
   
   2. 범위가 좁혀져서 더 이상 탐색할 수 없을 때 찾는 값에서 (**가장 일치하는 값 == 최적의 해**)를 얻게 되는 것

   ---

## 예시 [백준 - 2805(나무자르기)](https://www.acmicpc.net/problem/2805)

1. 절단기로 `H` 로 자를 때, **적어도** `M` 이상의 나무를 집으로 가져가기 위해 최대 `H`? -> **최적화 문제**
   

2. -> `H`로 나무를 잘랐을 때, `M` 미터 이상의 집으로 가져가는 지 판단하는 결정 문제 (**결정문제**로 변경)

3. 이진탐색을 응용

```swift
import Foundation

func isPossible(_ arr: [Int], _ target: Int, _ h: Int) -> Bool {
    var res = 0

    for height in arr {
        if height > h {
            res += height - h
        }
    }

    return res >= target
}

func parametricSearch(_ arr: [Int], _ target: Int) -> Int {
    var start = 0
    var end = arr.max() ?? 0
    var result = 0

    while start <= end {
        let mid = (start + end) / 2

        if isPossible(arr, target, mid) {
            result = mid // 톱날 높이를 높여도 가능
            start = mid + 1 // 더 높은 높이에서 탐색
        } else {
            end = mid - 1
        }
    }

    return result
}

func solution(_ N: Int, _ M: Int, _ woods: [Int]) -> Int {
    return parametricSearch(woods, M)
}

print(solution(4, 7, [20, 15, 10, 17])) // 15

print(solution(5, 20, [4, 42, 40, 26, 46])) // 36
```

## 연습문제

0. [BOJ-2805(나무 자르기)](https://www.acmicpc.net/problem/2805)

1. [BOJ-2512(예산)](https://www.acmicpc.net/problem/2512)

2. [BOJ-2343(기타 레슨)](https://www.acmicpc.net/problem/2343)

3. [BOJ-6236(용돈 관리)](https://www.acmicpc.net/problem/6236)

4. [BOJ-1654(랜선 자르기)](https://www.acmicpc.net/problem/1654)

5. [BOJ-7795(먹을 것인가 먹힐 것인가)](https://www.acmicpc.net/problem/7795)

## 참고

- [블로그 참조 - marades(이진탐색(Binary Search)와 파라메트릭서치(Parametric Search))](https://marades.tistory.com/7)

- [블로그 참조 - 백준 - 2805(나무자르기)](https://data-flower.tistory.com/99)

- [블로그 참조 - E145(파라메트릭 서치(Parametric Search))](https://9327144.tistory.com/entry/%ED%8C%8C%EB%9D%BC%EB%A9%94%ED%8A%B8%EB%A6%AD-%EC%84%9C%EC%B9%98Parametric-Search)

- [블로그 참조 - Jinhan's Note(이분 탐색, 파라메트릭 서치 안 헷갈리는 TIP)](https://blog.naver.com/jinhan814/222156334908)
