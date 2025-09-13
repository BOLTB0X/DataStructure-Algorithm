class Solution {
    func combinationSum(_ candidates: [Int], _ target: Int) -> [[Int]] {
        var answer: [[Int]] = []

        func dfs(_ com: [Int],  _ cur: Int, _ depth: Int) {
            let sum = com.reduce(0, +)

            if sum == target {
                answer.append(com)
            }

            for i in cur..<candidates.count {
                if sum + candidates[i] > target { continue }

                dfs(com + [candidates[i]], i, depth)
            }

        } // dfs

        dfs([], 0, 0)

        return answer
    }
}