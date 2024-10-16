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

