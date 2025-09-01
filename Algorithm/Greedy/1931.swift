import Foundation

let N = Int(readLine()!)!
var arr:[[Int]] = []

for _ in 0..<N {
  let input = readLine()!.split(separator: " ").map{Int(String($0))!}
  arr.append(input)
}

print(solution(N, arr))

func solution(_ N: Int, _ rooms: [[Int]]) -> Int {
  var answer = 0
  let rooms = rooms.sorted {
      if $0[1] == $1[1] {
        return $0[0] < $1[0]
      }
    return $0[1] < $1[1]
  }

  var curEndTime = rooms[0][1]
  answer += 1
  
  for i in 1..<N {
    if rooms[i][0] >= curEndTime {
      answer += 1
      curEndTime = rooms[i][1]
    }
  }
  
  return answer
}