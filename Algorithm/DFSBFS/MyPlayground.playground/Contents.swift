import Foundation

func dfs(_ graph: [[Int]], _ visited: inout [Bool], _ start: Int) {
    visited[start] = true
    print(start, terminator: " ")

    for next in graph[start] {
        if !visited[next] {
            dfs(graph, &visited, next)
        }
    }
} // dfs

func bfs(_ graph: [[Int]], _ start: Int) {
    var visited = Array(repeating: false, count: graph.count)
    var queue = [start]
    visited[start] = true
    
    while !queue.isEmpty {
        let node = queue.removeFirst()
        print(node, terminator: " ")
        
        for next in graph[node] {
            if !visited[next] {
                visited[next] = true
                queue.append(next)
            }
        } // for
    } //while
} // bfs

let graph = [
    [],         // 0 (unused)
    [2, 3],     // 1 → 2,3
    [4],        // 2 → 4
    [4],        // 3 → 4
    [],         // 4
]

var visited = Array(repeating: false, count: 5)

dfs(graph, &visited, 1) // 1 2 4 3

bfs(graph, 1) // 1 2 3 4 (방문 순서)
