import Foundation

func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
    var left = 0
    var right = nums.count - 1

    while left < right {
        let sum = nums[left] + nums[right]

        if sum == target {
            return [left, right]
        } else if sum < target {
            left += 1
        } else {
            right -= 1
        }
    }
    
    return []
}

print(twoSum([2, 7, 11, 15], 9))
// [0, 1]

func subArrayMinLength(_ nums: [Int], _ target: Int) -> Int {
    var res: Int = Int.max
    var left = 0, sum = 0

    for right in 0..<nums.count {
        sum += nums[right]

        while sum >= target {
            res = min(res, right - left + 1)
            sum -= nums[left]
            left += 1
        }
    }
    
    if res == Int.max {
        res = 0
    }
    
    return res
}

func subArrayMaxSum(_ nums: [Int], _ length: Int) -> Int {
    var res: Int = -1
    var tot = nums[0..<length].reduce(0, +)
    res = tot
    
    for i in length..<nums.count {
        tot += nums[i] - nums[i - length] // 새로운 값 추가, 이전 값 제거
        res = res > tot ? res : tot
    }
    
    return res
}

print(subArrayMaxSum([2, 1, 3, 4, 6, 3, 8, 9, 10], 3))
