import Foundation

let T = Int(readLine()!)!

for _ in 0..<T {
  let N = Int(readLine()!)!
  let budgets = readLine()!.split(separator: " ").map{Int(String($0))!}

  print(solution(N, budgets))
}

func solution(_ N: Int, _ budgets: [Int]) -> Int {
  var answer: Int = 0
  var maxBudget: Int = 0

  for budget in budgets.reversed() {
    if maxBudget < budget {
      maxBudget = budget
    } else {
      answer += (maxBudget - budget)
    }
  }

  return answer
}