import Foundation

let expression = readLine()!

print(solution(expression))

func solution(_ expression: String) -> Int {
  var plusNumbers: [Int] = []
  var minusNumbers: [Int] = []
  var number: String = ""
  var flag: Bool = true

  for e in Array(expression) {
    if e.isNumber {
      number.append(e)
    } else {
      if flag {
        plusNumbers.append(Int(number) ?? 0)
      } else {
        minusNumbers.append(Int(number) ?? 0)
      }
      number = ""
      if e == "-" {
        flag = false
      }
    }
  }

  if flag {
    plusNumbers.append(Int(number) ?? 0)
  } else {
    minusNumbers.append(Int(number) ?? 0)
  }

  return plusNumbers.reduce(0, +) - minusNumbers.reduce(0, +)
}