import Foundation

let NK = readLine()!.split(separator: " ").map{Int(String($0))!}
let products = readLine()!.split(separator: " ").map{Int(String($0))!}

print(solution(NK[0], NK[1], products))

func solution(_ N: Int, _ K: Int, _ products: [Int]) -> Int {
  var answer: Int = 0
  var plug: [Int] = []

  for i in products.indices {
    if plug.count < N {
      plug += !plug.contains(products[i]) ? [products[i]] : []
    } else {
      if plug.contains(products[i]) {
        continue
      }

      var targetIndex: Int = -1
      var targetValue: Int = -1
      for p in plug {
        if let j = Array(products[(i+1)...]).firstIndex(of: p) {
          if j > targetIndex {
            targetIndex = j
            targetValue = p
          }
        } else {
          targetValue = p
          break
        }
      }

      let removeIndex = plug.firstIndex(of: targetValue)!
      plug.remove(at:removeIndex)
      plug.append(products[i])
      answer += 1
    }
  }

  return answer
}