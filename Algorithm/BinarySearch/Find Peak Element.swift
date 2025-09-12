class Solution {
    func findPeakElement(_ nums: [Int]) -> Int {
        var answer: Int = 0
        var start: Int = 0, end = nums.count - 1

        while start < end {
            let mid = (start + end) / 2

            if nums[mid] < nums[mid + 1] {
                start = mid + 1
            } else {
                end = mid
            }
        }

        return start
    }
}