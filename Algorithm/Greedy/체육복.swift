import Foundation

func solution(_ n:Int, _ lost:[Int], _ reserve:[Int]) -> Int {
    var students = Array(repeating: 1, count: n + 1)
    students[0] = 0
    
    for l in lost {
        students[l] -= 1
    }
    
    for r in reserve {
        students[r] += 1
    }
    
    for i in 1...n {
        if students[i] != 0 {
            continue
        }
        
        if (i > 1 && students[i - 1] > 1) {
            students[i - 1] -= 1
            students[i] = 1
        } else if (i < n && students[i + 1] > 1) {
            students[i + 1] -= 1
            students[i] = 1
        }
    }
    
    return students.filter{$0 > 0}.count
}