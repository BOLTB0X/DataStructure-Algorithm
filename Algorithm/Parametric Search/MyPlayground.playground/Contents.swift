import Foundation

func isPossible(_ arr: [Int], _ target: Int, _ h: Int) -> Bool {
    var res = 0
    
    for height in arr {
        if height > h {
            res += height - h
        }
    }
    
    return res >= target
}

func parametricSearch(_ arr: [Int], _ target: Int) -> Int {
    var start = 0
    var end = arr.max() ?? 0
    var result = 0

    while start <= end {
        let mid = (start + end) / 2

        if isPossible(arr, target, mid) {
            result = mid // 톱날 높이를 높여도 가능
            start = mid + 1 // 더 높은 높이에서 탐색
        } else {
            end = mid - 1
        }
    }

    return result
}

func solution(_ N: Int, _ M: Int, _ woods: [Int]) -> Int {
    return parametricSearch(woods, M)
}

print(solution(4, 7, [20, 15, 10, 17])) // 15

print(solution(5, 20, [4, 42, 40, 26, 46])) // 36
