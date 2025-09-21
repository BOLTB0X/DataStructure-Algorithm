import Foundation

let S = readLine()!.map { String($0) }
var prefixSum = [[String: Int]](repeating: [:], count: S.count + 1)

for i in 0..<S.count {
  prefixSum[i + 1] = prefixSum[i]
  prefixSum[i + 1][S[i], default: 0] += 1
}

let q = Int(readLine()!)!

for _ in 0..<q {
  let alr = readLine()!.split(separator: " ").map { String($0) }
  let a = alr[0]
  let l = Int(alr[1])!
  let r = Int(alr[2])!

  print(prefixSum[r + 1][a, default: 0] - prefixSum[l][a, default: 0])
}

