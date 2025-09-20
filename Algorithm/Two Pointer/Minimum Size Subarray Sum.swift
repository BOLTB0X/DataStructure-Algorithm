class Solution {
    func minSubArrayLen(_ target: Int, _ nums: [Int]) -> Int {
        var answer: Int = 100001
        var start: Int = 0, end: Int = 0, sum: Int = nums[0]

        while start <= end && end < nums.count {
            if sum >= target {
                answer = min(answer, end - start + 1)
            }

            if sum < target {
                end += 1
                if end == nums.count { continue }
                sum += nums[end]
            } else {
                sum -= nums[start]
                start += 1
            }
        }

        return answer == 100001 ? 0 : answer
    }
}