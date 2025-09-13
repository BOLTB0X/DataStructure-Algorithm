import Foundation

func solution(_ n:Int, _ info:[Int]) -> [Int] {
    var answer:[Int] = [-1]
    var maxDiff: Int = -1
        
    for cur in makeTotalLionCase(n, info) {
        let lion = convertArrows(cur)
        let scores = calScore(lion, info)
        
        if scores[0] <= scores[1] {
            continue
        }
        
        if maxDiff < abs(scores[0] - scores[1]) {
            maxDiff = abs(scores[0] - scores[1])
            answer = lion
        } else if maxDiff == abs(scores[0] - scores[1]) {
            answer = chechMoreLower(lion, answer)
        }
    }
    
    return answer
}

func makeTotalLionCase(_ n:Int, _ info:[Int]) -> [[Int]] {
    var result: [[Int]] = []
    
    func dfs(_ com: [Int], _ cur: Int, _ depth: Int) {
        if depth == n {
            result.append(com)
            return
        }
        
        for i in cur...10 {
            dfs(com + [i], i, depth + 1)
        }
    } // dfs
    
    dfs([], 0, 0)
    
    return result
} // makeTotalLionCase

func convertArrows(_ arr: [Int]) -> [Int] {
    var result = Array(repeating: 0, count: 11)
    
    for a in arr {
        result[a] += 1
    }
    
    return result
} // convertArrows

func calScore(_ lion: [Int], _ apach: [Int]) -> [Int] {
    var lScore: Int = 0
    var aScore: Int = 0
    
    for i in 0...10 {
        if lion[i] == 0 && apach[i] == 0 {
            continue
        }
        
        if lion[i] > apach[i] {
            lScore += 10 - i
        } else {
            aScore += 10 - i
        }
    }
    
    return [lScore, aScore]
} // check

func chechMoreLower(_ arr1: [Int], _ arr2: [Int]) -> [Int] {
    for i in stride(from: 10, through: 0, by: -1) {
        if arr1[i] < arr2[i] {
            return arr2
        } else if arr1[i] > arr2[i] {
            return arr1
        }
    }
    return arr2
} // chechMoreLower