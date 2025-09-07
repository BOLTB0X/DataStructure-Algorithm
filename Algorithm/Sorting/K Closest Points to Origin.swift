class Solution {
    func kClosest(_ points: [[Int]], _ k: Int) -> [[Int]] {
        Array(points.sorted{ 
            getDistance($0[0], $0[1]) < getDistance($1[0], $1[1])
        }[..<k])
    }

    func getDistance(_ x: Int,  _ y: Int) -> Double {
        sqrt(pow(Double(x), 2) + pow(Double(y), 2))
    }
}