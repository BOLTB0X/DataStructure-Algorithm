import Foundation

let n = Int(readLine()!)!
var info: [[Int]] = []

for _ in 0..<n {
    info.append(readLine()!.split(separator: " ").map { Int($0)! })
}
print(solution(n, info))

func solution(_ n: Int, _ info: [[Int]]) -> Int {
    var dp = Array(repeating: 0, count: n + 1)

    for i in stride(from: n - 1, through: 0, by: -1) {
        let time = info[i][0]
        let pay = info[i][1]

        if i + time <= n {
            dp[i] = max(dp[i + 1], dp[i + time] + pay)
        } else {
            dp[i] = dp[i + 1]
        }
    }

    return dp[0]
}