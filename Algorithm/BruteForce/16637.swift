import Foundation

let N = Int(readLine()!)!
let expression = readLine()!

print(solution(N, expression))

func solution(_ N: Int, _ expression: String) -> Int {
  var answer: Int = Int.min
  let numbers = expression.components(separatedBy: ["+", "-", "*"]).filter{!$0.isEmpty}.map{Int($0)!}
  let operators = expression.filter{!$0.isNumber}.map{ String($0) }

  func DFS(_ res: Int, _ depth: Int) {
    if depth == operators.count {
      answer = max(answer, res)
      return
    }

    DFS(calculate(res, numbers[depth + 1], operators[depth]), depth + 1)

    if depth + 1 < operators.count {
      let next = calculate(numbers[depth + 1], numbers[depth + 2], operators[depth + 1])
      DFS(calculate(res, next, operators[depth]), depth + 2)
    }

    return
  } // DFS

  func calculate(_ a: Int, _ b: Int, _ op: String) -> Int {
    op == "+" ? a + b : op == "-" ? a - b : a * b
  } // calculate

  DFS(numbers[0], 0)
  
  return answer
}