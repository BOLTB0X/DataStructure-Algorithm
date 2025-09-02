import Foundation

let N = Int(readLine()!)!
let inputs:[Int] = readLine()!.split(separator: " ").map{Int(String($0))!}

print(solution(N, inputs))

func solution(_ N: Int, _ waitings: [Int]) -> Int {
  var answer = 0
  let waitings = waitings.sorted {$0 < $1}

  var prefixSum: Int = 0
  
  for i in 0..<N {
    prefixSum += waitings[i]
    answer += prefixSum
  }
  
  return answer
}