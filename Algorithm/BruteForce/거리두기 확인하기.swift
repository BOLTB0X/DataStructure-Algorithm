import Foundation

func solution(_ places:[[String]]) -> [Int] {
    var answer: [Int] = []
    
    for place in places {
        answer.append(checkDistance(place.map{Array($0)}))
    }
    
    return answer
}

func checkDistance(_ board: [[Character]]) -> Int {
    var res: Int = 1
    var visited: [[Bool]] = Array(repeating: Array(repeating: false, count: 5), count: 5)
    let dir = [[-1, 0], [1, 0], [0, -1], [0, 1]]
    
    func DFS(_ x: Int, _ y: Int, _ depth: Int) {
        if depth == 2 {
            return
        }
        
        for d in dir {
            let nx = x + d[0]
            let ny = y + d[1]
            
            if nx < 0 || ny < 0 || nx >= 5 || ny >= 5 || board[nx][ny] == "X" || visited[nx][ny] {
                continue
            }
            
            if board[nx][ny] == "P" {
                res = 0
                return
            }
            
            visited[nx][ny] = true
            DFS(nx, ny, depth + 1)
        }
        
        return
    } // DFS
    
    for i in 0..<5 {
        for j in 0..<5 {
            if board[i][j] == "P" {
                visited[i][j] = true
                DFS(i, j, 0)
            }
            
            if res == 0 {
                return res
            }
        }
    }
    
    return res
} // checkDistance
