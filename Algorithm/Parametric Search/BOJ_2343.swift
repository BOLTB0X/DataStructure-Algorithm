import Foundation

let NM = readLine()!.split(separator: " ").map { Int(String($0))! }
let bluelays = readLine()!.split(separator: " ").map { Int(String($0))! }

print(solution(NM[0], NM[1], bluelays))

func solution(_ N: Int, _ M: Int, _ bluelays: [Int]) -> Int {
  var answer = 0
  var l = bluelays.max()!, r = bluelays.reduce(0, +)

  while l <= r {
    let mid = (l + r) / 2
    var tot = 0, cnt = 1

    for bluelay in bluelays {
      if bluelay > mid {
        cnt = M + 1
        break
      }
      
      if tot + bluelay > mid {
        cnt += 1
        tot = 0
      }
      tot += bluelay
    } // for

    if (M < cnt) {
      l = mid + 1
    } else {
      r = mid - 1
    }
  } // while

  answer = l
  return answer
}