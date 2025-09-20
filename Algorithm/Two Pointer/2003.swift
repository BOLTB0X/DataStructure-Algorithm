import Foundation

let NM = readLine()!.split(separator: " ").map{ Int(String($0))! }
let arr: [Int] = readLine()!.split(separator: " ").map{ Int(String($0))! }

print(solution(NM[0], NM[1], arr))

func solution(_ N: Int, _ M: Int, _ arr: [Int]) -> Int {
  var answer: Int = 0
  var l: Int = 0, r: Int = 0, sum: Int = arr[0]
  
  while r < arr.count {
    if sum == M {
      answer += 1
    }

    if sum > M {
      sum -= arr[l]
      l += 1
      
    } else {
      r += 1
      sum += r == arr.count ? 0 : arr[r]
    }
  }
  
  return answer
} // solution
