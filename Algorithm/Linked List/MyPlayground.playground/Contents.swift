import Foundation

final class Node<T> {
    var data: T
    var nextNode: Node<T>?
    
    init(_ data: T, nextNode: Node<T>? = nil) {
        self.data = data
        self.nextNode = nextNode
    }
}

class SinglyLinkedList<T> {
    var head: Node<T>?
    var tail: Node<T>?
    
    func append(_ value: T) {
        let newNode = Node(value)
        if head == nil {
            head = newNode
            tail = newNode
        } else {
            tail?.nextNode = newNode
            tail = newNode
        }
    } // append
    
    func read(at index: Int) -> T? {
        var current = head
        var currentIndex = 0
        
        while current != nil && currentIndex < index {
            current = current?.nextNode
            currentIndex += 1
        }
        
        return current?.data
    } // read
    
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
    } // insert
    
    func printList() {
        var current = head
        while current != nil {
            print(current?.data ?? "nil", terminator: " -> ")
            current = current?.nextNode
        }
        print("nil")
    } // printList
    
    func update(at index: Int, with newValue: T) {
        var current = head
        var currentIndex = 0
        
        while current != nil && currentIndex < index {
            current = current?.nextNode
            currentIndex += 1
        }
        
        if current != nil {
            current?.data = newValue
        }
    } // update
    
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
    } // delete
}

// 테스트 코드
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

list.insert(15, at: 2)
list.printList()
// 22 -> 2 -> 15 -> 77 -> 6 -> 43 -> 76 -> 89 -> nil

list.delete(at: 6)
list.printList()
//22 -> 2 -> 15 -> 77 -> 6 -> 43 -> 89 -> nil


list.delete(at: 6)
list.printList()
// 22 -> 2 -> 15 -> 77 -> 6 -> 43 -> nil

