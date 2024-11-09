# Lower Bound & Upper Bound

> 이진 탐색을 응용한 개념으로 경계값을 찾는 알고리즘

- _배열(Array)_ 이나 _컬렉션(Collection)_ 값이 중복되는 경우나 특정 범위에 있는 값을 찾을 때 유용
  <br/>
- 이진 탐색을 기반으로 하기 때문에 data가 정렬되어 있어야 함

## Lower Bound

> lower bound는 찾고자 하는 값 이상이 처음 나타나는 위치

특정 값의 시작 위치를 찾는 알고리즘

```swift
func lowerBound(_ arr: [Int], _ target: Int) -> Int {
    var start = 0
    var end = arr.count

    while start < end {
        let mid = (start + end) / 2
        if arr[mid] < target {
            start = mid + 1
        } else {
            end = mid
        }
    }

    return start
}
```

- 기본원리

  1. 찾고자 하는 구간을 **[start, end(배열의 길이)]** 로 설정 구간 내의 중간 위치를 **mid**로 설정
  2. **arr[mid] < target** 이면서 **arr[mid] >= target**을 만족하는 최소 mid을 찾기 위해 반복
  3. **start >= end** 가 될 때 반복문이 중지되고 **start**
     <br/>

- 예시
  arr = [1, 2, 2, 2, 3, 5, 7], target = 2

  <div style="text-align: center;">
  <img src="https://github.com/BOLTB0X/DataStructure-Algorithm/blob/main/Algorithm/LowerUpper%20Bound/png/%EB%A1%9C%EC%9A%B0%ED%95%98%EC%9D%B4%EB%B0%94%EC%9A%B4%EB%93%9C1.png?raw=true" alt="Example Image" width="70%">

  <img src="https://github.com/BOLTB0X/DataStructure-Algorithm/blob/main/Algorithm/LowerUpper%20Bound/png/%EB%A1%9C%EC%9A%B0%ED%95%98%EC%9D%B4%EB%B0%94%EC%9A%B4%EB%93%9C2.png?raw=true" alt="Example Image" width="70%">

  <img src="https://github.com/BOLTB0X/DataStructure-Algorithm/blob/main/Algorithm/LowerUpper%20Bound/png/%EB%A1%9C%EC%9A%B0%EB%B0%94%EC%9A%B4%EB%93%9C4.png?raw=true" alt="Example Image" width="70%">

  <img src="https://github.com/BOLTB0X/DataStructure-Algorithm/blob/main/Algorithm/LowerUpper%20Bound/png/%EB%A1%9C%EC%9A%B0%EB%B0%94%EC%9A%B4%EB%93%9C5.png?raw=true" alt="Example Image" width="70%">
  </div>
  <br/>

  ```swift
  print(lowerBound(arr, 2)) // 1
  ```

  <br/>

- 시간복잡도
  ```
  o(logN)
  ```
  <br/>

## Upper Bound

> upper bound는 찾고자 하는 값보다 큰 값이 처음으로 나타나는 위치

특정 값의 초과 값을 시작 위치를 찾는 알고리즘

```swift
func upperBound(_ arr: [Int], _ target: Int) -> Int {
    var start = 0
    var end = arr.count

    while start < end {
        let mid = (start + end) / 2
        if arr[mid] <= target {
            start = mid + 1
        } else {
            end = mid
        }
    }

    return start
}
```

<br/>

- 기본원리

  1. 찾고자 하는 구간을 **[start, end(배열의 길이)]** 로 설정 구간 내의 중간 위치를 **mid**로 설정
  2. **arr[mid-1] <= target** 이면서 **arr[mid] > target**을 만족하는 최소 mid을 찾기 위해 반복
  3. **start >= end** 가 될 때 반복문이 중지되고 **start**
     <br/>

- 예시
  arr = [1, 2, 2, 2, 3, 5, 7], target = 2

    <div style="text-align: center;">
    <img src="https://github.com/BOLTB0X/DataStructure-Algorithm/blob/main/Algorithm/LowerUpper%20Bound/png/%EB%A1%9C%EC%9A%B0%ED%95%98%EC%9D%B4%EB%B0%94%EC%9A%B4%EB%93%9C1.png?raw=true" alt="Example Image" width="70%">

    <img src="https://github.com/BOLTB0X/DataStructure-Algorithm/blob/main/Algorithm/LowerUpper%20Bound/png/%EB%A1%9C%EC%9A%B0%ED%95%98%EC%9D%B4%EB%B0%94%EC%9A%B4%EB%93%9C2.png?raw=true" alt="Example Image" width="70%">

    <img src="https://github.com/BOLTB0X/DataStructure-Algorithm/blob/main/Algorithm/LowerUpper%20Bound/png/%ED%95%98%EC%9D%B4%EB%B0%94%EC%9A%B4%EB%93%9C3.png?raw=true" alt="Example Image" width="70%">

    <img src="https://github.com/BOLTB0X/DataStructure-Algorithm/blob/main/Algorithm/LowerUpper%20Bound/png/%ED%95%98%EC%9D%B4%EB%B0%94%EC%9A%B4%EB%93%9C4.png?raw=true" alt="Example Image" width="70%">
  </div>

  ```swift
  print(upperBound(arr, 2)) // 4
  ```

    <br/>

- 시간복잡도
  ```
  o(logN)
  ```

## Lower Bound와 Upper Bound 에서 Start로 반환?

- **lower bound**: _start는 target 이상인 값이 시작하는 위치를 나타냄_

- **upper bound**: _start는 target을 초과하는 값이 처음으로 나타나는 위치를 나타냄_

- **lower/upper bound**: _end는 마지막 반복에서 start와 같은 값으로 수렴_

마지막에 반환할 때 start와 end는 동일한 값으로 수렴하기 때문에, 아무거나 return 가능

_start를 반환하는 것이 더 일반적_

## 연습문제

- [BOJ-2632](https://www.acmicpc.net/problem/2632)

## 참고

- [블로그 참조 - 12bme(Lower bound, Upper bound)](https://12bme.tistory.com/120)

- [블로그 참조 - linux-studying(Parametric Search, lower, upper Bound / Swift)](https://linux-studying.tistory.com/17)

- [블로그 참조 - hongz-developer(이진탐색 LowerBound, UpperBound 이해하기)](https://hongz-developer.tistory.com/m/172)

- [블로그 참조 - didu-story(10816번 - 숫자카드2)](https://didu-story.tistory.com/m/432)

- [블로그 참조 - yoongrammer(Lower bound & Upper bound 개념 및 구현)](https://yoongrammer.tistory.com/105)
