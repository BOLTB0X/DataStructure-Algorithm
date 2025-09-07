class Solution {
    func largestNumber(_ nums: [Int]) -> String {
        let answer = nums.map{String($0)}.sorted{$0 + $1 > $1 + $0}.joined()

        return answer.first! == "0" ? "0" : answer
    }
}