import Foundation

func solution(_ word:String) -> Int {
    var answer: Int = 0
    var moum:[String] = ["A", "E", "I", "O", "U"]
    var resArr:[String] = []
    
    func DFS(_ cur: String, _ depth: Int, _ limit: Int) {
        if depth == limit {
            if !resArr.contains(cur) {
                resArr.append(cur)
            }
            return
        }
        
        for m in moum {
            DFS(cur+m, depth+1, limit)
        }
    }
    
    for i in 1...5 {
        DFS("", 0, i)
    }
    
    resArr.sort(by: <)
    answer = resArr.firstIndex(of: word)!+1
    return answer
}