import Foundation

let NM = readLine()!.split(separator: " ").map { Int(String($0))! }
let soils = readLine()!.split(separator: " ").map { Int(String($0))! }
var cmd: [[Int]] = []

for _ in 0..<NM[1] {
  cmd.append(readLine()!.split(separator: " ").map { Int(String($0))! })
}

print(solution(NM[0], NM[1], soils, cmd))

func solution(_ N: Int, _ M: Int, _ soils: [Int], _ cmd: [[Int]]) -> String {
  var soils = soils
  var prefixSum = Array(repeating: 0, count: N + 1)

  for c in cmd {
    let (s, e, d) = (c[0] - 1, c[1] - 1, c[2])

    prefixSum[s] += d
    prefixSum[e + 1] -= d
  }

  for i in 1..<N {
    prefixSum[i] += prefixSum[i - 1]
  }

  for i in 0..<N {
    soils[i] += prefixSum[i]
  }

  return soils.map { String($0) }.joined(separator: " ")
}