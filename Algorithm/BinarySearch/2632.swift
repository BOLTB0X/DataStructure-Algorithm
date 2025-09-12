import Foundation

let pizza = Int(readLine()!)!
let nm = readLine()!.split(separator: " ").map{ Int(String($0))! }
var A: [Int] = [], B: [Int] = []

for _ in 0..<nm[0] {
  A.append(Int(readLine()!)!)
}

for _ in 0..<nm[1] {
  B.append(Int(readLine()!)!)
}

print(solution(pizza, A, B))

func solution(_ pizza: Int, _ A: [Int], _ B: [Int]) -> Int {
  var answer: Int = 0
  let aSums = getSumArray(A), bSums = getSumArray(B)

  for a in aSums {
    let b = pizza - a
    
    answer += upperBound(bSums, b) - lowerBound(bSums, b)
  }
  
  return answer
} // solution

func getSumArray(_ arr: [Int]) -> [Int] {
  var res: [Int] = [0]

  for i in arr.indices {
    var sum: Int = 0
    for j in i..<(arr.count + i - 1) {
      sum += arr[j % arr.count]
      res.append(sum)
    }
  }
  
  res.append(arr.reduce(0, +))

  return res.sorted()
} // getSumArray

func lowerBound(_ arr: [Int], _ target: Int) -> Int {
  var start: Int = 0, end: Int = arr.count

  while start < end {
    let mid = (start + end) / 2

    if arr[mid] < target {
      start = mid + 1
    } else {
      end = mid
    }
  }

  return start
} // lowerBound

func upperBound(_ arr: [Int], _ target: Int) -> Int {
  var start: Int = 0, end: Int = arr.count

  while start < end {
    let mid = (start + end) / 2

    if arr[mid] <= target {
      start = mid + 1
    } else {
      end = mid
    }
  }

  return start
} // upperBound