# Queue

> First In First Out

선입선출 구조를 따르는 자료구조, 먼저 들어온 data가 먼저 나가는 구조

```swift
struct Queue<T> {
    private var queue: [T] = []

    public var count: Int {
        return queue.count
    }

    public var isEmpty: Bool {
        return queue.isEmpty
    }

    public mutating func enqueue(_ element: T) {
        queue.append(element)
    }

    public mutating func dequeue() -> T? {
        guard !queue.isEmpty else { return nil }
        return queue.removeFirst()
    }

    mutating func peek() -> T? {
        return queue.first
    }
}
```

## 주요 연산

```swift
// 예시
var queue = Queue<Int>()
```

1. **Enqueue**:
   queue의 맨 뒤에 data를 추가하는 연산

   ```swift
   queue.enqueue(1)
   queue.enqueue(2)
   queue.enqueue(3)
   queue.enqueue(4)
   queue.enqueue(5)
   ```

   <br/>

2. **Dequeue**:
   queue의 맨 앞에 있는 data를 제거하고 return하는 연산

   ```swift
   print(queue.dequeue() ?? -1)
   // 1
   ```

   <br/>

3. **Peek/Front**:
   queue의 맨 앞에 있는 data를 제거하지 않고 return하는 연산

   ```swift
   print(queue.peek() ?? -1)
   // 2
   ```

   <br/>

4. **count**:
   queue 안에 data 갯수, stack의 길이

   ```swift
   print(queue.count)
   // 4
   ```

   <br/>

5. **isEmpty**:
   queue가 비어 있는지 확인하는 연산

   ```swift
   print(queue.isEmpty)
   // false
   ```

   <br/>

## 연습하기 좋은 문제

- [프로그래머스 - 고득점 kit(프로세스)](https://school.programmers.co.kr/learn/courses/30/lessons/42587)

- [백준 - 1158(요세푸스 문제)](https://www.acmicpc.net/problem/1158)

- [백준 - 5430(AC)](https://www.acmicpc.net/problem/5430)

- [백준 - 2164(카드2)](https://www.acmicpc.net/problem/2164)

## 참고

- [블로그 참조 -개발자소들이(Queue)](https://babbab2.tistory.com/84)
