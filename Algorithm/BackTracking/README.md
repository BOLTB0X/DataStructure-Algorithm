# Backtracking

```swift
func backtrack(현재 상태):
    if 종료 조건 만족:
        결과 처리
        return
    
    for 선택지 in 가능한 선택들:
        현재 상태에 선택 적용
        backtrack(업데이트된 상태)
        현재 상태 원상 복구 (되돌리기)
```

- 일명 **가지치기** , 조건을 붙여서 전부 탐색하지 않는 효율성 추가하는 것

- **종료 조건** ,**조건문** 을 어떻게 하는 지가 중요


## Ex01) [BOJ 15649 - N과 M 1](https://www.acmicpc.net/problem/15649)

<details markdown="1">
<summary>info</summary>

### 문제

*자연수 `N`과 `M`이 주어졌을 때, 아래 조건을 만족하는 길이가 `M`인 수열을 모두 구하는 프로그램을 작성하시오.*

- *`1`부터 `N`까지 자연수 중에서 중복 없이 `M`개를 고른 수열*

### 입력

*첫째 줄에 자연수 `N`과 `M`이 주어진다. `(1 ≤ M ≤ N ≤ 8)`*

### 출력

*한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.*

*수열은 사전 순으로 증가하는 순서로 출력해야 한다.*

### 예시 입출력

- 예제 입출력 1

   ```
   // 입력
   3 1
   ```

   ```
   // 출력
   1
   2
   3
   ```


- 예제 입출력 2

   ```
   // 입력
   4 2
   ```

   ```
   // 출력
   1 2
   2 3
   1 4
   2 1
   2 3
   2 4
   3 1
   3 2
   3 4
   4 1
   4 2
   4 3
   ```

</details>

순열 코드 작성, 만약 중복순열일 경우, 방문리스크 사용 X

<details markdown="1">
<summary>code</summary>

```cpp
#include <iostream>
#include <vector>

using namespace std;

vector<int> per;
bool visited[9] = { false, };

//백트래킹 
void DFS(int n, int m, int depth) {
	if (depth == m) {
		for (int i = 0; i < per.size(); i++) {
			cout << per[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i])
			continue;
		visited[i] = true;
		per.push_back(i);
		DFS(n, m, depth + 1);
		per.pop_back();
		visited[i] = false;
	}
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;

	cin >> n >> m;
	DFS(n, m, 0);
	return 0;
}
```

```swift
let inputArr = readLine()!.split { $0 == " " }.map { Int($0)! }

let N = inputArr[0]
let M = inputArr[1]

permutation(arr: Array(1...N), N: N, M: M)

func permutation(arr: [Int], N: Int, M: Int) {
    var perArr: [[Int]] = []
    var visited = [Bool](repeating: false, count: N)
    
    func DFS(per: [Int]) {
        if per.count == M {
            perArr.append(per)
            return
        }
        
        for i in 0..<arr.count {
            if !visited[i] {
                visited[i] = true
                DFS(per: per + [arr[i]])
                visited[i] = false
            }
        }
    }
    
    DFS(per: [])
    
    for per in perArr {
        for p in per {
            print(p, terminator: " ")
        }
        print()
    }
    
    return
}
```

</details>

---

## Ex02) [BOJ 15650 - N과 M 2](https://www.acmicpc.net/problem/15650)

<details markdown="1">
<summary>info</summary>

### 문제

*자연수 `N`과 `M`이 주어졌을 때, 아래 조건을 만족하는 길이가 `M`인 수열을 모두 구하는 프로그램을 작성하시오.*

*`1`부터 `N`까지 자연수 중에서 중복 없이 `M`개를 고른 수열
고른 수열은 오름차순이어야 한다.*

### 입력

*첫째 줄에 자연수 `N`과 `M`이 주어진다. `(1 ≤ M ≤ N ≤ 8)`*

### 출력

*한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.*

*수열은 사전 순으로 증가하는 순서로 출력해야 한다.*

### 예시 입출력

- 예제 입출력 1

   ```
   // 입력
   3 1
   ```

   ```
   // 출력
   1
   2
   3
   ```


- 예제 입출력 2

   ```
   // 입력
   4 2
   ```

   ```
   // 출력
   1 2
   1 3
   1 4
   2 3
   2 4
   3 4
   ```

</details>


<details markdown="1">
<summary>code</summary>

```swift
import Foundation

let inputArr = readLine()!.split { $0 == " " }.map { Int($0)! }

let N = inputArr[0]
let M = inputArr[1]

combination(arr: Array(1...N), N: N, M: M)

func combination(arr: [Int], N: Int, M: Int) {
    var comArr: [[Int]] = []
    
    func DFS(com: [Int], cur: Int) {
        if com.count == M {
            comArr.append(com)
            return
        }
        
        for i in cur..<arr.count {
            DFS(com: com + [arr[i]], cur: i+1)
        }
    }
    
    DFS(com: [], cur: 0)
    
    for com in comArr {
        for c in com {
            print(c, terminator: " ")
        }
        print()
    }
    
    return
}
```

```cpp
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> totalCom;
vector<bool> visited;
void combination(vector<int> com, int n, int r, int cur, int depth);

int main()
{
    int n, r;

    cin >> n >> r;
    visited = vector<bool>(n, false);
    combination({}, n, r, 0, 0);
    
    for (const vector<int> com: totalCom) {
        for (const int ele: com) {
            cout << ele << ' ';
        }
        cout << '\n';
    }
    return 0;
}

void combination(vector<int> com, int n, int r, int cur, int depth) {
    if (depth == r) {
        totalCom.push_back(com);
        return;
    }

    for (int i = cur; i < n; ++i) {
        if (visited[i]) continue;

        visited[i] = true;
        com.push_back(i + 1);
        combination(com, n, r, i + 1, depth + 1);
        com.pop_back();
        visited[i] = false;
    }
}
```

</details>

---



## 문제 List

### 정형화

- [BOJ 1182 - 부분수열의 합](https://www.acmicpc.net/problem/1182)

- [BOJ 14888 - 연산자 끼워넣기](https://www.acmicpc.net/problem/14888)

- [BOJ 9663 – N-Queen](https://www.acmicpc.net/problem/9663)

- [Programmers – 소수 찾기](https://school.programmers.co.kr/learn/courses/30/lessons/42839)

---

### 응용

- [BOJ 2661 - 좋은 수열](https://www.acmicpc.net/problem/2661)

- [LeetCode 39 - Combination Sum](https://leetcode.com/problems/combination-sum/description/)

- [BOJ 15686 - 치킨배달](https://www.acmicpc.net/problem/15686)

- [LeetCode 78 - Subsets](https://leetcode.com/problems/subsets/description/)

---

### 실전

- [Programmers - 메뉴 리뉴얼](https://school.programmers.co.kr/learn/courses/30/lessons/72411)

- [Programmers - 주사위 고르기](https://school.programmers.co.kr/learn/courses/30/lessons/258709)

- [BOJ 1941 - 소문난 칠공주](https://www.acmicpc.net/problem/1941)

- [Programmers - 양궁대회](https://school.programmers.co.kr/learn/courses/30/lessons/92342)


---