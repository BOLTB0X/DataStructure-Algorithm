import Foundation

let NX = readLine()!.split(separator: " ").map{ Int(String($0))! }
let visitors: [Int] = readLine()!.split(separator: " ").map{ Int(String($0))! }

print(solution(NX[0], NX[1], visitors))

func solution(_ N: Int, _ X: Int, _ visitors: [Int]) -> String {
  var answer: Int = 0
  var cnt: Int = 0
  var prefixSum = [Int](repeating: 0, count: N + 1)

  for i in 1...N {
    prefixSum[i] = prefixSum[i - 1] + visitors[i - 1]
  }

  for i in 0...(N - X) {
    let sum = prefixSum[i + X] - prefixSum[i]
    
    if answer < sum {
      answer = sum
      cnt = 1
    } else if answer == sum {
      cnt += 1
    }
  }
  
  return answer == 0 ? "SAD" : "\(answer)\n\(cnt)"
} // solution
