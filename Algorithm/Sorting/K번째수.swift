import Foundation

func solution(_ array:[Int], _ commands:[[Int]]) -> [Int] {
    var answer: [Int] = []
    
    for cmd in commands {
        let i = cmd[0] - 1
        let j = cmd[1] - 1
        let k = cmd[2] - 1
        
        answer.append(array[i...j].sorted()[k])
    }
    
    return answer
}