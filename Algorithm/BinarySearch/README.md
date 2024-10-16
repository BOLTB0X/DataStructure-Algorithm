# Binary Search(이진 탐색)

> 정렬되어 있는 data에서 특정한 값을 찾아내는 알고리즘

- 이분 탐색이라고도 불리며 Binary Search(이진 탐색)은 탐색 범위를 반으로 나누어 찾는 값을 포함하는 범위를 좁혀가는 방식
  <br/>

- Binary Search(이진 탐색)은 data를 반씩 줄여가며 탐색하기 때문에 시간 복잡도가 매우 낮음

## 기본 원리

- 전제 조건
  이진 탐색은 **오름차순** 또는 **내림차순**으로 정렬된 _배열(Array)_ 이나 _컬렉션(Collection)_ 에서만 사용 가능
  <br/>

- 탐색 방법
  1.  배열의 중간값을 선택
  2.  찾고자 하는 값이 중간값(middle)과 같은지 확인
  3.  찾고자 하는 값이 중간값(middle)보다 크다면, 중간값(middle)의 오른쪽 절반에서 탐색을 계속 진행
  4.  찾고자 하는 값이 중간값(middle)보다 작다면, 중간값(middle)의 왼쪽 절반에서 탐색을 계속 진행
  5.  이 과정을 반복하여 값을 찾거나, 값이 없음을 확인
      <br/>

## 시간복잡도

```
O(log N)
```

실행할수록 탐색 범위가 절반씩 줄어들기 때문에, 데이터의 양이 많아질수록 상대적으로 빠르게 탐색 가능

## 예시 in 배열

_배열 A = [0, 1, 2, 3, 5, 7, 9, 10, 11, 13, 19, 22]에서 숫자 7을 찾는 경우_

- **Recursion**

  ```swift
  func binarySearch_Recursion<T: Comparable>(_ arr: [T], _ target: T, start: Int, end: Int) -> Int? {
      guard start <= end else {
          return nil
      }

      let middle = (start + end) / 2

      if arr[middle] == target {
          return middle
      } else if arr[middle] < target {
          return binarySearch_Recursion(arr, target, start: middle + 1, end: end)
      }

      return binarySearch_Recursion(arr, target, start: start, end: middle - 1)
  }
  ```

  1. 배열의 중간값 -> 9, 그러므로 **9 > 7**이므로 왼쪽 절반 [0, 1, 2, 3, 5, 7]에서 탐색을 계속 진행

  2. 왼쪽 절반의 중간값 -> 2, **2 < 7**이므로 오른쪽 절반 [3, 5, 7]에서 탐색을 계속 진행

  3. 중간 값은 5, **5 < 7** 이번에도 오른쪽을 자르면 7 하나만 element로 있으며 해당 값을 찾을 수 있음
     <br/>

  ```swift
  let A = [0, 1, 2, 3, 5, 7, 9, 10, 11, 13, 19, 22]

  if let i = binarySearch_Recursion(A, 7, start: 0, end: A.count - 1) {
      print("element 7의 index: \(i)") // element 7의 index: 5
  } else {
      print("X")
  }
  ```

- **Loop**

  ```swift
  func binarySearch_Loop<T: Comparable>(_ arr: [T], _ target: T, start: Int, end: Int) -> Int?
  {
      var start = start
      var end = end

      while start <= end {
          let middle = (start + end) / 2

          if arr[middle] == target {
              return middle
          } else if arr[middle] < target {
              start = middle + 1
          } else {
              end = middle - 1
          }
      }

      return nil
  }
  ```

  1. 재귀와 비슷하게 해당 값을 비교하고 start와 end 값을 수정 반복으로 찾을 값을 찾아내는 방식
  2. 찾을 값보다 현재 중간값이 작다면 **start = middle + 1**
  3. 찾을 값보다 현재 중간값이 크다면 **end = middle - 1**
  4. 이를 찾을 때까지 반복
     <br/>

  ```swift
  if let i = binarySearch_Loop(A, 7, start: 0, end: A.count - 1) {
      print("element 7의 index: \(i)") //element 7의 index: 5

  } else {
      print("X")
  }
  ```

## Next

- Upper Bound
- lower Bound

## 연습하기 좋은 문제

- [백준 - 10816(숫자 카드2)](https://www.acmicpc.net/problem/10816)

## 참고

- [Wikipedia -이진탐색 알고리즘](https://ko.wikipedia.org/wiki/%EC%9D%B4%EC%A7%84_%EA%B2%80%EC%83%89_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98)

- [블로그 참조 -kwontae1313(이진탐색)](https://velog.io/@kwontae1313/%EC%9D%B4%EC%A7%84-%ED%83%90%EC%83%89Binary-Search-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EA%B0%9C%EB%85%90)

- [블로그 참조 -cobi-98(이진탐색)](https://cobi-98.tistory.com/43#google_vignette)

- [블로그 참조 -개발자소들이(이진탐색)](https://babbab2.tistory.com/104)

- [블로그 참조 -conandevdaily(이진탐색)](https://conandevdaily.tistory.com/47)
