import Foundation

func solution(_ numbers:String) -> Int {
    var answer:Int = 0
    var numbersArr = numbers.map{$0}
    var resultsSet:Set<Int> = []
    
    // 소수판별
    func isPrime(_ num:Int) -> Bool {
        var result: Bool = true
        
        if num < 2 {
            result = false
        }else if num > 2 {
            for i in 2..<num {
                if num%i == 0 {
                    result = false
                }
            }
        }
        return result
    }
    
    // 깊이우선탐색
    func DFS(_ prime:String, _ visited:[Bool], _ size:Int, _ level:Int) {
        if size == level {
            resultsSet.insert(Int(prime)!)
            return
        }
        
        var visited = visited
        for i in 0..<numbersArr.count {
            if visited[i] == true {
                continue
            }
            visited[i] = true
            DFS(prime+"\(numbersArr[i])",visited,size, level+1)
            visited[i] = false
        }
    }
    
    for i in 1...numbers.count {
        var visited:[Bool] = Array(repeating: false, count: numbers.count)
        DFS("", visited, i, 0)
    }
    
    let arr = resultsSet.map{$0}
    //print(arr)
    
    for a in arr {
        if isPrime(a) == true {
            answer += 1
        }
    }
    return answer
}