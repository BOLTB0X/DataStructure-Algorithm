import Foundation

let N = Int(readLine()!)!
print(solution(N))

func solution(_ N: Int) -> Int {
    var answer = 0
    var colUsed = Array(repeating: false, count: N)
    var diag1Used = Array(repeating: false, count: 2*N-1) // (row+col)
    var diag2Used = Array(repeating: false, count: 2*N-1) // (row-col+N-1)

    func dfs(_ row: Int) {
        if row == N {
            answer += 1
            return
        }

        for col in 0..<N {
            if colUsed[col] || diag1Used[row+col] || diag2Used[row-col+N-1] {
                continue
            }

            colUsed[col] = true
            diag1Used[row+col] = true
            diag2Used[row-col+N-1] = true

            dfs(row+1)

            colUsed[col] = false
            diag1Used[row+col] = false
            diag2Used[row-col+N-1] = false
        }
    } // dfs

    dfs(0)

    return answer
}
