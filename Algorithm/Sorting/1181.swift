import Foundation

let N = Int(readLine()!)!
var words:[String] = []

for _ in 0..<N {
  words.append(readLine()!)
}

words = Array(Set(words))

words.sort {
  if $0.count == $1.count {
    return $0 < $1
  }
  return $0.count < $1.count
}

print(words.joined(separator: "\n"))