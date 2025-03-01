import Foundation

func lowerBound(_ arr: [Int], _ target: Int) -> Int {
    var start = 0
    var end = arr.count
    
    while start < end {
        let mid = (start + end) / 2
        if arr[mid] < target {
            start = mid + 1
        } else {
            end = mid
        }
    }
    
    return start
}

func upperBound(_ arr: [Int], _ target: Int) -> Int {
    var start = 0
    var end = arr.count
    
    while start < end {
        let mid = (start + end) / 2
        if arr[mid] <= target {
            start = mid + 1
        } else {
            end = mid
        }
    }
    
    return start
}

let arr = [1, 2, 2, 2, 3, 5, 7]

print(lowerBound(arr, 2)) // 1
print(upperBound(arr, 2)) // 4

func sol_2512(n: Int, requestions: [Int], budget: Int) -> Int {
    var answer: Int = 0
    
    var requestions = requestions
    var l = 0, r = requestions.max()!
    
    while l <= r {
        let mid = (l + r) / 2
        var tot = 0
        
        requestions.forEach {
            if $0 <= mid {
                tot += $0
            } else {
                tot += mid
            }
        }
        
        if tot <= budget {
            l = mid + 1
        } else {
            r = mid - 1
        }
    }
    
    answer = r
    return answer
}

//let n = Int(readLine()!)!
//let requestions = readLine()!.split(separator: " ").map{Int(String($0))!}
//let budget = Int(readLine()!)!

print(sol_2512(n: 4, requestions: [120, 110, 140, 150], budget: 485))
