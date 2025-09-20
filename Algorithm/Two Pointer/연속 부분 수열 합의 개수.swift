import Foundation

func solution(_ elements:[Int]) -> Int {
    var answer: Set<Int> = []
    let elements = elements + elements
    var prefixSum = [Int](repeating: 0, count: elements.count + 1)
    
    for i in 0..<elements.count {
        prefixSum[i + 1] = prefixSum[i] + elements[i]
    }
    
    for length in 1...(elements.count / 2) {
        for i in 0..<(elements.count / 2) {
            answer.insert(prefixSum[length + i] - prefixSum[i])
        }
    }
    
    return answer.count
}