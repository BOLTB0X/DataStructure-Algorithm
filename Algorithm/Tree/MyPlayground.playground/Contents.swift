import Foundation

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

func preOrderTraversal<T>(node: TreeNode<T>?) {
    guard let node = node else { return }
    print(node.value, terminator: " ")
    preOrderTraversal(node: node.left)
    preOrderTraversal(node: node.right)
}

func inOrderTraversal<T>(node: TreeNode<T>?) {
    guard let node = node else { return }
    inOrderTraversal(node: node.left)
    print(node.value, terminator: " ")
    inOrderTraversal(node: node.right)
}

func postOrderTraversal<T>(node: TreeNode<T>?) {
    guard let node = node else { return }
    postOrderTraversal(node: node.left)
    postOrderTraversal(node: node.right)
    print(node.value, terminator: " ")
}

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

preOrderTraversal(node: root)
print()
// 루트 -> 왼쪽 -> 오른쪽
// 36 4 2 11 21 62 54 60 75 85

inOrderTraversal(node: root)
print()
// 왼쪽 -> 루트 -> 오른쪽
// 2 4 11 21 36 54 60 62 75 85

postOrderTraversal(node: root)
print()
// 왼쪽 -> 오른쪽 -> 루트
// 2 21 11 4 60 54 85 75 62 36

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

func preOrderTraversalDict(tree: [Int: (Int?, Int?)], node: Int?) {
    guard let node = node else { return }
    print(node, terminator: " ")
    preOrderTraversalDict(tree: tree, node: tree[node]?.0)
    preOrderTraversalDict(tree: tree, node: tree[node]?.1)
}

func inOrderTraversalDict(tree: [Int: (Int?, Int?)], node: Int?) {
    guard let node = node else { return }
    inOrderTraversalDict(tree: tree, node: tree[node]?.0)
    print(node, terminator: " ")
    inOrderTraversalDict(tree: tree, node: tree[node]?.1)
}

func postOrderTraversalDict(tree: [Int: (Int?, Int?)], node: Int?) {
    guard let node = node else { return }
    postOrderTraversalDict(tree: tree, node: tree[node]?.0)
    postOrderTraversalDict(tree: tree, node: tree[node]?.1)
    print(node, terminator: " ")
}

preOrderTraversalDict(tree: tree, node: 36)
print()
// 루트 -> 왼쪽 -> 오른쪽
// 36 4 2 11 21 62 54 60 75 85

inOrderTraversalDict(tree: tree, node: 36)
print()
// 왼쪽 -> 루트 -> 오른쪽
// 2 4 11 21 36 54 60 62 75 85

postOrderTraversalDict(tree: tree, node: 36)
print()
// 왼쪽 -> 오른쪽 -> 루트
// 2 21 11 4 60 54 85 75 62 36

