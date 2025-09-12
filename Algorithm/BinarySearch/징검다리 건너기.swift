import Foundation

func solution(_ stones:[Int], _ k:Int) -> Int {
    var answer: Int = 0
    var start: Int = stones.min() ?? 1
    var end: Int = stones.max() ?? 200_000_000
    
    while start <= end {
        let mid = (start + end) / 2
        
        if isCross(stones, k, mid) {
            answer = mid
            end = mid - 1
        } else {
            start = mid + 1
        }
    }
    
    return answer
}

func isCross(_ stones:[Int], _ k:Int, _ crossedFriend: Int) -> Bool {
    var jumpLengh: Int = 0
    
    for i in stones.indices {
        if stones[i] - crossedFriend <= 0 {
            jumpLengh += 1
        } else {
            jumpLengh = 0
        }
        
        if jumpLengh >= k {
            break
        }
    }
    
    return jumpLengh >= k
}