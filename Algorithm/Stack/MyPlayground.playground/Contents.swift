import Foundation

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

var stack = Stack<Int>()

stack.push(0)
stack.push(1)
stack.push(2)
stack.push(3)
stack.push(4)

print(stack.pop() ?? -1)
// 4

print(stack.peek() ?? -1 )
// 3

print(stack.count)
// 4

print(stack.isEmpty)
//false
