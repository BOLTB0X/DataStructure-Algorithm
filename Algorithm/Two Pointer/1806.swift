import Foundation

let NS = readLine()!.split(separator: " ").map{ Int(String($0))! }
let arr = readLine()!.split(separator: " ").map{ Int(String($0))! }

print(solution(NS[0], NS[1], arr))

func solution(_ N: Int, _ S: Int, _ arr: [Int]) -> Int {
  var answer: Int = 1000001
  var start: Int = 0, end: Int = 0, sum: Int = arr[0]

  while start <= end && end < N {
    if sum >= S {
      answer = min(answer, end - start + 1)
    }

    if sum < S {
      end += 1
      sum = sum + (end == N ? 0 : arr[end])
    } else {
      sum -= arr[start]
      start += 1
    }
  }

  return answer == 1000001 ? 0 : answer
} // solution
