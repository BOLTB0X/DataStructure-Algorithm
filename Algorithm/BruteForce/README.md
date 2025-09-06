# 완전탐색

> **Problem Solving** 를 위해 모든 가능한 경우의 수를 체계적으로 탐색하여 최적의 해를 찾는 알고리즘인 **완전탐색(Brute Force)** 을 적용하는 것


- 말 그대로 모든 경우의 수를 다 탐색하는 방법

- 가능한 모든 조합/순열/상황을 전부 확인 -> 답을 보장하지만 비효율적일 수 있음

---


## Ex01) [BOJ 2798 블랙잭](https://www.acmicpc.net/problem/2798)

<details markdown="1">
<summary>info</summary>


### 문제

*카지노에서 제일 인기 있는 게임 블랙잭의 규칙은 상당히 쉽다. 카드의 합이 `21`을 넘지 않는 한도 내에서, 카드의 합을 최대한 크게 만드는 게임이다. 블랙잭은 카지노마다 다양한 규정이 있다.*

*한국 최고의 블랙잭 고수 김정인은 새로운 블랙잭 규칙을 만들어 상근, 창영이와 게임하려고 한다.*

*김정인 버전의 블랙잭에서 각 카드에는 양의 정수가 쓰여 있다. 그 다음, 딜러는 `N`장의 카드를 모두 숫자가 보이도록 바닥에 놓는다. 그런 후에 딜러는 숫자 `M`을 크게 외친다.*

*이제 플레이어는 제한된 시간 안에 `N`장의 카드 중에서 `3`장의 카드를 골라야 한다. 블랙잭 변형 게임이기 때문에, 플레이어가 고른 카드의 합은 `M`을 넘지 않으면서 `M`과 최대한 가깝게 만들어야 한다.*

*`N`장의 카드에 써져 있는 숫자가 주어졌을 때, `M`을 넘지 않으면서 `M`에 **최대한 가까운 카드 3장의 합** 을 구해 출력하시오.*

### 입력

*첫째 줄에 카드의 개수 `N(3 ≤ N ≤ 100)`과 `M(10 ≤ M ≤ 300,000)`이 주어진다. 둘째 줄에는 카드에 쓰여 있는 수가 주어지며, 이 값은 `100,000`을 넘지 않는 양의 정수이다.*

*합이 `M`을 넘지 않는 카드 `3`장을 찾을 수 있는 경우만 입력으로 주어진다.*

### 출력

*첫째 줄에 `M`을 넘지 않으면서 `M`에 최대한 가까운 카드 3장의 합을 출력한다.*


### 예시 입출력

| 항목        | 값                         |
|-------------|----------------------------|
| 입력 1(`N`, `M`, `cards`)      | 5, 21, [5, 6, 7, 8, 9]                    |
| 출력 1      | 21                          |

| 항목        | 값                         |
|-------------|----------------------------|
| 입력 2(`N`, `M`, `cards`)      | 10, 500, [93, 181, 245, 214, 315, 36, 185, 138, 216, 295]                  |
| 출력 2      | 497                          |


---

</details>

- 입력값 `N` 의 최대가 100, 2중, 3중으로 **완전탐색** ,  **백트래킹** 을 진행 상관 X

- 배열에서 3 개를 뽑아서 `M` 미만 값 중 최댓값을 찾는 것이 관건

<details markdown="1">
<summary>code</summary>

```swift
import Foundation

let NM = readLine()!.split(separator: " ").map { Int($0)! }
let cards = readLine()!.split(separator: " ").map { Int($0)! }

print(solution(NM[0], NM[1], cards))

func solution(_ N: Int, _ M: Int, _ cards: [Int]) -> Int {
  var answer: Int = 0

  for i in 0..<N {
    for j in i+1..<N {
      for k in j+1..<N {
        if cards[i]+cards[j]+cards[k] <= M {
          answer = max(answer, cards[i]+cards[j]+cards[k])
        }
      }
    }
  }

  return answer
}
```

```cpp
#include <iostream>

using namespace std;

int N, M;
int cards[101];

int mx(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int answer = 0;

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> cards[i];
    }

    for (int i = 0; i < N-2; ++i) 
    {
        for (int j = i+1; j < N-1; ++j) 
        {
            for (int k = j+1; k < N; ++k) 
            {
                if (cards[i]+cards[j]+cards[k] <= M)
                {
                    answer = mx(answer, cards[i]+cards[j]+cards[k]);
                }
            }
        }
    }

    cout << answer;

    return 0;
}
```

