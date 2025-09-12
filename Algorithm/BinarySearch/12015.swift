let N = Int(readLine()!)!
let A = readLine()!.split(separator: " ").map {Int(String($0))!}

print(solution(N, A))

func solution(_ N: Int, _ A: [Int]) -> Int {
    var answer: [Int] = []
    
    for i in A.indices {
        let idx = lowerBound(answer, A[i])

        if idx == answer.count {
            answer.append(A[i])
        } else {
            answer[idx] = A[i]
        }
    }

    return answer.count
}

func lowerBound(_ arr:[Int], _ target: Int) -> Int {
    var start = 0, end = arr.count
    
    while start < end {
        let mid = (start + end) / 2

        if arr[mid] < target {
            start = mid + 1
        } else {
            end = mid
        }
    }

    return start
}
