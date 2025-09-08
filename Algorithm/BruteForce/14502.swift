import Foundation

let NM = readLine()!.split(separator: " ").map{Int(String($0))!}
var board:[[Int]] = []

for _ in 0..<NM[0] {
  board.append(readLine()!.split(separator: " ").map{Int(String($0))!})
}

print(solution(NM[0], NM[1], board))

func solution(_ N: Int, _ M: Int, _ board: [[Int]]) -> Int {
  var answer: Int = 0
  var board = board
  let dir = [[-1, 0], [1, 0], [0, -1], [0, 1]]

  func inRange(_ x: Int, _ y: Int) -> Bool {
    x >= 0 && x < N && y >= 0 && y < M
  } // inRange

  func dfs(_ x: Int, _ y: Int) {
    for d in dir {
      let nx = x + d[0]
      let ny = y + d[1]

      if inRange(nx, ny) && board[nx][ny] == 0 {
          board[nx][ny] = 2
          dfs(nx, ny)
      }
    }
    return
  } // dfs

  func speradVirus() {    
    for i in 0..<N {
      for j in 0..<M {
        if board[i][j] == 2 {
          dfs(i, j)
        }
      }
    }
  } // speradVirus

  func buildWall(_ start: Int, _ cnt: Int) {
    if cnt == 3 {
      let backup = board
      speradVirus()
      answer = max(answer, board.flatMap{$0}.filter{$0 == 0}.count)
      board = backup
      return
    }

    for i in start..<(N*M) {
      let x = i / M
      let y = i % M

      if board[x][y] == 0 {
        board[x][y] = 1
        buildWall(i + 1, cnt + 1)
        board[x][y] = 0
      }
    }

    return
  } // buildWall

  buildWall(0, 0)
  
  return answer
} // solution
