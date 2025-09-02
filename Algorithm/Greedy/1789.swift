import Foundation

let N = Int(readLine()!)!

print(solution(N))

func solution(_ N: Int) -> Int {
  var answer: Int = 0
  var sum = 0

  for i in 1...N {
    sum += i

    if sum > N {
      answer = i - 1
      sum -= i
      break
    } else if sum == N {
      answer = i
      break
    }
  }

  return answer
}