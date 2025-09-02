import Foundation

func solution(_ number:String, _ k:Int) -> String {
    var answer: [String] = []
    var number = number.map{String($0)}, k: Int = k
    
    for n in number {
        while k > 0 && !answer.isEmpty
                && Int(answer.last!)! < Int(n)! {
            answer.removeLast()
            k -= 1
        }
        
        answer.append(n)
    }
    
    while k > 0 {
        answer.removeLast()
        k -= 1
    }
    
    return answer.joined()
}