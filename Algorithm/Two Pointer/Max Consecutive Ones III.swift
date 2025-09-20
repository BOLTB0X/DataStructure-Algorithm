class Solution {
    func longestOnes(_ nums: [Int], _ k: Int) -> Int {
        var answer = 0
        var zeroCount: Int = 0, l: Int = 0

        for r in 0..<nums.count {
            if nums[r] == 0 {
                zeroCount += 1
            }

            while k < zeroCount {
                if nums[l] == 0 {
                    zeroCount -= 1
                }

                l += 1
            }

            answer = max(answer, r - l + 1)
        }

        return answer
    }
}