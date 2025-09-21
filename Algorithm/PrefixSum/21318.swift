import Foundation

let N = Int(readLine()!)!
let sheets = readLine()!.split(separator: " ").map{ Int(String($0))! }

var prefixSum = [Int](repeating: 0, count: N + 1)

for i in 1..<N {
  prefixSum[i] = prefixSum[i - 1] + (sheets[i - 1] > sheets[i] ? 1 : 0)
}

prefixSum[N] += prefixSum[N - 1]
let Q = Int(readLine()!)!

for _ in 0..<Q {
  let LR = readLine()!.split(separator: " ").map{ Int(String($0))! }
  print(prefixSum[LR[1] - 1] - prefixSum[LR[0] - 1])
}