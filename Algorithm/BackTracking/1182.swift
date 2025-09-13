import Foundation

let NS = readLine()!.split(separator: " ").map{Int(String($0))!}
let arr:[Int] = readLine()!.split(separator: " ").map{Int(String($0))!}

print(solution(NS[0], NS[1], arr))

func solution(_ N: Int, _ S: Int, _ arr: [Int]) -> Int {
  var answer: Int = 0

  func DFS(_ sum: Int, _ depth: Int) {
    if depth == N {
      return
    }

    if sum + arr[depth] == S {
      answer += 1
    }

    DFS(sum + arr[depth], depth + 1)
    DFS(sum, depth + 1)
    return
  }

  DFS(0, 0)
  
  return answer
} // solution
