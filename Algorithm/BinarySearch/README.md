# Binary Search(이진 탐색)

> 정렬되어 있는 data에서 특정한 값을 찾아내는 알고리즘

- 이분 탐색이라고도 불리며 Binary Search(이진 탐색)은 탐색 범위를 반으로 나누어 찾는 값을 포함하는 범위를 좁혀가는 방식

- Binary Search(이진 탐색)은 data를 반씩 줄여가며 탐색하기 때문에 시간 복잡도가 매우 낮음

---

## 기본 원리

- 전제 조건
  이진 탐색은 **오름차순** 또는 **내림차순** 으로 정렬된 _배열(Array)_ 이나 _컬렉션(Collection)_ 에서만 사용 가능

  ---

- 탐색 방법
  1.  배열의 중간값을 선택

  2.  찾고자 하는 값이 중간값(middle)과 같은지 확인

  3.  찾고자 하는 값이 중간값(middle)보다 크다면, 중간값(middle)의 오른쪽 절반에서 탐색을 계속 진행

  4.  찾고자 하는 값이 중간값(middle)보다 작다면, 중간값(middle)의 왼쪽 절반에서 탐색을 계속 진행

  5.  이 과정을 반복하여 값을 찾거나, 값이 없음을 확인

---

## 시간복잡도

```
O(log N)
```

실행할수록 탐색 범위가 절반씩 줄어들기 때문에, 데이터의 양이 많아질수록 상대적으로 빠르게 탐색 가능

---

## 예시 in 배열

<details>
<summary>접기/펼치기</summary>

_배열 A = [0, 1, 2, 3, 5, 7, 9, 10, 11, 13, 19, 22]에서 숫자 7을 찾는 경우_

- **Recursion**

  ```cpp
  int binary_Search(vector<int> arr, int target, int start, int end)
  {
      if (start > end)
          return -1;

      int mid = (start + end) / 2;

      if (arr[mid] == target)
          return mid;

      if (arr[mid] > target)
          return binary_Search(arr, target, start, mid - 1);
    
      return binary_Search(arr, target, mid + 1, end);
  }
  ```

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

  1. 배열의 중간값 -> 9, 그러므로 **9 > 7**이므로 왼쪽 절반 `[0, 1, 2, 3, 5, 7]` 에서 탐색을 계속 진행

  2. 왼쪽 절반의 중간값 -> 2, **2 < 7**이므로 오른쪽 절반 `[3, 5, 7]`에서 탐색을 계속 진행

  3. 중간 값은 5, **5 < 7** 이번에도 오른쪽을 자르면 7 하나만 element로 있으며 해당 값을 찾을 수 있음

  ---

  ```swift
  let A = [0, 1, 2, 3, 5, 7, 9, 10, 11, 13, 19, 22]

  if let i = binarySearch_Recursion(A, 7, start: 0, end: A.count - 1) {
      print("element 7의 index: \(i)") // element 7의 index: 5
  } else {
      print("X")
  }
  ```

  ---

- **Loop**

  ```cpp
  int binary_Search(vector<int> arr, int target)
  {
      int start = 0, end = arr.size() - 1, mid = 0;
    
      while (start <= end)
      {
          mid = (start + end) / 2;

          if (arr[mid] == target)
              break;

          if (arr[mid] > target)
              end = mid - 1;
          else if (arr[mid] < target)
              start = mid + 1;
      }

      return mid;
  }
  ```

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
  
     ---

  ```swift
  if let i = binarySearch_Loop(A, 7, start: 0, end: A.count - 1) {
      print("element 7의 index: \(i)") //element 7의 index: 5

  } else {
      print("X")
  }
  ```

</details>


---

## C++ STL 이용 - `binary_search()` 함수

있다면 `true` , 없다면 `false` 반환

- **parameter**

   - 찾고자 하는 범위의 시작점
   
   - 찾고자 하는 범위의 끝점

   - 칮고자하는 값

   ---

- **Code**

   ```cpp
   cout << binary_search(arr.begin(), arr.end(), 11) << '\n';
   ```

   ---


## Next

### [Lower/Upper Bound](https://github.com/BOLTB0X/DataStructure-Algorithm/blob/main/Algorithm/LowerUpper%20Bound/README.md)

> 정렬된 배열 안에서 특정 값의 위치를 찾는 것


<details>
<summary>접기/펼치기</summary>

- **Lower Bound**

    - `target` 이상이 처음 등장하는 인덱스 반환

    - 배열에서 `target` 미만(`< target`)인 원소 개수

    ---

