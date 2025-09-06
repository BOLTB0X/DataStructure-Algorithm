import Foundation

let N = Int(readLine()!)!
var answer: Int = 0

for i in 1...N {
  let sum = String(i).map{Int(String($0))!}.reduce(0,+)
  if i + sum == N {
    answer = i
    break
  }
}

print(answer)