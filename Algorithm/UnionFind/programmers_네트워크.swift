import Foundation

func solution(_ n:Int, _ computers:[[Int]]) -> Int {
    var answer:[Int] = []
    var parents: [Int] = Array(repeating: 0, count: n+1)
    
    func Find(_ x : Int) -> Int {
        if (x != parents[x]) {
            parents[x] = Find(parents[x])
        }
        return parents[x]
    }
    
    func Union(_ x: Int, _ y: Int) {
        var x = x
        var y = y
        x = Find(x)
        y = Find(y)
        
        if x != y {
            if x < y {
                parents[y] = x
            } else {
                parents[x] = y
            }
        }
        
        return
    }
    
    for i in 0...n {
        parents[i] = i
    }
    
    for i in 0..<n {
        for j in 0..<n {
            if (i == j || computers[i][j] == 0) {
                continue
            }
            
            Union(i, j)
        }
    }
    
    for i in 0..<n {
        if !answer.contains(Find(i)) {
            answer.append(i)
        }
    }
    return answer.count
}