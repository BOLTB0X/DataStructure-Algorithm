import Foundation

func solution(_ n:Int, _ results:[[Int]]) -> Int {
    var answer: Int = 0
    var resultInfo = [[Int]](repeating: [Int](repeating: 0, count: n + 1), count: n + 1)
    
    for res in results {
        resultInfo[res[0]][res[1]] = 1
        resultInfo[res[1]][res[0]] = -1
    }
    
    for k in 1...n {
        for a in 1...n {
            for b in 1...n {
                if resultInfo[a][k] == 1 && resultInfo[k][b] == 1 {
                    resultInfo[a][b] = 1
                } else if resultInfo[a][k] == -1 && resultInfo[k][b] == -1 {
                    resultInfo[a][b] = -1
                }
            }
        }
    }
    
    // for res in resultInfo {
    //     print(res)
    // }
    
    for a in 1...n {
        var cnt: Int = 0
        for b in 1...n {
            if resultInfo[a][b] == 0 {
                cnt += 1
            }
        }
        
        if cnt == 1 {
            answer += 1
        }
    } // for
    
    return answer
}