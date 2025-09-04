# Greedy

> 최적의 해를 구하는 데에 사용되는 근사적인 방법

- **최적의 값** 을 구해야 하는 상황에서 사용되는 근시안적인 방법론으로, **‘각 단계에서 최적이라고 생각되는 것을 선택’** 해 나가는 방식으로 진행하여 최종적인 해답에 도달하는 알고리즘

- 이때, 항상 최적의 값을 보장하는것이 아니라 최적의 값의 **근사한 값** 을 목표로 함

- 주로 문제를 분할 가능한 문제들로 분할한 뒤, 각 문제들에 대한 최적해를 구한 뒤 이를 결합하여 전체 문제의 최적해를 구하는 경우에 주로 사용됩

---

## Ex01) [BOJ 11047 동전 0](https://www.acmicpc.net/problem/11047?utm_source=chatgpt.com)

<details markdown="1">
<summary>info</summary>


### 문제

*준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.*

*동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.*

### 입력

*첫째 줄에 `N`과 `K`가 주어진다. (`1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000`)*

*둘째 줄부터 `N`개의 줄에 동전의 가치 `Ai`가 오름차순으로 주어진다. (`1 ≤ Ai ≤ 1,000,000, A1 = 1`, `i ≥ 2`인 경우에 `Ai`는 `Ai-1`의 배수)*

### 출력

첫째 줄에 `K`원을 만드는데 필요한 동전 개수의 최솟값을 출력한다.


### 예시 입출력

| 항목        | 값                         |
|-------------|----------------------------|
| 입력 1(`N`, `K`, `coins`)      | 10, 4200, [1, 5, 10, 50, 100, 500, 1000, 5000, 10000, 50000]                    |
| 출력 1      | 6                          |

| 항목        | 값                         |
|-------------|----------------------------|
| 입력 2(`N`, `K`, `coins`)      | 10, 4790, [1, 5, 10, 50, 100, 500, 1000, 5000, 10000, 50000]                  |
| 출력 2      | 12                          |


---

</details>

**배수 관계이므로 큰 단위를 먼저 쓰는 게 항상 최적**

<details markdown="1">
<summary>code</summary>

```cpp
#include <iostream>
#define LL long long

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    LL K, coins[11], answer = 0;

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        cin >> coins[i];
    }

    for (int i = N-1; i>=0; --i)
    {
        answer += (K / coins[i]);
        K %= coins[i];
    }

    cout << answer;
    return 0;
}
```

```swift
import Foundation

let inputArr = readLine()!.split(separator: " ").map { Int(String($0))!}

var N = inputArr[0]
var K = inputArr[1]
var coins: [Int] = []
var answer:Int = 0

for coin in 0..<N {
    let coin = Int(readLine()!)!
    coins.append(coin)
}

for coin in coins.reversed() {
    answer += (K / coin)
    K %= coin
}

print(answer)
```

</details>


---

## Ex02) [BOJ 1931 회의실 배정](https://www.acmicpc.net/problem/1931)

<details markdown="1">
<summary>info</summary>

### 문제

*한 개의 회의실이 있는데 이를 사용하고자 하는 `N`개의 회의에 대하여 회의실 사용표를 만들려고 한다.*

*각 회의 `I`에 대해 시작시간과 끝나는 시간이 주어져 있고, 각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 회의의 최대 개수를 찾아보자.*

*단, 회의는 한번 시작하면 중간에 중단될 수 없으며 한 회의가 끝나는 것과 동시에 다음 회의가 시작될 수 있다.*

*회의의 시작시간과 끝나는 시간이 같을 수도 있다. 이 경우에는 시작하자마자 끝나는 것으로 생각하면 된다.*

### 입력

*첫째 줄에 회의의 수 `N(1 ≤ N ≤ 100,000)` 이 주어진다.*

*둘째 줄부터 `N+1` 줄까지 각 회의의 정보가 주어지는데 이것은 공백을 사이에 두고 회의의 시작시간과 끝나는 시간이 주어진다.*

*시작 시간과 끝나는 시간은 `231-1`보다 작거나 같은 자연수 또는 `0`이다.*

### 출력

*첫째 줄에 최대 사용할 수 있는 회의의 최대 개수를 출력한다.*

### 예시 입출력

| 항목        | 값                         |
|-------------|----------------------------|
| 입력 1(`N`, `rooms`)      | 11, [[1, 4], [3, 5], [0, 6], [5 7], [3 8], [5, 9], [6, 10], [8, 11], [8, 12], [2, 13], [12, 14]]                   |
| 출력 1      | 4                          |


---

</details>


한 회의가 차지하는 시간은 다양 -> 무작정 짧은 회의를 고르면 안 됨.

**종료 시간이 빠른 회의부터 선택해야 다음 회의를 최대한 많이 배정 가능**

<details markdown="1">
<summary>code</summary>

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int,int> a, const pair<int,int> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int solution(int N, vector<pair<int,int>> rooms) {
    int answer = 1;
    int cmp = 0;

    sort(rooms.begin(), rooms.end(), compare);
    cmp = rooms.front().second; // 끝나는 시간
    for (int i= 1; i < rooms.size(); ++i)
    {
        if (cmp <= rooms[i].first)
        {
            cmp = rooms[i].second;
            answer++;
        }
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    vector<pair<int,int>> rooms;

    cin >> N;
    rooms = vector<pair<int,int>> (N);

    for (int i = 0; i < N; ++i)
    {
        cin >> rooms[i].first >> rooms[i].second;
    }

    cout << solution(N, rooms);

    return 0;
}
```

```swift
import Foundation

let N = Int(readLine()!)!
var arr:[[Int]] = []

for _ in 0..<N {
  let input = readLine()!.split(separator: " ").map{Int(String($0))!}
  arr.append(input)
}

print(solution(N, arr))

func solution(_ N: Int, _ rooms: [[Int]]) -> Int {
  var answer = 0
  let rooms = rooms.sorted {
      if $0[1] == $1[1] {
        return $0[0] < $1[0]
      }
    return $0[1] < $1[1]
  }

  var curEndTime = rooms[0][1]
  answer += 1
  
  for i in 1..<N {
    if rooms[i][0] >= curEndTime {
      answer += 1
      curEndTime = rooms[i][1]
    }
  }
  
  return answer
}
```

</details>

---

## 문제 List

### 정형화

- [BOJ 11399 – ATM](https://www.acmicpc.net/problem/11399)

- [BOJ 1541 – 잃어버린 괄호](https://www.acmicpc.net/problem/1541)

- [BOJ 11501 - 주식](https://www.acmicpc.net/problem/11501)

- [Programmers - 체육복](https://school.programmers.co.kr/learn/courses/30/lessons/42862)

---

### 응용

- [BOJ 13305 – 주유소](https://www.acmicpc.net/problem/13305)

- [BOJ 1789 – 수들의 합](https://www.acmicpc.net/problem/1789)

- [Programmers – 구명보트](https://school.programmers.co.kr/learn/courses/30/lessons/42885)

---

### 실전

- [BOJ 1700 – 멀티탭 스케줄링](https://www.acmicpc.net/problem/1700)

- [Programmers - 큰 수 만들기](https://school.programmers.co.kr/learn/courses/30/lessons/42883)

- [Leetcode - Candy](https://leetcode.com/problems/candy/description/?utm_source=chatgpt.com)

---