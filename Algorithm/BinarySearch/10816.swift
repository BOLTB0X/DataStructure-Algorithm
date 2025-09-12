import Foundation

let N = Int(readLine()!)!
let cards = readLine()!.split(separator: " ").map{ Int(String($0))! }.sorted()
let M = Int(readLine()!)!
let targets = readLine()!.split(separator: " ").map{ Int(String($0))! }

var answer: String = ""

for target in targets {
  answer += "\(upperBound(target) - lowerBound(target)) "
}

print(answer)

func upperBound(_ target: Int) -> Int {
  var start: Int = 0, end: Int = N

  while start < end {
    let mid = (start + end) / 2

    if cards[mid] <= target {
      start = mid + 1
    } else {
      end = mid
    }
  }

  return start
} // upperBound

func lowerBound(_ target: Int) -> Int {
  var start: Int = 0, end: Int = N

  while start < end {
    let mid = (start + end) / 2

    if cards[mid] < target {
      start = mid + 1
    } else {
      end = mid
    }
  }

  return start
} // lowerBound