</details>

---

### Ex02) [Programmers 모의고사](https://school.programmers.co.kr/learn/courses/30/lessons/42840)

<details markdown="1">
<summary>info</summary>

### 문제 설명

*수포자는 수학을 포기한 사람의 준말입니다. 수포자 삼인방은 모의고사에 수학 문제를 전부 찍으려 합니다. 수포자는 1번 문제부터 마지막 문제까지 다음과 같이 찍습니다.*

*1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...*

*2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...*

*3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...*


*1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열 `answers`가 주어졌을 때, 가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 `return` 하도록 `solution` 함수를 작성해주세요.*


### 제한 조건

- *시험은 최대 `10,000` 문제로 구성되어있습니다.*

- *문제의 정답은 `1`, `2`, `3`, `4`, `5` 중 하나입니다.*

- *가장 높은 점수를 받은 사람이 여럿일 경우, `return`하는 값을 오름차순 정렬해주세요.*

### 예시 입출력

| 항목        | 값                         |
|-------------|----------------------------|
| 입력 1(`answers`)      | [1,2,3,4,5]                    |
| 출력 1      | [1]                          |

| 항목        | 값                         |
|-------------|----------------------------|
| 입력 2(`answers`)      | [1,3,2,4,2]                |
| 출력 2      | [1, 2, 3]                          |


---

</details>

- **패턴 탐색**

- 각 수포자들의 패턴을 확인 후, 하나씩 확인

<details markdown="1">
<summary>code</summary>

```cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> score(3, 0);
    const int supoja1[5] = {1, 2, 3, 4, 5};
    const int supoja2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    const int supoja3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for (int i = 0; i < answers.size(); ++i) {
        if (supoja1[i % 5] == answers[i])
            score[0]++;
        if (supoja2[i % 8] == answers[i])
            score[1]++;
        if (supoja3[i % 10] == answers[i])
            score[2]++;
    }
    
    int maxVal = *max_element(score.begin(), score.end());
    
    for (int i = 0; i < 3; ++i) {
        if (maxVal == score[i])
            answer.push_back(i + 1);
    }
    
    return answer;
}
```

```swift
import Foundation

func solution(_ answers:[Int]) -> [Int] {
    var answer:[Int] = []
    let supoja1:[Int] = [1,2,3,4,5]
    let supoja2:[Int] = [2,1,2,3,2,4,2,5]
    let supoja3:[Int] = [3,3,1,1,2,2,4,4,5,5]
    
    var totalAns:[Int] = [0,0,0]
    
    for i in answers.enumerated() {
        if i.1 == supoja1[i.0 % supoja1.count] {
            totalAns[0] += 1
        }

        if i.1 == supoja2[i.0 % supoja2.count] {
            totalAns[1] += 1
        }

        if i.1 == supoja3[i.0 % supoja3.count] {
            totalAns[2] += 1
        }
    }
    
    let maxValue = totalAns.max()
    
    for i in 0..<3 {
        if totalAns[i] == totalAns.max() {
            answer.append(i + 1)
        }
    }
    
    return answer
}
```

</details>

## 문제 List

### 정형화

- [BOJ 2231 – 분해합](https://www.acmicpc.net/problem/2231)

- [BOJ 7568 – 덩치](https://www.acmicpc.net/problem/7568)

- [BOJ 1018 - 체스판 다시 칠하기](https://www.acmicpc.net/problem/1018)

- [Programmers - 피로도](https://school.programmers.co.kr/learn/courses/30/lessons/87946)

---

### 응용

- [BOJ 1436 - 영화감독 숌](https://www.acmicpc.net/problem/1436)

- [BOJ 6064 – 카잉 달력](https://www.acmicpc.net/problem/6064)

- [Programmers - 도넛과 막대 그래프](https://school.programmers.co.kr/learn/courses/30/lessons/258711)

- [LeetCode 78 - Subsets](https://leetcode.com/problems/subsets/description/)


---

### 실전

- [Programmers - 전력망을 둘로 나누기](https://school.programmers.co.kr/learn/courses/30/lessons/86971)

- [BOJ 16637 - 괄호 추가하기](https://www.acmicpc.net/problem/16637)

- [BOJ 14502 – 연구소](https://www.acmicpc.net/problem/14502)

- [Programmers - 거리두기 확인하기](https://school.programmers.co.kr/learn/courses/30/lessons/81302/)

---