import Foundation

let NM = readLine()!.split(separator: " ").map{ Int(String($0))! }
var cashes: [Int] = []

for _ in 0..<NM[0] {
  cashes.append(Int(readLine()!)!)
}

print(solution(NM[0], NM[1], cashes))

func solution(_ N: Int, _ M: Int, _ cashes: [Int]) -> Int {
  var answer: Int = 0
  var start: Int = cashes.max() ?? 0, end: Int = cashes.reduce(0, +)

  while start <= end {
    let mid = (start + end) / 2

    var count: Int = 1
    var curMoney: Int = mid

    for cash in cashes {
      if curMoney - cash < 0 {
        curMoney = mid
        count += 1
      }

      curMoney -= cash
    }

    if count > M {
      start = mid + 1
    } else {
      answer = mid
      end = mid - 1
    }
  }
  
  return answer
}
