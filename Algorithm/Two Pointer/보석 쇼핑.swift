import Foundation

func solution(_ gems:[String]) -> [Int] {
    var answer: [Int] = [-100001, 100001]
    var start: Int = 0, end: Int = 0
    
    var gemsDict: [String: Int] = [gems[0] : 1]
    let gemTypeCount = Set(gems).count
    
    while start <= end && end < gems.count {
        if gemsDict.count == gemTypeCount {
            if answer[1] - answer[0] > end - start {
                answer = [start, end]
            } else if answer[1] - answer[0] == end - start {
                if answer[0] > start {
                    answer = [start, end]
                }
            }
        } // if
        
        if gemsDict.count < gemTypeCount {
            end += 1
            if end == gems.count {
                continue
            }
            gemsDict[gems[end], default: 0] += 1
        } else {
            gemsDict[gems[start], default : 0] -= 1
            if gemsDict[gems[start], default : 0] <= 0 {
                gemsDict[gems[start]] = nil
            }
            start += 1
        }
    }
    
    answer[0] += 1
    answer[1] += 1
    return answer
}