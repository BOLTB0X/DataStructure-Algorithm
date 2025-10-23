import Foundation

func solution(_ n:Int, _ s:Int, _ a:Int, _ b:Int, _ fares:[[Int]]) -> Int {
    var answer: Int = Int.max
    var adj: [Int: [(next: Int, cost: Int)]] = [:]
    
    func dijkstra(_ start: Int) -> [Int] {
        var que: [(node: Int, cost: Int)] = [(start, 0)]
        var head: Int = 0
        var dist = [Int](repeating: Int.max, count: n + 1)
        
        dist[start] = 0
        
        while head < que.count {
            let (cur, curCost) = que[head]
            //print(cur)
            head += 1
            
            if curCost > dist[cur] { continue }
            
            for (next, nextCost) in adj[cur, default: []] {
                if dist[next] <= nextCost + curCost {
                    continue
                }
                
                dist[next] = nextCost + curCost
                que.append((next, dist[next]))
            }
        }
        
        return dist
    } // dijkstra
    
    for fare in fares {
        adj[fare[0], default: []].append((fare[1], fare[2]))
        adj[fare[1], default: []].append((fare[0], fare[2]))
    }
    
    //print(adj)
    let distS = dijkstra(s)
    let distA = dijkstra(a)
    let distB = dijkstra(b)
    
    // print(distS)
    // print(distA)
    // print(distB)
    
    for i in 1...n {
        if distS[i] == Int.max || distA[i] == Int.max || distB[i] == Int.max { continue }
        
        answer = min(answer, distS[i] + distA[i] + distB[i])
    }
    return answer
}