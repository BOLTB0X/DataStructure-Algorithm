import Foundation

func solution(_ n:Int, _ wires:[[Int]]) -> Int {
    var answer: Int = n
    var adj:[[Int]] = Array(repeating: Array(repeating: 0, count: n + 1), count: n + 1)
    
    for wire in wires {
        adj[wire[0]][wire[1]] = 1
        adj[wire[1]][wire[0]] = 1
    }
    
    for wire in wires {
        adj[wire[0]][wire[1]] = 0
        adj[wire[1]][wire[0]] = 0
        
        let ret1 = BFS(n, adj, wire[0])
        let ret2 = BFS(n, adj, wire[1])
        
        answer = min(answer, abs(ret1 - ret2))
        adj[wire[0]][wire[1]] = 1
        adj[wire[1]][wire[0]] = 1
    }
    
    return answer
}

func BFS(_ n:Int, _ adj:[[Int]], _ start: Int) -> Int {
    var res: Int = 0
    var visited: [Bool] = Array(repeating: false, count: n + 1)
    var que:[Int] = []
    
    visited[start] = true
    que.append(start)
    
    while !que.isEmpty {
        let cur = que.removeFirst()
        res += 1
        
        for i in 1...n {
            if visited[i] || adj[cur][i] == 0{
                continue
            }
            
            visited[i] = true
            que.append(i)
        }
    }
    
    return res
}