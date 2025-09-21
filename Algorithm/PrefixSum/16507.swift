import Foundation

let RCQ = readLine()!.split(separator: " ").map { Int(String($0))! }
var board: [[Int]] = []

for _ in 0..<RCQ[0] {
  board.append(readLine()!.split(separator: " ").map { Int(String($0))! })
}

var prefixSum = [[Int]](repeating: [Int](repeating: 0, count: RCQ[1] + 1), count: RCQ[0] + 1)

for i in 1...RCQ[0] {
  for j in 1...RCQ[1] {
    prefixSum[i][j] = board[i - 1][j - 1] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1]
  }
}

for _ in 0..<RCQ[2] {
  let pos = readLine()!.split(separator: " ").map { Int(String($0))! }
  let x1 = pos[0] - 1, y1 = pos[1] - 1, 
      x2 = pos[2] - 1, y2 = pos[3] - 1
  let sum = prefixSum[x2 + 1][y2 + 1] - prefixSum[x1][y2 + 1] - prefixSum[x2 + 1][y1] + prefixSum[x1][y1]

  print(sum / (x2 - x1 + 1) / (y2 - y1 + 1))
}