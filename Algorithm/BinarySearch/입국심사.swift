import Foundation

func solution(_ n:Int, _ times:[Int]) -> Int64 {
    var answer: Int64 = 0
    var start = times.min()!, end = times.max()! * n
    
    while start <= end {
        let mid = (start + end) / 2
        
        if check(n, times, mid) {
            start = mid + 1
        } else {
            answer = Int64(mid)
            end = mid - 1
        }
    }
    
    return answer
}

func check(_ n: Int, _ arr: [Int], _ t: Int) -> Bool {
    var cnt: Int = 0
    
    for a in arr {
        cnt += t / a
    }
    
    return cnt < n
}