- **Upper Bound**

    - `target` 초과(`> target`)가 처음 등장하는 인덱스

    - 배열에서 `target` 이하(`≤ target`)인 원소 개수

    ---

- **응용**

    - 배열 안에 특정 값 `target` 이 몇 개인지

        ```
        count(target) = upperBound(target) - lowerBound(target)
        ```

        --- 

    - 배열 안에 `target` 이상 값의 개수

        ```
        >= target 개수 = n - lowerBound(target)
        ```

        --- 

    - 배열 안에 `target` 초과 값의 개수

        ```
        >= target 개수 = n - upperBound(target)
        ```

        --- 

</details>


---

### [Parametric Search](https://github.com/BOLTB0X/DataStructure-Algorithm/blob/main/Algorithm/Parametric%20Search/README.md)


> 파라메트릭 문제는 보통 **“조건을 만족하는 어떤 값의 최댓값/최솟값을 구해라”** 가 관건

`start` = **“답의 최소 가능값”** , `end` = **“답의 최대 가능값**

<details>
<summary>접기/펼치기</summary>

1. 이분 탐색 대상이 **“길이”** 일 때

    *ex.)* [BOJ 2805 - 나무자르기](https://www.acmicpc.net/problem/2805) , [BOJ 1654 - 랜선 자르기](https://www.acmicpc.net/problem/1654)

    - 답은 **“자를 길이”** 

    - 최소: 1 (길이는 0이 될 수 없음)

    - 최대: 입력값 중 최대 길이

    -> 구간: `[1, max(arr)]`

    ---

2. 이분 탐색 대상이 **“값/크기”** 일 때

    *ex.)* [BOJ 2512 - 예산](https://www.acmicpc.net/problem/2512)

    - 답은 **“상한 금액”**

    - 최소: 0 (예산 0일 수도 있음)

    - 최대: 요청 예산의 최댓값

    -> 구간: `[0, max(requests)]`

    ---

3. 이분 탐색 대상이 **“시간/일수”** 일 때

    *ex.)* [BOJ 2343 - 기타 레슨](https://www.acmicpc.net/problem/2343) , [BOJ 6236 - 용돈 관리](https://www.acmicpc.net/problem/6236)


    - 답은 **“필요한 일수/용량/시간”**

    - 최소: max(한 요소) (최소한 가장 큰 단위는 감당해야 함)

    - 최대: 전체 합 (모두 한 번에 처리하는 경우)

    -> 구간: `[max(arr), sum(arr)]`

    ---

- **길이 문제** : `[1, max]`

- **상한/값 문제** : `[0, max]`

- **시간/용량 문제** : `[max(arr), sum(arr)]`


</details>

---


## 문제 List

### 정형화

- [BOJ 10816 - 숫자 카드 2](https://www.acmicpc.net/problem/10816)

- [BOJ 1654 - 랜선 자르기](https://www.acmicpc.net/problem/1654)

- [BOJ 6236 - 용돈 관리](https://www.acmicpc.net/problem/6236)

- [Programmers - 징검다리 건너기](https://school.programmers.co.kr/learn/courses/30/lessons/64062)

---

### 응용

- [BOJ 12015 - 가장 긴 증가하는 부분 수열 2](https://www.acmicpc.net/problem/12015)

- [Leetcode 33 - Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/description/)

- [Leetcode 162 - Find Peak Element](https://leetcode.com/problems/find-peak-element/description/)

- [Programmers - 입국심사](https://school.programmers.co.kr/learn/courses/30/lessons/43238)

---

### 실전

- [BOJ 2632 - 피자판대](https://www.acmicpc.net/problem/2632)

- [BOJ 2110 - 공유기 설치](https://www.acmicpc.net/problem/2110)

- [Programmers - 가사 검색](https://school.programmers.co.kr/learn/courses/30/lessons/60060)

---

## 참고

- [Wikipedia -이진탐색 알고리즘](https://ko.wikipedia.org/wiki/%EC%9D%B4%EC%A7%84_%EA%B2%80%EC%83%89_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98)

- [블로그 참조 -kwontae1313(이진탐색)](https://velog.io/@kwontae1313/%EC%9D%B4%EC%A7%84-%ED%83%90%EC%83%89Binary-Search-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EA%B0%9C%EB%85%90)

- [블로그 참조 -cobi-98(이진탐색)](https://cobi-98.tistory.com/43#google_vignette)

- [블로그 참조 -개발자소들이(이진탐색)](https://babbab2.tistory.com/104)

- [블로그 참조 -conandevdaily(이진탐색)](https://conandevdaily.tistory.com/47)
