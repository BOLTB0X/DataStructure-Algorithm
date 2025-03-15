# Two Pointer / Sliding Window

- **Two Pointer**

  > 배열에 순차적으로 접근해야 할 때 두 개의 점의 위치를 기록하면서 처리하는 알고리즘

  - 포인터 2개를 사용해서 탐색 범위를 좁혀가는 방식
  - 정렬된 배열에서 특정 조건을 만족하는 구간을 찾을 때 많이 사용
  - 시간 복잡도: `O(N)` or `O(NlogN)`
    <br/>

- **Sliding Window**

  > 고정된 크기 또는 가변 크기의 윈도우를 사용하여 탐색하는 알고리즘

  - 배열이나 문자열에서 특정 크기의 부분을 확인하며 이동하는 방식
  - **연속된 부분 배열(구간)**을 빠르게 탐색할 때, _최대/최소 합_ , _평균_ , _부분 문자열_ 문제에 자주 사용
  - 시간 복잡도: `O(N)`
    <br/>

## 자주 사용되는 패턴

- "배열이 정렬되어 있고, 두 개의 원소를 비교해야 한다?" -> **Two Pointer**
- "연속된 부분 배열(구간)의 값을 빠르게 구해야 한다?" -> **Sliding Window**

### 합이 특정 값인 두 수 찾기

```swift
func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
    var left = 0
    var right = nums.count - 1

    while left < right {
        let sum = nums[left] + nums[right]

        if sum == target {
            return [left, right]
        } else if sum < target {
            left += 1
        } else {
            right -= 1
        }
    }

    return []
}

print(twoSum([2, 7, 11, 15], 9))
// [0, 1]
```

- 정렬된 배열에서 **왼쪽에서 시작하는 포인터(`left`)** 와 **오른쪽에서 시작하는 포인터(`right`)** 를 이동하면서 구간의 합을 조정

- 시간복잡도: `O(N)`
  <br/>

### 부분 합 문제 (Subarray Sum)

- 윈도우 크기만큼 부분 배열을 확인하고, 윈도우를 한 칸씩 이동하면서 값을 갱신

- 이전 값을 활용하여 중복 연산을 피함

#### 연속된 부분 배열의 합이 K 이상이 되는 최소 구간(= 길이)

```swift
func subArrayMinLength(_ nums: [Int], _ target: Int) -> Int {
    var res: Int = Int.max
    var left = 0, sum = 0

    for right in 0..<nums.count {
        sum += nums[right]

        while sum >= target {
            res = min(res, right - left + 1)
            sum -= nums[left]
            left += 1
        }
    }

    if res == Int.max {
        res = 0
    }

    return res
}

print(subArrayMinLength([2, 3, 1, 2, 4, 3], 7))
// 2 ([4,3])
```

1.  right를 오른쪽으로 이동하면서 부분 합을 구함
2.  조건을 만족하면 left를 이동하여 최소 길이를 찾음

#### 길이 K인 부분 배열의 최대 합 찾기

```swift
func subArrayMaxSum(_ nums: [Int], _ length: Int) -> Int {
    var res: Int = -1
    var tot = nums[0..<length].reduce(0, +)
    res = tot

    for i in length..<nums.count {
        tot += nums[i] - nums[i - length] // 새로운 값 추가, 이전 값 제거
        res = res > tot ? res : tot
    }

    return res
}

```

1. 매번 전체 합을 구하는 대신
2. 앞의 값만 빼고 뒤의 값을 추가함

## 연습문제

- [BOJ-2003(수들의 합 2)](https://www.acmicpc.net/problem/2003)
- [BOJ-2531(회전 초밥)](https://www.acmicpc.net/problem/2531)
- [BOJ-1806(부분합)](https://www.acmicpc.net/problem/1806)
