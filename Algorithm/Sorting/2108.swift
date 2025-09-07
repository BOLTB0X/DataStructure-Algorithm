import Foundation

let N = Int(readLine()!)!
var arr: [Int] = []

for _ in 0..<N {
  arr.append(Int(readLine()!)!)
}

for s in solution(N, arr) {
  print(s)
}

func solution(_ N: Int, _ arr: [Int]) -> [Int] {
  let arr = arr.sorted(by: <)
  let sum = arr.reduce(0.0) {Double($0) + Double($1)}
  let occDict = arr.reduce(into: [Int:Int]()) {$0[$1, default: 0] += 1}
  let maxFreq = occDict.values.max()!
  let candidates = occDict.filter{$0.value == maxFreq}.map{$0.key}.sorted()

  let occKey = candidates.count == 1 ? candidates[0] : candidates[1]
  
  return [Int(round(sum / Double(N))), 
          arr[N / 2], 
          occKey, 
          arr[N-1] - arr[0]]
}