import Foundation

func solution(_ words:[String], _ queries:[String]) -> [Int] {
    var answer:[Int] = []
    var lengthF: [Int: [String]] = [:], lengthR: [Int: [String]] = [:]
    
    for word in words {
        lengthF[word.count, default: []].append(word)
        lengthR[word.count, default: []].append(String(word.reversed()))
    } //
    
    for (k, v) in lengthF {
        lengthF[k] = v.sorted()
    }
    
    for (k, v) in lengthR {
        lengthR[k] = v.sorted()
    }
    
    for query in queries {
        if query.first! != "?" {
            let arr = lengthF[query.count, default: []]
            let lower = query.replacingOccurrences(of: "?", with: "a")
            let upper = query.replacingOccurrences(of: "?", with: "z")
            
            answer.append(upperBound(arr, upper) - lowerBound(arr, lower))
        } else {
            let arr = lengthR[query.count, default: []]
            let lower = String(query.reversed()).replacingOccurrences(of: "?", with: "a")
            let upper = String(query.reversed()).replacingOccurrences(of: "?", with: "z")
            
            answer.append(upperBound(arr, upper) - lowerBound(arr, lower))
        } // if - else
    }
    
    return answer
}

func upperBound(_ arr:[String], _ target: String) -> Int {
    var start: Int = 0, end: Int = arr.count
    
    while start < end {
        let mid = (start + end) / 2
        
        if arr[mid] <= target {
            start = mid + 1
        } else {
            end = mid
        }
    }
    
    return start
} // upperBound

func lowerBound(_ arr:[String], _ target: String) -> Int {
    var start: Int = 0, end: Int = arr.count
    
    while start < end {
        let mid = (start + end) / 2
        
        if arr[mid] < target {
            start = mid + 1
        } else {
            end = mid
        }
    }
    
    return start
} // lowerBound