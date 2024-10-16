# Linked List(연결리스트)

> 각 노드가 데이터와 포인터를 가지고 한 줄로 연결되어 있는 방식으로 데이터를 저장하는 자료구조

- Linked List는 배열과 유사하지만, 연속된 공간에 메모리를 차지하고 인덱스를 통해 상수시간 내에 값을 처리한다는 특징이 존재
  <br/>

- Linked List는 메모리 상에 흩어져 있지만 연결되어 있다는 특징
  <br/>

- 대표적인 형태로 **Singly Linked List(단일 연결 리스트)** 와 **Doubly Linked List(이중 연결 리스트)** 가 존재
  <br/>

## 특징

- **장점**

  - **빠른 Update(수정/추가)Delete(삭제)**

    - 시간복잡도 O(1)
    - 배열에 경우, 배열은 중간 인덱스의 data를 삭제한다고 한다면 삭제 후 남은 요소들을 이동해야함
      <br/>

  - **동적 메모리 관리**
    - 크기를 유연하게 조정할 수 있어 메모리 활용에 유리
    - 배열에 경우, 고정된 크기로 Create/Init
      <br/>

- **단점**

  - **느린 접근**

    - Linked List에서 특정 요소를 탐색 할경우 시간 복잡도 O(n)
    - 단일 연결리스트로 볼 경우 Head를 통해 포인터가 존재하지 않을 때까지 해당 값을 순회하면서 찾아야하기 떄문

  - **추가적인 메모리 필요**
    <br/>

## [Singly Linked List](https://github.com/BOLTB0X/DataStructure-Algorithm/blob/main/Algorithm/Linked%20List/SLinkedList.md)

## [Doubly Linked List]()
