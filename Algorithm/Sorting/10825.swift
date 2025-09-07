import Foundation

let N = Int(readLine()!)!
var students:[String: [Int]] = [:]
var answer: String = ""

for _ in 0..<N {
  let inputs = readLine()!.split(separator: " ").map{String($0)}
  students[inputs[0]] = [Int(inputs[1])!,
                        Int(inputs[2])!,
                        Int(inputs[3])!]
}

let sorted = students.sorted {
  if $0.value[0] == $1.value[0] {
    if $0.value[1] == $1.value[1] {
      if $0.value[2] == $1.value[2] {
        return $0.key < $1.key
      }
      return $0.value[2] > $1.value[2]
    }
    return $0.value[1] < $1.value[1]
  }
  return $0.value[0] > $1.value[0]
}

for s in sorted {
  answer += s.key + "\n"
}

print(answer)