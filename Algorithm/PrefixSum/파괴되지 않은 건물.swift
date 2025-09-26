import Foundation

func solution(_ board:[[Int]], _ skill:[[Int]]) -> Int {
    var answer: Int = 0
    var prefixSum = [[Int]](repeating: Array(repeating: 0, count: board[0].count + 1), count: board.count + 1)
    
    for sk in skill {
        let t = sk[0]
        let r1 = sk[1], c1 = sk[2], r2 = sk[3], c2 = sk[4]
        var degree = sk[5]
        if t == 1 {
            degree *= -1
        }
        
        prefixSum[r1][c1] += degree
        prefixSum[r1][c2 + 1] -= degree
        prefixSum[r2 + 1][c1] -= degree
        prefixSum[r2 + 1][c2 + 1] += degree
    }
    
    for i in board.indices {
        for j in board[i].indices {
            prefixSum[i][j+1] += prefixSum[i][j]
        }
    }
    
    for j in board[0].indices {
        for i in board.indices {
            prefixSum[i + 1][j] += prefixSum[i][j]
        }
    }
    
    for i in board.indices {
        for j in board[i].indices {
            prefixSum[i][j] += board[i][j]
            
            if prefixSum[i][j] > 0 {
                answer += 1
            }
        }
    }
    

    
    return answer
}