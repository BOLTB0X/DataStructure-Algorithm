import Foundation

let N = Int(readLine()!)!
var countingArr = [Int](repeating: 0, count: 10001)

for _ in 0..<N {
  countingArr[Int(readLine()!)!] += 1
}

var answer: String = ""

for i in 1...10000 {
  answer += String(repeating: "\(i)\n", count: countingArr[i])
}

print(answer)