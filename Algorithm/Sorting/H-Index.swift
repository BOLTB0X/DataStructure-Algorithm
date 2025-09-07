import Foundation

func solution(_ citations:[Int]) -> Int {
    var answer: Int = 0
    
    for citation in citations.sorted(by: >) {
        if citation > answer {
            answer += 1
        } else {
            break
        }
    }
    
    return answer
}