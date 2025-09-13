class Solution {
    func permute(_ nums: [Int]) -> [[Int]] {
        var answer:[[Int]] = []
        var visited = Array(repeating: false, count: nums.count)

        func DFS(_ per: [Int], _ depth: Int) {
            if depth == nums.count {
                answer.append(per)
                return
            }

            for i in 0..<nums.count {
                if visited[i] {
                    continue
                }

                visited[i] = true
                DFS(per + [nums[i]], depth + 1)
                visited[i] = false
            }

            return
        }

        DFS([], 0)
        return answer
    }
}