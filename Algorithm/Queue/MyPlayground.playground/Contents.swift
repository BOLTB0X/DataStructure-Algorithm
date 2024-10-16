import UIKit

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

var queue = Queue<Int>()
queue.enqueue(1)
queue.enqueue(2)
queue.enqueue(3)
queue.enqueue(4)
queue.enqueue(5)

print(queue.dequeue() ?? -1)
// 1
print(queue.peek() ?? -1)
// 2
print(queue.count)
// 4
print(queue.isEmpty)
// false
