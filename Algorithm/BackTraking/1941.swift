import Foundation

var board: [String] = []

for _ in 0..<5 {
  board.append(readLine()!)
}

print(solution(board))

func solution(_ board: [String]) -> Int {
  var answer:Int = 0
  var visited = Array(repeating: false, count: 25)

  let board = board.map{ Array($0) }

  func bfs(_ sx: Int, _ sy: Int) -> Int {
    var res: Int = 1
    var checked = Array(repeating: Array(repeating: false, count: 5), count: 5)
    var que: [[Int]] = [[sx, sy]]

    let dir = [[0, 1], [1, 0], [0, -1], [-1, 0]]

    checked[sx][sy] = true

    while !que.isEmpty {
      let cur = que.removeFirst()

      for d in dir {
        let nx = cur[0] + d[0]
        let ny = cur[1] + d[1]
        let next = nx * 5 + ny

        if nx < 0 || ny < 0 || nx >= 5 || ny >= 5 { continue }

        if checked[nx][ny] || !visited[next] { continue }

        checked[nx][ny] = true
        res += 1
        que.append([nx, ny])
      }
    }
    
    return res
  } // bfs

  func dfs(_ cur: Int, _ yCount: Int, _ depth: Int) {
    if yCount >= 4 {
      return
    }

    if depth == 7 {
      answer += bfs((cur - 1) / 5, (cur - 1) % 5) == 7 ? 1: 0
      return
    }

    for i in cur..<25 {
      if visited[i] { continue }

      visited[i] = true
      if board[i / 5][i % 5] == "Y" {
        dfs(i + 1, yCount + 1, depth + 1)
      } else {
        dfs(i + 1, yCount, depth + 1)
      }
      visited[i] = false
    }
    return 
  } // dfs

  dfs(0, 0, 0)
  
  return answer
} // solution
