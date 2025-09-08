import Foundation

let N = Int(readLine()!)!
var answer: Int = 666
var loop: Int = 0

func isSixSixSix(_ n: Int) -> Bool {
  var n = n

  while n >= 666 {
    if n % 1000 == 666 {
      return true
    }

    n /= 10
  }

  return false
}

while true {
  if isSixSixSix(answer) {
    loop += 1
  }

  if loop == N {
    break
  }

  answer += 1
}

print(String(answer))