import Foundation

func solution(_ answers:[Int]) -> [Int] {
    var answer:[Int] = []
    let supoja1:[Int] = [1,2,3,4,5]
    let supoja2:[Int] = [2,1,2,3,2,4,2,5]
    let supoja3:[Int] = [3,3,1,1,2,2,4,4,5,5]
    
    var totalAns:[Int] = [0,0,0]
    
    for i in answers.enumerated() {
        if i.1 == supoja1[i.0 % supoja1.count] {
            totalAns[0] += 1
        }
        if i.1 == supoja2[i.0 % supoja2.count] {
            totalAns[1] += 1
        }
        if i.1 == supoja3[i.0 % supoja3.count] {
            totalAns[2] += 1
        }
    }
    
    let maxValue = totalAns.max()
    for i in 0..<3 {
        if totalAns[i] == totalAns.max() {
            answer.append(i + 1)
        }
    }
    return answer
}