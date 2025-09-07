class Solution {
    func merge(_ nums1: inout [Int], _ m: Int, _ nums2: [Int], _ n: Int) {
        nums1 = Array(nums1[0..<m]) + Array(nums2[0..<n])
        nums1.sort()
    }
}