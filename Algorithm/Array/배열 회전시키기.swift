import Foundation

func solution(_ numbers:[Int], _ direction:String) -> [Int] {
     var numbers = numbers
    
    return direction == "right" ? [numbers.removeLast()] + numbers : numbers[1...] + [numbers.removeFirst()]
}