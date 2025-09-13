class Solution {
    func subsets(_ nums: [Int]) -> [[Int]] {
        var answer: [[Int]] = []

        func backTrack(_ subset: [Int], _ cur: Int) {
            answer.append(subset)

            for i in cur..<nums.count {
                backTrack(subset + [nums[i]] ,i + 1)
            }

        } // backTrack

        backTrack([], 0)

        return answer
    }
}