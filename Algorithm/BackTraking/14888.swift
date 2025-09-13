import Foundation

let N = Int(readLine()!)!
let arr = readLine()!.split(separator: " ").map{Int(String($0))!}
let operators = readLine()!.split(separator: " ").map{Int(String($0))!}

print(solution(N, arr, operators))

func solution(_ N: Int, _ arr: [Int], _ operators: [Int]) -> String {
  var answer: [Int] = [-1000000001, 1000000001]
  var operators: [Int] = operators

  func dfs(_ result: Int, _ depth: Int) {
    if depth == N {
      answer[0] = max(answer[0], result)
      answer[1] = min(answer[1], result)
      return
    }

    if operators[0] > 0 {
      operators[0] -= 1
      dfs(result + arr[depth], depth + 1)
      operators[0] += 1
    }

    if operators[1] > 0 {
      operators[1] -= 1
      dfs(result - arr[depth], depth + 1)
      operators[1] += 1
    }

    if operators[2] > 0 {
      operators[2] -= 1
      dfs(result * arr[depth], depth + 1)
      operators[2] += 1
    }

    if operators[3] > 0 {
      operators[3] -= 1
      dfs(result / arr[depth], depth + 1)
      operators[3] += 1
    }

    return
  }

  dfs(arr[0], 1)
  
  return "\(answer[0])\n\(answer[1])"
} // solution
