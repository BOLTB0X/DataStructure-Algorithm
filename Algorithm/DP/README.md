# Dynamic Programming

> 복잡한 문제를 단순한 하위(작은) 문제로 나누어 해결하는 최적화 기법 중 대표적인 예

- DP는 동일한 하위 문제를 여러 번 계산하는 대신, 한 번 계산한 결과를 저장하고 재사용하여 연산을 줄이는 방식

  -> **Memoization(메모이제이션)**

- 작은 문제들이 **반복**되며, 그것을 이용해 문제를 풀어나간다는 점

---

## 기본 원리

> 가장 작은 부분의 해답을 구한 후, 이를 저장하여, 저장한 값을 이용해 상위 문제를 풀어가는 방식

- 문제를 작은 하위 문제로 나누는 경우 -> **재귀(recursion)**

문제를 여러 개의 더 작은 하위 문제로 나눠 재귀적으로 해결

- 중복되는 하위 문제를 저장 -> **Memoization(메모이제이션)**

  하위 문제의 결과를 저장하여, 같은 하위 문제를 다시 계산하지 않고 이전에 계산된 결과를 사용

- 최적 부분 구조(Optimal Substructure)

  문제의 최적 해결 방법이 하위 문제들의 최적 해결 방법으로 구성될 수 있는 특성이 있어야 함

부분 문제의 최적 해가 전체 문제의 최적 해를 이끌어내는 경우에 DP를 사용함

---

## 적용 해야할 때

- **중복된 하위 문제**

  *문제를 재귀적으로 풀 때, 동일한 하위 문제가 여러 번 등장하는 경우*
  

- **최적 부분 구조**

  *문제를 여러 하위 문제로 나누기 가능하며, 각 하위 문제의 최적 해를 모아서 전체 문제의 최적 해를 구할 수 있을 때*

---

## 방식

- **Top-Down**

  큰 문제를 작은 문제로 쪼개면서 해결하고 재귀로 구현


- **Bottom-Up**

  작은 문제부터 차례대로 해결, 반복문으로 구현

---

## 피보나치 수열(Fibonacci numbers)

> 피보나치 수열은 대표적인 다이나믹 프로그래밍 문제

피보나치수열은 제2항 까지는 1, 제3항부터는 바로 앞의 두 항을 더한 수가 반복되는 수열

일반적으로 피보나치 수열은 다음과 같이 정의

_F(0) = 0_
_F(1) = 1_
_F(n) = F(n-1) + F(n-2) (n ≥ 2)_

```
1, 1, 2, 3, 5, 8, 13, 21, 34, 55...
```

- **Top-Down**

  ```swift
  // 시간복잡도 O(2^n)
  func fibo_Topdown(_ n: Int) -> Int {
      if n <= 1 {
          return n;
      } else {
          if dp[n] > 0 {
              return dp[n]
          }

          dp[n] = fibo_Topdown(n-1) +
          fibo_Topdown(n-2)
          return dp[n]
       }
   }

  print(fibo_Topdown(5))
  // 5
  ```

  _아래 그림 처럼 메서드 호출을 나타내면_

<div style="text-align: center;">
<img src="https://github.com/BOLTB0X/DataStructure-Algorithm/blob/main/Algorithm/DP/%ED%94%BC%EB%B3%B4%EB%82%98%EC%B9%98.png?raw=true" alt="Example Image" width="70%">
</div>

중복되는 연산이 많고 시간 복잡도는 지수 함수가 되어버림

- **Bottom-Up**

  큰 문제에서 작은 문제로 연산하기 보단 작은 연산 결과를 저장해두었다 이용하는 것이 \*\*Bottom-Up

  **Memoization**을 이용하고 이를 배열에 저장하는 것으로 구현

  ```swift
  // MARK: - Bottom up
  // 시간복잡도 O(n)
  func fibo_Bottomup(_ n: Int) -> Int {
      dp = Array(repeating: 0, count: 1000)

      dp[0]
      dp[1] = 1

      for i in 2...n {
          dp[i] = dp[i-1] + dp[i-2]
      }

      return dp[n]
   }

  print(fibo_Bottomup(5))
  // 5
  ```

---

## 연습하기 좋은 문제

- [BOJ 1463 - 1로 만들기](https://www.acmicpc.net/problem/1463)

- [BOJ 2579 - 계단 오르기](https://www.acmicpc.net/problem/2579)

- [BOJ 15486 - 퇴사 2](https://www.acmicpc.net/problem/15486)

---

## 참고

- [블로그 참조 - 개발자 소들이 - DP](https://babbab2.tistory.com/100)

- [블로그 참조 - 코드 연구소](https://code-lab1.tistory.com/7)

- [블로그 참조 - Juwon](https://juwon-yun.tistory.com/34)
