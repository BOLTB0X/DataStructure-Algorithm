# Singly Linked List(단일 연결 리스트)

> 단일 연결 리스트는 각 노드가 다음 노드를 가리키는 방식으로 연결

<div style="text-align: center;">
<img src="https://github.com/BOLTB0X/DataStructure-Algorithm/blob/main/Algorithm/Linked%20List/img/%EB%8B%A8%EC%9D%BC%EB%A7%81%ED%81%AC%EB%93%9C.png?raw=true" alt="Example Image" width="90%">

data를 저장하는 **노드(Node)** 들이 한 줄로 연결된 자료구조

</div>

## 특징

- 노드가 data와 다음 노드를 가리키는 포인터 두가지를 가리키는 형태

- 연속되지 않은 메모리에 저장된 데이터들을 연결시켜 놓은 것

## Node

<div style="text-align: center;">
<img src="https://github.com/BOLTB0X/DataStructure-Algorithm/blob/main/Algorithm/Linked%20List/img/Node.png?raw=true" alt="Example Image" width="90%">

현재 위치 data와 다음 위치 data의 주소값을 가짐

</div>

<br/>

```swift
final class Node<T> {
    var data: T
    var nextNode: Node<T>?

    init(_ data: T, nextNode: Node<T>? = nil) {
        self.data = data
        self.nextNode = nextNode
    }
}
```

- 각 노드는 **데이터(data)** 와 다음 노드를 가리키는 **참조(nextNode)** 를 가지고 있으며, 마지막 노드의 nextNode는 nil을 가리켜 리스트의 끝임을 나타냄
  <br/>

- _cf. Class로 정의한 이유_
  _구조체의 경우 값의 변경에 따라 노드가 다시 복사되어 메모리에 올라오기 때문에 스택 메모리 공간을 많이 사용_
  <br/>

## CRUD

```swift
class SinglyLinkedList<T> {
    var head: Node<T>?
    var tail: Node<T>?

    // 생략
    // ..
}
```

- **Head**

  - Linked List의 첫 번째 노드를 가리키는 포인터 리스트의 시작을 나타내며, 새로운 노드를 추가하거나 data를 검색할 때 가장 먼저 접근하게 되는 위치

  - 모든 노드의 탐색은 이 head에서부터 시작
    <br/>

- **Tail**

  - 연결 리스트의 마지막 노드를 가리킴
  - Tail은 nextNode가 nil인 노드를 의미하며, 리스트의 끝을 나타냄
  - 새로운 노드를 리스트의 끝에 추가할 때, tail을 사용하면 리스트의 끝까지 순회할 필요 없이 빠르게 추가 가눙
    <br/>

- **Append / Insert**
  Node 추가

  ```swift
  func append(_ value: T) {
    let newNode = Node(value)
    if head == nil {  // 1
        head = newNode
        tail = newNode
     } else { // 2
        tail?.nextNode = newNode
        tail = newNode
     }
  }
  ```

  1.  리스트가 비어있으면 head와 tail을 모두 newNode로 설정
  2.  tail을 사용하여 마지막 노드에 직접 접근해 새로운 노드 추가
      <br/>

  ```swift
  func insert(_ value: T, at index: Int) {
     let newNode = Node(value)

     if index == 0 {
        newNode.nextNode = head
        head = newNode
        if tail == nil {
            tail = newNode
        }
        return
    }

    var current = head
    var currentIndex = 0

    while current != nil && currentIndex < index - 1 {
        current = current?.nextNode
        currentIndex += 1
   }

    if current == nil {
        return
    }

    newNode.nextNode = current?.nextNode
    current?.nextNode = newNode

    if newNode.nextNode == nil {
        tail = newNode
    }
  }
  ```

  - **Step 1**: 새로운 노드 생성
    삽입하려는 데이터를 사용해 새로운 노드를 생성, 이 노드는 연결 리스트에 추가 될 노드
    <br/>

  - **Step 2**: 리스트의 시작(head)에 삽입하는 경우(만약 삽입하려는 위치가 0(리스트의 첫 번째 위치))

    1. 새로운 노드를 head의 위치에 추가
    2. 기존의 head를 새로운 노드의 nextNode로 설정하여 리스트가 연결되도록 함
    3. head 포인터를 새로운 노드로 업데이트
    4. 만약 리스트가 비어 있었을 경우, 새로 추가된 노드는 tail로도 설정
       <br/>

  - **Step 3**: 리스트의 중간 또는 끝에 삽입하는 경우(만약 삽입하려는 위치가 리스트의 중간이나 끝)
    1.  삽입 위치 바로 이전 노드를 찾기 위해, currentIndex를 0부터 시작하여 현재 노드(current)가 삽입 위치에 도달할 때까지 순차적으로 리스트를 탐색
    2.  이전 노드의 nextNode를 새로운 노드로 설정하고, 새로운 노드의 nextNode는 기존의 nextNode를 가리키도록 연결
    3.  만약 새로운 노드를 리스트의 마지막에 삽입한 경우, tail 포인터를 새로 삽입한 노드로 업데이트
        <br/>

