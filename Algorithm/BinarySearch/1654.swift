import Foundation

let NK = readLine()!.split(separator: " ").map{ Int(String($0))! }
var LANCables: [Int] = []

for _ in 0..<NK[0] {
  LANCables.append(Int(readLine()!)!)
}

print(solution(NK[0], NK[1], LANCables))

func solution(_ N: Int, _ K: Int, _ LANCables: [Int]) -> Int {
  var answer: Int = 0
  var start: Int = 1, end: Int = LANCables.max() ?? 0

  while start <= end {
    let mid = (start + end) / 2

    var sum: Int = 0

    for cable in LANCables {
      sum += cable / mid
    }

    if K <= sum {
      answer = mid
      start = mid + 1
    } else {
      end = mid - 1
    }
  }

  return answer
}
