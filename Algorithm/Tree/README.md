# Tree

> 트리는 계층 구조를 나타내는 비선형 데이터 구조로, 노드들로 구성

<div style="text-align: center;">
<img src="https://github.com/BOLTB0X/DataStructure-Algorithm/blob/main/Algorithm/Tree/Img/Tree.png?raw=true" alt="Example Image" width="90%">

</div>

위 그림과 같이 노드 와 간선으로 이루어진 것을 그래프(Graph) -> Tree

## 특징

- **Root 노드**
  Tree의 최상위 노드

- **간선**
  노드와 노드를 잇는 선

- **자식(Child) 노드**
  부모 노드에 의해 연결된 하위 노드

- **부모(Parent) 노드**
  자식 노드를 가지는 상위 노드
- **리프(Leaf) 노드**
  자식 노드가 없는 노드
- **서브트리(Subtree)**
  하나의 노드와 그 자손들로 구성된 트리
- **깊이(Depth)**
  루트에서 해당 노드까지의 경로 길이를 의미
- **높이(Height)**
  노드에서 가장 멀리 있는 리프 노드까지의 경로 길이를 의미

## Binary Tree(이진 트리)

> 이진 트리는 각 노드가 최대 두 개의 자식 노드(왼쪽 자식, 오른쪽 자식)를 가질 수 있는 트리

branch가 최대 2개인 노드로만 구성되는 트리

이진 트리는 다양한 활용이 가능하며, 특히 탐색, 정렬, 힙, 우선순위 큐 등의 자료구조로 많이 사용

Class 와 딕셔너리로 표현 가능

```swift
class TreeNode<T> {
    var value: T
    var left: TreeNode<T>?
    var right: TreeNode<T>?

    init(value: T, left: TreeNode<T>? = nil, right: TreeNode<T>? = nil) {
        self.value = value
        self.left = left
        self.right = right
    }
}
```

```swift
let tree: [Int: (Int?, Int?)] = [:]
```

<br/>

- **Complete Binary Tree(완전 이진 트리)**
  <div style="text-align: center;">
  <img src="https://github.com/BOLTB0X/DataStructure-Algorithm/blob/main/Algorithm/Tree/Img/%EC%99%84%EC%A0%84%20%EC%9D%B4%EC%A7%84%20%ED%8A%B8%EB%A6%AC.png?raw=true" alt="Example Image" width="100%">
  </div>

  모든 레벨이 완전히 채워져 있으며 마지막 레벨은 왼쪽부터 차례로 채워져 있는 트리
  <br/>

- **Full Binary Tree(포화 이진 트리)**
  <div style="text-align: center;">
  <img src="https://github.com/BOLTB0X/DataStructure-Algorithm/blob/main/Algorithm/Tree/Img/%ED%8F%AC%ED%99%94%EC%9D%B4%EC%A7%84%ED%8A%B8%EB%A6%AC.png?raw=true" alt="Example Image" width="100%">
  </div>
    
  모든 노드가 두 개의 자식 노드를 가지거나 리프 노드인 트리
  <br/>

- **Balanced Binary Tree(균형 이진 트리)**
  <div style="text-align: center;">
  <img src="https://github.com/BOLTB0X/DataStructure-Algorithm/blob/main/Algorithm/Tree/Img/%EC%9D%B4%EC%A7%84%20%ED%83%90%EC%83%89%20%ED%8A%B8%EB%A6%AC.png?raw=true" alt="Example Image" width="100%">
  </div>

  모든 리프 노드의 깊이가 거의 비슷한 트리로, 탐색 속도를 높이기 위해 균형을 유지
  <br/>

- **Binary Search Tree, BST(이진 탐색 트리)**
    <div style="text-align: center;">
    <img src="https://github.com/BOLTB0X/DataStructure-Algorithm/blob/main/Algorithm/Tree/Img/%EC%9D%B4%EC%A7%84%20%ED%83%90%EC%83%89%20%ED%8A%B8%EB%A6%AC.png?raw=true" alt="Example Image" width="100%">
    </div>

  왼쪽 자식 노드는 부모 노드보다 작고, 오른쪽 자식 노드는 부모 노드보다 큰 값을 가지는 트리
  <br/>

## Tree Traversal(트리 순회)

> 트리 순회는 트리의 모든 노드를 방문하는 방법, 주로 재귀 이용

1. **전위 순회(Pre-order Traversal)**

   - 방문 순서
     - **루트 -> 왼쪽 -> 오른쪽**
     - 루트 노드를 먼저 방문한 후, 왼쪽 서브트리와 오른쪽 서브트리를 순차적으로 방문
       <br/>
   - 재귀로 표현
     _preorder(node) = visit(node) -> preorder(node.left) -> preorder(node.right)_
     <br/>

   - 코드

     ```swift
     func preOrderTraversal<T>(node: TreeNode<T>?) {
        guard let node = node else { return }
        print(node.value, terminator: " ")
        preOrderTraversal(node: node.left)
        preOrderTraversal(node: node.right)
     }
     ```

     ```swift
     func preOrderTraversalDict(tree: [Int: (Int?, Int?)], node: Int?) {
        guard let node = node else { return }
        print(node, terminator: " ")
        preOrderTraversalDict(tree: tree, node: tree[node]?.0)
        preOrderTraversalDict(tree: tree, node: tree[node]?.1)
     }
     ```

      <br/>

