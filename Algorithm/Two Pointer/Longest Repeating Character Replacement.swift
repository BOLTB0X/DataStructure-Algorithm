class Solution {
    func characterReplacement(_ s: String, _ k: Int) -> Int {
        var answer: Int = 0
        var start: Int = 0, maxCount: Int = 0

        var eleDic = s.reduce(into: [Character:Int]()) { $0[$1] = 0 }
        let s = Array(s)

        for end in s.indices {
            eleDic[s[end], default: 0] += 1
            maxCount = max(maxCount, eleDic[s[end], default: 0])

            while (end - start + 1) - maxCount > k {
                eleDic[s[start], default: 0] -= 1
                start += 1
            }

            answer = max(answer, end - start + 1)
        }

        return answer
    }
}