import Foundation

func solution(_ orders:[String], _ course:[Int]) -> [String] {
    var answer:[String] = []
    var menuCandiates: [String: Int] = [:]
    
    let orders = orders.map{ Array($0) }
    
    func combination(_ order: [Character],
                     _ com: [Character], _ limit: Int,
                     _ cur: Int, _ depth: Int) {
        if limit == depth {
            menuCandiates[String(com.sorted()), default: 0] += 1
            return
        }
        
        for i in cur..<order.count {
            combination(order, com + [order[i]], limit, i + 1, depth + 1)
        }
        return
    } // combination
    
    for len in course {
        menuCandiates = [:]
        
        for order in orders.filter{ $0.count >= len } {
            combination(order, [], len, 0, 0)
        }
        
        let maxCount = menuCandiates.values.max() ?? 0
        answer += menuCandiates.filter({ $0.value >= 2 && $0.value == maxCount}).keys
    }
    
    return answer.sorted()
}