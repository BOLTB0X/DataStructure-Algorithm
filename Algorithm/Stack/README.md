# Stack

> LIFO, Last In First Out

후입선출 구조를 가진 자료구조, 가장 나중에 추가된 data가 가장 먼저 제거되는 방식

```swift
struct Stack<T> {
    private var stack: [T] = []

    public var count: Int {
        return stack.count
    }

    public var isEmpty: Bool {
        return stack.isEmpty
    }

    public mutating func push(_ element: T) {
        stack.append(element)
    }

    public mutating func pop() -> T? {
        return stack.popLast()
    }

    public mutating func peek() -> T? {
        return stack.last
    }
}
```

## 주요 연산

```swift
// 예시
var stack = Stack<Int>()
```

1. **Push**:
   stack의 하단에 data를 추가하는 연산

   ```swift
   stack.push(0)
   stack.push(1)
   stack.push(2)
   stack.push(3)
   stack.push(4)
   ```

   <br/>

2. **Pop**:
   stack의 히단에서 data를 제거하고 반환하는 연산

   ```swift
   print(stack.pop() ?? -1)
   // 4
   ```

   <br/>

3. **Peek/Top**:
   stack의 맨 위에 있는 data를 제거하지 않고 반환하는 연산

   ```swift
   print(stack.peek() ?? -1 )
   // 3
   ```

   <br/>

4. **count**:
   stack 안에 data 갯수, stack의 길이

   ```swift
   print(stack.count)
   // 4
   ```

   <br/>

5. **isEmpty**:
   stack이 비어 있는지 확인하는 연산
   ```swift
   print(stack.isEmpty)
   //false
   ```
   <br/>

## 연습하기 좋은 문제

- [프로그래머스 - 고득점 kit(기능개발)](https://school.programmers.co.kr/learn/courses/30/lessons/42586)

- [백준 - 10799(쇠막대기)](https://www.acmicpc.net/problem/10799)

- [백준 - 1918(후위 표기식)](https://www.acmicpc.net/problem/1918)

- [백준 - 1874(스택 수열)](https://www.acmicpc.net/problem/1874)

- [백준 - 6198(옥상 정원 꾸미기)](https://www.acmicpc.net/problem/6198)

## 참고

- [블로그 참조 -개발자소들이(Stack)](https://babbab2.tistory.com/85)
