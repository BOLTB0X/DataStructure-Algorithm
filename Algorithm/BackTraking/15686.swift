import Foundation

let NM = readLine()!.split(separator: " ").map { Int(String($0))! }
var board: [[Int]] = []

for _ in 0..<NM[0] {
  board.append(readLine()!.split(separator: " ").map { Int(String($0))! })
}

print(solution(NM[0], NM[1], board))

func solution(_ N: Int, _ M: Int, _ board: [[Int]]) -> Int {
  var answer: Int = 1000000000
  
  var homes:[[Int]] = []
  var chickens: [[Int]] = []
  
  func calDistance(_ chickens: [[Int]]) -> Int {
    var res: Int = 0

    for home in homes {
      var dist: Int = 1000000000
      for chicken in chickens {
        dist = min(dist, abs(home[0] - chicken[0]) + abs(home[1] - chicken[1]))
      }

      res += dist
    }

    return res
  } // calDistance

  func combination(_ com: [Int], _ cur: Int, _ depth: Int) {    
    if depth == M {
      var tempChickens: [[Int]] = []

      for c in com {
        tempChickens.append(chickens[c])
      }
      answer = min(answer, calDistance(tempChickens))
      return
    }

    for i in cur..<chickens.count {
      if visited[i] { continue }

      visited[i] = true
      combination(com + [i], i + 1, depth + 1)
      visited[i] = false
    }
    
    return
  } // combination

  for i in 0..<N {
    for j in 0..<N {
      if board[i][j] == 1 {
        homes.append([i, j])
      }
    }
  }

  for i in 0..<N {
    for j in 0..<N {
      if board[i][j] == 2 {
        chickens.append([i, j])
      }
    }
  }

  var visited: [Bool] = Array(repeating: false, count: chickens.count)
  combination([], 0, 0)
  
  return answer
}
