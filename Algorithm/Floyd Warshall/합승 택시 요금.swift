import Foundation

func solution(_ n:Int, _ s:Int, _ a:Int, _ b:Int, _ fares:[[Int]]) -> Int {
    var answer: Int = 0
    var adj: [[Int]] = Array(repeating: [Int](repeating: 1000000 * n + 1, count: n + 1), count: n + 1)
    
    for i in 1...n {
        adj[i][i] = 0
    }
    
    for fare in fares {
        let a = fare[0], b = fare[1], c = fare[2]
        adj[a][b] = c
        adj[b][a] = c
    }
    
    for k in 1...n {
        for a in 1...n {
            for b in 1...n {
                adj[a][b] = min(adj[a][b], adj[a][k] + adj[k][b])
            }
        }
    }
    
    answer = adj[s][a] + adj[s][b]
    for i in 1...n {
        if i == s {
            continue
        }
        answer = min(answer, adj[i][s] + adj[i][a] + adj[i][b])
    }
    
    return answer
}