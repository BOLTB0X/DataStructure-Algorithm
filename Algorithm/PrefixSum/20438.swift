import Foundation

let NKQM = readLine()!.split(separator: " ").map { Int(String($0))! }
let sleepStudents = readLine()!.split(separator: " ").map { Int(String($0))! }
let qrStudents = readLine()!.split(separator: " ").map { Int(String($0))! }
var ranges: [[Int]] = []

for _ in 0..<NKQM[3] {
  ranges.append(readLine()!.split(separator: " ").map { Int(String($0))! })
}

solution(NKQM[0], NKQM[1], NKQM[2], NKQM[3], sleepStudents, qrStudents, ranges)

func solution(_ N:Int, _ K:Int, _ Q:Int, _ M:Int, _ sleepStudents: [Int], _ qrStudents: [Int], _ ranges: [[Int]])  {
  var enterCode = Array(repeating: 0, count: N + 3)

  for i in 0..<K {
    enterCode[sleepStudents[i]] = -1
  }

  for i in 0..<Q {
    if enterCode[qrStudents[i]] == -1 {
      continue
    }
    
    for j in stride(from: qrStudents[i], to: N + 3, by: qrStudents[i]) {
                                                                                 if enterCode[j] == -1 {
        continue
      }
      
      enterCode[j] = 1
    }
  }

  var prefixSum = Array(repeating: 0, count: N + 3)

  for i in 3...(N + 2) {
    prefixSum[i] = prefixSum[i - 1] + (enterCode[i] != 1 ? 1: 0)
  }

  for range in ranges {
    print(prefixSum[range[1]] - prefixSum[range[0] - 1])
  }


  return
}