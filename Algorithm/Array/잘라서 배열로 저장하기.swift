import Foundation

func solution(_ my_str:String, _ n:Int) -> [String] {
    var answer: [String] = []
    let arr = Array(my_str)
    
    for i in stride(from: 0, to: my_str.count, by: n) {
        if i + n < my_str.count {
            answer.append(String(arr[i..<(i+n)]))
        } else {
            answer.append(String(arr[i...]))
        }
    }
    return answer
}