- **Read**
  특정 위치 노드 탐색

  ```swift
  func read(at index: Int) -> T? {
      var current = head
      var currentIndex = 0

      while current != nil && currentIndex < index {
          current = current?.nextNode
          currentIndex += 1
      }

      return current?.data
  }
  ```

   <br/>

- **Delete**
  노드 삭제

  ```swift
  func delete(at index: Int) {
       if head == nil {
           return
       }

       if index == 0 {
           head = head?.nextNode
           if head == nil {
               tail = nil
           }
           return
       }

       var current = head
       var previous: Node<T>?
       var currentIndex = 0

       while current != nil && currentIndex < index {
           previous = current
           current = current?.nextNode
           currentIndex += 1
       }

       if current != nil {
           previous?.nextNode = current?.nextNode
           if current?.nextNode == nil {
               tail = previous
           }
       }
  }
  ```

  - **Step 1**: 삭제할 위치가 리스트의 시작(head)인 경우(만약 삭제하려는 위치가 0)

    1.  head 포인터를 head?.nextNode로 업데이트, 즉 head가 다음 노드를 가리키게 하여 첫 번째 노드를 삭제
    2.  만약 삭제 후 리스트가 비어 있게 되면(head == nil), tail도 nil로 설정
        <br/>

  - **Step 2**: 리스트의 중간 또는 끝에서 삭제하는 경우
    1.  currentIndex를 0부터 시작하여 삭제할 위치 바로 이전의 노드(previous)를 찾아야 함
    2.  이전 노드의 nextNode를 삭제하려는 노드의 nextNode로 설정하여 삭제 대상 노드를 연결 리스트에서 분리
    3.  만약 삭제할 노드가 리스트의 마지막 노드라면, 삭제 후 tail 포인터를 이전 노드로 업데이트
        <br/>

## 예시

<div style="text-align: center;">
<img src="https://github.com/BOLTB0X/DataStructure-Algorithm/blob/main/Algorithm/Linked%20List/img/%EB%8B%A8%EC%9D%BC%EB%A7%81%ED%81%AC%EB%93%9C%EC%98%88%EC%8B%9C.png?raw=true" alt="Example Image" width="90%">

</div>

<br/>

```swift
let list = SinglyLinkedList<Int>()

list.append(22)
list.append(2)
list.append(77)
list.append(6)
list.append(43)
list.append(76)
list.append(89)

list.printList()
//22 -> 2 -> 77 -> 6 -> 43 -> 76 -> 89 -> nil
```

- 2번째 위치에 15 Insert

  - currentIndex가 2인 위치에서 노드 2을 찾고, 그 노드의 nextNode를 새로운 노드 15로 변경
  - 새로운 노드 15의 nextNode는 기존의 노드 77을 가르킴
    <br/>

  ```swift
  list.insert(15, at: 2)
  list.printList()
  // 22 -> 2 -> 15 -> 77 -> 6 -> 43 -> 76 -> 89 -> nil
  ```

  <br/>

- 5번째 위치 Delete

  - currentIndex가 5인 위치에서 노드 6을 찾고, 그 이전 노드(20)의 nextNode를 노드 43으로 설정

  ```swift
  list.delete(at: 6)
  list.printList()
  //22 -> 2 -> 15 -> 77 -> 6 -> 43 -> 89 -> nil
  ```

- 만약 마지막 위치를 삭제하면?

  - tail이 43으로 업데이트

  ```swift
  list.delete(at: 6)
  list.printList()
  // 22 -> 2 -> 15 -> 77 -> 6 -> 43 -> nil
  ```

## 참고

- [블로그 참조 - 개발자소들이(단일연결리스트)](https://babbab2.tistory.com/86)

- [블로그 참조 - newon(단일연결리스트)](https://velog.io/@newon-seoul/Swift%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-LinkedList-1%ED%8E%B8-Node-%EC%99%80-LinkedList-%EC%97%90-%EC%B6%94%EA%B0%80%ED%95%98%EA%B8%B0)

- [블로그 참조 - leonfather(단일연결리스트)](https://leonfather.tistory.com/38)

- [블로그 참조 - chanos(단일연결리스트)](https://chanos.tistory.com/entry/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-%EB%8B%A8%EB%B0%A9%ED%96%A5-%EC%97%B0%EA%B2%B0%EB%A6%AC%EC%8A%A4%ED%8A%B8Singly-Linked-List%EB%9E%80-%EA%B5%AC%ED%98%84%ED%95%98%EA%B8%B0)
