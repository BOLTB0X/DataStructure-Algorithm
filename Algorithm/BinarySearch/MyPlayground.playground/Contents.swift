import Foundation

func binarySearch_Recursion<T: Comparable>(_ arr: [T], _ target: T, start: Int, end: Int) -> Int? {
    guard start <= end else {
        return nil
    }
    
    let middle = (start + end) / 2
    
    if arr[middle] == target {
        return middle
    } else if arr[middle] < target {
        return binarySearch_Recursion(arr, target, start: middle + 1, end: end)
    }
    
    return binarySearch_Recursion(arr, target, start: start, end: middle - 1)
}


func binarySearch_Loop<T: Comparable>(_ arr: [T], _ target: T, start: Int, end: Int) -> Int? {
    var start = start
    var end = end
    
    while start <= end {
        let middle = (start + end) / 2
        
        if arr[middle] == target {
            return middle
        } else if arr[middle] < target {
            start = middle + 1
        } else {
            end = middle - 1
        }
    }
    
    return nil
}

let A = [0, 1, 2, 3, 5, 7, 9, 10, 11, 13, 19, 22]

if let i = binarySearch_Recursion(A, 7, start: 0, end: A.count - 1) {
    print("element 7의 index: \(i)") // element 7의 index: 5

} else {
    print("X")
}

if let i = binarySearch_Loop(A, 7, start: 0, end: A.count - 1) {
    print("element 7의 index: \(i)") //element 7의 index: 5

} else {
    print("X")
}

