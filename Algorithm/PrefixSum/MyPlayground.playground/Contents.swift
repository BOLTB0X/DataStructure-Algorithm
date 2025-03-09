import Foundation

let arr = [3, 2, 4, 1, 7]
let N = arr.count

var prefixSum = [Int](repeating: 0, count: N + 1)

// 누적합 계산
for i in 0..<N {
    prefixSum[i + 1] = prefixSum[i] + arr[i]
}

// 구간 합 (1~3) => arr[1] + arr[2] + arr[3] = 2 + 4 + 1 = 7
let L = 1, R = 3
print(prefixSum[R + 1] - prefixSum[L]) // 7

let arr2 = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

let M = arr2.count
let K = arr2[0].count

// 누적합 배열
var prefixSum2 = [[Int]](repeating: [Int](repeating: 0, count: K + 1), count: M + 1)

// 누적합 계산
for i in 1...M {
    for j in 1...K {
        prefixSum2[i][j] = arr2[i - 1][j - 1] + prefixSum2[i - 1][j] + prefixSum2[i][j - 1] - prefixSum2[i - 1][j - 1]
    }
}

// 예제: 구간 합 (1,1) ~ (2,2) => arr[1][1] + arr[1][2] + arr[2][1] + arr[2][2]
let x1 = 1, y1 = 1, x2 = 2, y2 = 2

let result = prefixSum2[x2][y2] - prefixSum2[x1 - 1][y2] - prefixSum2[x2][y1 - 1] + prefixSum2[x1 - 1][y1 - 1]

print(result) // 5 + 6 + 8 + 9 = 28
