import Foundation

let N = Int(readLine()!)!
let solutions = readLine()!.split(separator: " ").map { Int(String($0))! }

print(solution(N, solutions))

func solution(_ N: Int, _ solutions: [Int]) -> String {
  var answer: [Int] = [1000000001, 1000000001]
  var start: Int = 0, end: Int = solutions.count - 1

  while start < end && end < N {
    let sum = solutions[start] + solutions[end]

    if abs(answer[0] + answer[1]) > abs(sum) {
      answer = [solutions[start], solutions[end]]
    }

    if sum < 0 {
      start += 1
    } else {
      end -= 1
    }
  }
  
  return "\(answer[0]) \(answer[1])"
} // solution
