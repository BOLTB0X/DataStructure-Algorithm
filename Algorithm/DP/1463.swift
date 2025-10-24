import Foundation

let X = Int(readLine()!)!

print(solution(X))

func solution(_ X: Int) -> Int {
    if X == 1 { return 0 } 
    
    var dp = Array(repeating: 0, count: X + 1)

    if X >= 2 {
        dp[2] = 1
    }
    
    if X >= 3 {
        dp[3] = 1
    }

    for i in 2...X {
        dp[i] = dp[i - 1] + 1

        if i % 2 == 0 {
            dp[i] = min(dp[i], dp[i / 2] + 1)
        }
        
        if i % 3 == 0 {
            dp[i] = min(dp[i], dp[i / 3] + 1)
        }
    }
    
    return dp[X]
}