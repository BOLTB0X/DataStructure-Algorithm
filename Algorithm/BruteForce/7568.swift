import Foundation

let N = Int(readLine()!)!
var students: [[Int]] = []

for _ in 0..<N {
  students.append(readLine()!.split(separator: " ").map{Int(String($0))!})
}

var answer: [Int] = []

for i in students.enumerated() {
  var rank: Int = 1
  for j in students.enumerated() {
    if i.0 == j.0 {
      continue
    }
    
    if i.1[0] < j.1[0] && i.1[1] < j.1[1] {
      rank += 1
    }
  }

  answer.append(rank)
}

print(answer.map{String($0)}.joined(separator: " "))