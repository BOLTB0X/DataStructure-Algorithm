import Foundation

let NK = readLine()!.split(separator: " ").map{ Int(String($0))! }
let temperatures
: [Int] = readLine()!.split(separator: " ").map{ Int(String($0))! }

print(solution(NK[0], NK[1], temperatures
))

func solution(_ N: Int, _ K: Int, _ temperatures: [Int]) -> Int {
  var answer: Int = Int.min
  var prefixSum = [Int](repeating: 0, count: N + 1)
  
  for i in 1...N {
    prefixSum[i] = prefixSum[i - 1] + temperatures[i - 1]
  }

  for i in 0...(N - K) {
    answer = max(answer, prefixSum[i + K] - prefixSum[i])
  }
  
  return answer
} // solution