2. **중위 순회(In-order Traversal)**

   - 방문 순서

     - **왼쪽 -> 루트 -> 오른쪽 **
     - 왼쪽 서브트리를 먼저 방문하고, 루트 노드를 방문한 후, 오른쪽 서브트리를 방문
       <br/>

   - 이진 탐색 트리에서 중위 순회를 하면 노드가 **오름차순**으로 정렬이 됌
     <br/>

   - 재귀로 표현
     _inorder(node) = inorder(node.left) -> visit(node) -> inorder(node.right)_
     <br/>

   - 코드

     ```swift
     func inOrderTraversal<T>(node: TreeNode<T>?) {
        guard let node = node else { return }
        inOrderTraversal(node: node.left)
        print(node.value, terminator: " ")
        inOrderTraversal(node: node.right)
     }
     ```

     ```swift
     func inOrderTraversalDict(tree: [Int: (Int?, Int?)], node: Int?) {
         guard let node = node else { return }
         inOrderTraversalDict(tree: tree, node: tree[node]?.0)
         print(node, terminator: " ")
         inOrderTraversalDict(tree: tree, node: tree[node]?.1)
     }
     ```

      <br/>

3. **후위 순회(Post-order Traversal)**

   - 방문 순서

     - **왼쪽 > 오른쪽 -> 루트**
     - 왼쪽과 오른쪽 서브트리를 모두 방문한 후, 루트 노드를 방문
       <br/>

   - 재귀로 표현
     _postorder(node) = postorder(node.left) -> postorder(node.right) -> visit(node)_
     <br/>

   - 코드

     ```swift
     func postOrderTraversal<T>(node: TreeNode<T>?) {
        guard let node = node else { return }
        postOrderTraversal(node: node.left)
        postOrderTraversal(node: node.right)
        print(node.value, terminator: " ")
     }
     ```

     ```swift
     func postOrderTraversalDict(tree: [Int: (Int?, Int?)], node: Int?) {
        guard let node = node else { return }
        postOrderTraversalDict(tree: tree, node: tree[node]?.0)
        postOrderTraversalDict(tree: tree, node: tree[node]?.1)
        print(node, terminator: " ")
     }
     ```

## 예시

<div style="text-align: center;">
<img src="https://github.com/BOLTB0X/DataStructure-Algorithm/blob/main/Algorithm/Tree/Img/%EC%9D%B4%EC%A7%84%20%ED%83%90%EC%83%89%20%ED%8A%B8%EB%A6%AC.png?raw=true" alt="Example Image" width="90%">

</div>

<br/>

- Tree 정의

  ```swift
  // Class
  let root = TreeNode(value: 36)

  // 왼쪽 서브트리
  root.left = TreeNode(value: 4)
  root.left?.left = TreeNode(value: 2)
  root.left?.right = TreeNode(value: 11)
  root.left?.right?.right = TreeNode(value: 21)

  // 오른쪽 서브트리
  root.right = TreeNode(value: 62)
  root.right?.left = TreeNode(value: 54)
  root.right?.left?.right = TreeNode(value: 60)
  root.right?.right = TreeNode(value: 75)
  root.right?.right?.right = TreeNode(value: 85)
  ```

  ```swift
  // Dictionary
  let tree: [Int: (Int?, Int?)] = [
     36: (4, 62),
     4: (2, 11),
     11: (nil, 21),
     2: (nil, nil),
     21: (nil, nil),
     62: (54, 75),
     54: (nil, 60),
     60: (nil, nil),
     75: (nil, 85),
     85: (nil, nil)
  ]
  ```

   <br/>

- preOrder(전위 순회)
    <div style="text-align: center;">
    <img src="https://github.com/BOLTB0X/DataStructure-Algorithm/blob/main/Algorithm/Tree/Img/%EC%A0%84%EC%9C%84.gif?raw=true" alt="Example Image" width="100%">
    </div>

  <br/>

  ```swift
  preOrderTraversal(node: root)

  preOrderTraversalDict(tree: tree, node: 36)

  print()
  // 루트 -> 왼쪽 -> 오른쪽
  // 36 4 2 11 21 62 54 60 75 85
  ```

- inOrder(중위 순회)

    <div style="text-align: center;">
    <img src="https://github.com/BOLTB0X/DataStructure-Algorithm/blob/main/Algorithm/Tree/Img/%EC%A4%91%EC%9C%84.gif?raw=true" alt="Example Image" width="100%">
    </div>

  <br/>

  ```swift
  inOrderTraversal(node: root)

  inOrderTraversalDict(tree: tree, node: 36)

  print()
  // 왼쪽 -> 루트 -> 오른쪽
  // 2 4 11 21 36 54 60 62 75 85
  ```

- postOrder(후위 순회)
    <div style="text-align: center;">
    <img src="https://github.com/BOLTB0X/DataStructure-Algorithm/blob/main/Algorithm/Tree/Img/%ED%9B%84%EC%9C%84.gif?raw=true" alt="Example Image" width="100%">
    </div>

  <br/>

  ```swift
  postOrderTraversal(node: root)

  postOrderTraversalDict(tree: tree, node: 36)

  print()
  // 왼쪽 -> 오른쪽 -> 루트
  // 2 21 11 4 60 54 85 75 62 36
  ```

   <br/>

## 참고

- [블로그 참조 - 개발자소들이(BST1)](https://babbab2.tistory.com/90)
- [블로그 참조 - 개발자소들이(BST2)](https://babbab2.tistory.com/91)

- [블로그 참조 - pooh-footprints(이진탐색트리)](https://pooh-footprints.tistory.com/entry/Swift-%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-%EC%9D%B4%EC%A7%84-%ED%83%90%EC%83%89%1C%ED%8A%B8%EB%A6%AC-Binary-Search-Tree)

- [코드 연구소 - 이진탐색트리](https://code-lab1.tistory.com/10)

- [블로그 참조 - rosweet(이진탐색트리)](https://rosweet-ai.tistory.com/59)
