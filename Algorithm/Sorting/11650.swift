import Foundation

let N = Int(readLine()!)!
var positions:[[Int]] = []

for _ in 0..<N {
  positions.append(readLine()!.split(separator: " ").map{Int(String($0))!})
}

positions.sort {
  if $0[0] == $1[0] {
    return $0[1] < $1[1]
  }
  return $0[0] < $1[0]
}

for pos in positions {
  print("\(pos[0]) \(pos[1])")
}