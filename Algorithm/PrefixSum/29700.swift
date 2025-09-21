import Foundation

let NMK = readLine()!.split(separator: " ").map { Int(String($0))! }
var board: [[Int]] = []

for _ in 0..<NMK[0] {
  board.append(readLine()!.map { Int(String($0))! })
}

print(solution(NMK[0], NMK[1], NMK[2], board))

func solution(_ N: Int, _ M: Int, _ K: Int, _ board: [[Int]]) -> Int {
  var answer: Int = 0

  var prefixSum = [[Int]](repeating: [Int](repeating: 0, count: M + 1), count: N)

  for i in 0..<N {
    for j in 1...M {
      if board[i][j - 1] != 0 {
        continue
      }
      prefixSum[i][j] = prefixSum[i][j - 1] + 1
    }

    answer += prefixSum[i].filter { $0 >= K }.count
  }
  
  
  return answer
} // solution
