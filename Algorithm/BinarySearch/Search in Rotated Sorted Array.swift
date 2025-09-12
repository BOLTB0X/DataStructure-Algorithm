class Solution {
    func search(_ nums: [Int], _ target: Int) -> Int {
        var answer: Int = -1
        var sortedNums = nums.sorted()

        if var i = binarySearch(sortedNums, target) {
            var cnt: Int = 0

            while cnt < nums.count {
                if sortedNums == nums {
                    answer = i
                    break
                }

                let fir = sortedNums.removeFirst()
                sortedNums += [fir]
                cnt += 1
                i = i - 1 < 0 ? sortedNums.count - 1 : i - 1
            }
        } 

        return answer
    } // search

    func binarySearch(_ arr:[Int], _ target: Int) -> Int? {
        var start: Int = 0, end: Int = arr.count - 1

        while start <= end {
            let mid = (start + end) / 2

            if arr[mid] == target {
                return mid
            } else if arr[mid] < target {
                start = mid + 1
            } else {
                end = mid - 1
            }
        }

        return nil
    } // binarySearch
}