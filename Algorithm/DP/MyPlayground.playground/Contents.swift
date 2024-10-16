import Foundation

var dp = Array(repeating: 0, count: 1000)

// MARK: - Top down
// 시간복잡도 O(2^n)
func fibo_Topdown(_ n: Int) -> Int {
    if n <= 1 {
        return n;
    } else {
        if dp[n] > 0 {
            return dp[n]
        }
        
        dp[n] = fibo_Topdown(n-1) + fibo_Topdown(n-2)
        return dp[n]
    }
}

print(fibo_Topdown(5))
// 5

// MARK: - Bottom up
// 시간복잡도 O(n)
func fibo_Bottomup(_ n: Int) -> Int {
    dp = Array(repeating: 0, count: 1000)

    dp[0]
    dp[1] = 1
    
    for i in 2...n {
        dp[i] = dp[i-1] + dp[i-2]
    }
    
    return dp[n]
}

print(fibo_Bottomup(5))
// 5
