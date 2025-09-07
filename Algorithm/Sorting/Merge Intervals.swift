class Solution {
    func merge(_ intervals: [[Int]]) -> [[Int]] {
        var answer:[[Int]] = []
        let intervals = intervals.sorted{
            if $0[0] == $1[0] {
                return $0[1] < $1[1]
            }
            return $0[0] < $1[0]
        }

        for interval in intervals {
            let size = answer.count
            if answer.isEmpty || answer[size - 1][1] < interval[0] {
                answer.append(interval)
            } else {
                answer[size - 1][1] = max(answer[size - 1][1], interval[1])
            }
        }

        return answer
    }
}