import Foundation

let N = Int(readLine()!)!

print(solution(N))

func solution(_ N: Int) -> String {
  var answer: String = ""

  func isGood(_ numbers: [Int]) -> Bool {
    for i in 1...(numbers.count / 2) {
      let l = numbers[(numbers.count - i * 2)..<(numbers.count - i)]
      let r = numbers[(numbers.count - i)..<numbers.count]

      if l == r {
        return false
      }
    }
    
    return true
  }

  func dfs(_ numbers: [Int], _ depth: Int) {
    if answer != "" {
      return
    }

    if depth == N {
      answer = numbers.map { String($0) }.joined()
      return
    }

    for i in 1...3 {
      if numbers.isEmpty || isGood(numbers + [i]) {
        dfs(numbers + [i], depth + 1)
      }
    }
  } // dfs

  dfs([], 0)

  return answer
}
