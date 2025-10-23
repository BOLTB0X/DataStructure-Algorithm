import Foundation

func solution(_ n:Int, _ edge:[[Int]]) -> Int {
    var answer: Int = 0
    var adj: [[Int]] = Array(repeating: [Int](), count: n + 1)
    
    func dijkstra(_ start: Int) -> [Int] {
        var que:[Int] = [start]
        var head: Int = 0
        
        var dist = [Int](repeating: Int.max, count: n + 1)
        dist[start] = 0
        
        while head < que.count {
            let cur = que[head]
            head += 1
                        
            for next in adj[cur] {
                if dist[next] <= 1 + dist[cur] {
                    continue
                }
                
                dist[next] = 1 + dist[cur]
                que.append(next)
            }
        }
        
        return dist
    } // dijkstra
    
    for uv in edge {
        adj[uv[0]].append(uv[1])
        adj[uv[1]].append(uv[0])
    }
    
    let ret = dijkstra(1)
    let maxDist = ret[1...].max() ?? 0
    //print(maxDist)
    return ret.filter { $0 == maxDist }.count
}