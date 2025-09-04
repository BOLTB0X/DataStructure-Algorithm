class Solution {
    func candy(_ ratings: [Int]) -> Int {
        var allocatedList = Array(repeating: 1, count: ratings.count)

        for i in 1..<ratings.count {
            if ratings[i] > ratings[i - 1] {
                allocatedList[i] = allocatedList[i - 1] + 1 
            }
        }

        for i in stride(from: ratings.count - 2, through: 0, by: -1) {
            if ratings[i] > ratings[i + 1]
                && allocatedList[i] <= allocatedList[i + 1] {
                allocatedList[i] = allocatedList[i + 1] + 1 
            }
        }
    
        return allocatedList.reduce(0, +)
    }
}