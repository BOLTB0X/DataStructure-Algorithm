import Foundation

let T = Int(readLine()!)!

for _ in 0..<T {
  let MNXY = readLine()!.split(separator: " ").map { Int(String($0))! }
  print(solution(MNXY[0], MNXY[1], MNXY[2], MNXY[3]))
}

func solution(_ M: Int, _ N: Int, _ x: Int, _ y: Int) -> Int {
  var answer: Int = -1
  var k: Int = x

  let maxYear = lcm(M, N)

  func gcd(_ a: Int, _ b: Int) -> Int {
    b == 0 ? a : gcd(b, a % b)
  }

  func lcm(_ a: Int, _ b: Int) -> Int {
    a * b / gcd(a, b)
  }

  while k <= maxYear {
    let ny = k % N == 0 ? N : k % N

    if ny == y {
      answer = k
      break
    }
    
    k += M
  }

  return answer
}