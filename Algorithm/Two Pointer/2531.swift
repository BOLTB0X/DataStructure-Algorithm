import Foundation

let Ndkc = readLine()!.split(separator: " ").map{ Int(String($0))! }
var belt: [Int] = []

for _ in 0..<Ndkc[0] {
  belt.append(Int(readLine()!)!)
}

print(solution(Ndkc[0], Ndkc[1], Ndkc[2], Ndkc[3], belt))

func solution(_ N: Int, _ d: Int, _ k: Int, _ c: Int, _ belt: [Int]) -> Int {
  var answer: Int = 0
  var sushiType = [Int](repeating: 0, count: d + 1)
  var uniqueCount: Int = 0

  let belt: [Int] = belt + belt
  
  for i in 0..<k {
    if sushiType[belt[i]] == 0 {
      uniqueCount += 1
    }

    sushiType[belt[i]] += 1
  }

  answer = uniqueCount + (sushiType[c] == 0 ? 1: 0)

  for i in 1..<N {
    let removed = belt[i - 1]

    sushiType[removed] -= 1
    if sushiType[removed] == 0 {
      uniqueCount -= 1
    }

    let added = belt[i + k - 1]
    if sushiType[added] == 0 {
      uniqueCount += 1
    }
    
    sushiType[added] += 1

    answer = max(answer, uniqueCount + (sushiType[c] == 0 ? 1: 0))
  }
  
  return answer
} // solution
