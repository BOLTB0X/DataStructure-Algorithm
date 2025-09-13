import Foundation

func solution(_ numbers:String) -> Int {
    var answer: Set<Int> = []
    var visited = Array(repeating: false, count: numbers.count)
    let numbers = numbers.map{ String($0) }
    
    func isPrime(_ n: Int) -> Bool {
        if n < 2 {
            return false
        } else if n > 2 {
            for i in 2..<n {
                if n % i == 0 {
                    return false
                }
            }
        }
        
        return true
    } // isPrime
    
    func dfs(_ prime: String, _ limit: Int, _ depth: Int) {
        if limit == depth {
            answer.insert(Int(prime) ?? 0)
            return
        }
        
        for i in 0..<numbers.count {
            if visited[i] { continue }
            
            visited[i] = true
            dfs(prime + numbers[i], limit, depth + 1)
            visited[i] = false
        }
        
        return
    } // dfs
    
    for i in 1...numbers.count {
        dfs("", i, 0)
    }
    
    return answer.filter{isPrime($0)}.count
}