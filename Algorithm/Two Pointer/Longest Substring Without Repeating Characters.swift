class Solution {
    func lengthOfLongestSubstring(_ s: String) -> Int {
        var answer: Int = 0
        var subString: [Character] = []

        let s = Array(s)

        for i in 0..<s.count {
            subString.append(s[i])
            if subString.count == Set(subString).count {
                answer = max(answer, subString.count )
            } else {
                subString = Array(subString[1...])
            }
        }

        return answer
    }
}