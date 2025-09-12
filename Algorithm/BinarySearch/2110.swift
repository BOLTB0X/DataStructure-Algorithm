import Foundation

let NC = readLine()!.split(separator: " ").map{ Int(String($0))! }
var homes: [Int] = []

for _ in 0..<NC[0] {
  homes.append(Int(readLine()!)!)
}

print(solution(NC[0], NC[1], homes))

func solution(_ N: Int, _ C: Int, _ homes: [Int]) -> Int {
  var answer: Int = 0
  var start: Int = 1, end: Int = 1_000_000_000

  let homes = homes.sorted()

  while start <= end {
    let mid = (start + end) / 2

    if isPossible(homes, mid, C) {
      answer = mid
      start = mid + 1
    } else {
      end = mid - 1
    }

  }

  return answer
} // solution

func isPossible(_ arr: [Int], _ dist: Int, _ C: Int) -> Bool {
  var cnt = 1
  var lastPos = arr[0]

  for i in 1..<arr.count {
    if arr[i] - lastPos >= dist {
      cnt += 1
      lastPos = arr[i]
    }
  }

  return cnt >= C
} // isPossible
