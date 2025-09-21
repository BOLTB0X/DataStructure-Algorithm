
class NumMatrix {
    let board: [[Int]]
    let row: Int
    let col: Int

    init(_ matrix: [[Int]]) {
        board = matrix
        row = matrix.count
        col = matrix[0].count
    }
    
    func sumRegion(_ row1: Int, _ col1: Int, _ row2: Int, _ col2: Int) -> Int {
        var prefixSum = [[Int]](repeating: [Int](repeating: 0, count: col + 1), count: row + 1)

        let row1: Int = row1 + 1,col1: Int = col1 + 1, row2: Int = row2 + 1, col2: Int = col2 + 1

        for i in 1...row {
            for j in 1...col {
                prefixSum[i][j] = board[i - 1][j - 1] + prefixSum[i][j - 1] + prefixSum[i - 1][j] - prefixSum[i - 1][j - 1]
            }
        }


        return prefixSum[row2][col2] - prefixSum[row1 - 1][col2] - prefixSum[row2][col1 - 1] + prefixSum[row1 - 1][col1 - 1]
        // 8 - 
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * let obj = NumMatrix(matrix)
 * let ret_1: Int = obj.sumRegion(row1, col1, row2, col2)
 */