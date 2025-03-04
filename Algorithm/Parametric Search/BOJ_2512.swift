import Foundation

let NM = readLine()!.split(separator: " ").map { Int(String($0))! }
let heights = readLine()!.split(separator: " ").map { Int(String($0))! }

print(solution(NM[0], NM[1], heights))

func solution(_ N: Int, _ M: Int, _ heights: [Int]) -> Int {
  var answer = 0
  let heights = heights.sorted{$0 < $1}
  var l = 0, r = heights.last!

  while l <= r {
    let mid = (l + r) / 2
    var sum = 0

    for h in heights {
      if mid < h {
        sum += (h - mid)
      }
    } // for

    if sum >= M {
      l = mid + 1
    } else {
      r = mid - 1
    }
  } // while

  answer = r
  return answer
}