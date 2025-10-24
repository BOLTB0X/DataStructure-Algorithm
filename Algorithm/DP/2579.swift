import Foundation

let n = Int(readLine()!)!
var stairs: [Int] = []

for _ in 0..<n {
    stairs.append(Int(readLine()!)!)
}
print(solution(n, stairs))

func solution(_ n: Int, _ stairs: [Int]) -> Int {
    var dp = Array(repeating: 0, count: n)

    if n == 1 {
        return stairs[0]
    }
    if n <= 2 {
        return stairs[0] + stairs[1]
    }
    
    if n == 3 {
        return max(stairs[0] + stairs[2], stairs[1] + stairs[2])
    }
    
    dp[0] = stairs[0]
    dp[1] = stairs[0] + stairs[1]
    dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2])

    for i in 3..<n {
        dp[i] = max(dp[i - 3] + stairs[i - 1] + stairs[i], dp[i - 2] + stairs[i])
    }
    
    return dp[n - 1]
}