import Foundation

func solution(_ dice:[[Int]]) -> [Int] {
    var answer: [Int] = []
    var maxWincase: Int = -1
    
    for selection in combination(dice.count / 2) {
        let myCase = dice.enumerated().filter{ selection.contains($0.0) }.map{ $0.1 }
        let enemyCase = dice.enumerated().filter{ selection.contains($0.0) == false }.map{ $0.1 }
                
        let myCurrent = rollDice(myCase, dice.count / 2)
        let enemyCurrent = rollDice(enemyCase, dice.count / 2).sorted()
        let winCase = myCurrent.reduce(0) { $0 + lowerBound(enemyCurrent, $1)}
        if maxWincase < winCase {
            maxWincase = winCase
            answer = selection.map { $0 + 1}
        }
        
    }
    
    return answer

} // solution

func combination(_ r: Int) -> [[Int]] {
    var result: [[Int]] = []
        
    func dfs(_ com: [Int], _ cur: Int, _ depth: Int) {
        if depth == r {
            result.append(com)
            return
        }   
        
        for i in cur..<(r * 2) {
            dfs(com + [i], i + 1, depth + 1)
        }
        return
    } // dfs
    
    dfs([], 0, 0)
        
    return result
} // combination

func rollDice(_ dice: [[Int]], _ diceCount:Int) -> [Int] {
    var result: [Int] = []
    
    func dfs(_ sum: Int, _ depth: Int) {
        if depth == diceCount {
            result.append(sum)
            return
        }
        
        for i in 0..<6 {
            dfs(sum + dice[depth][i], depth + 1)
        }
        
        return
    }
    
    dfs(0, 0)
    return result
} // rollDice

func lowerBound(_ arr: [Int], _ target: Int) -> Int {
    var start: Int = 0, end: Int = arr.count
    
    while start < end {
        let mid = (start + end) / 2
        
        if arr[mid] < target {
            start = mid + 1
        } else {
            end = mid
        }
    }
    
    return start
}