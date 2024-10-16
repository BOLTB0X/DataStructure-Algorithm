import Foundation

var arr: [Int] = [38, 57, 50, 84, 28, 49, 80, 36, 82, 7, 7, 43, 12, 15, 38, 79]

print(arr)
// 배열 Create/Init
// [38, 57, 50, 84, 28, 49, 80, 36, 82, 7, 7, 43, 12, 15, 38, 79]

print("index 2인 요소: \(arr[2])")
//배열의 요소 Read
//index 2인 요소: 50

for (index, element) in arr.enumerated() {
    print("idenx: \(index), element: \(element)")
}
// 배열 전체 Read
//idenx: 0, element: 38
//idenx: 1, element: 57
//idenx: 2, element: 50
//idenx: 3, element: 84
//idenx: 4, element: 28
//idenx: 5, element: 49
//idenx: 6, element: 80
//idenx: 7, element: 36
//idenx: 8, element: 82
//idenx: 9, element: 7
//idenx: 10, element: 7
//idenx: 11, element: 43
//idenx: 12, element: 12
//idenx: 13, element: 15
//idenx: 14, element: 38
//idenx: 15, element: 79

arr.append(60)
print(arr)
// 배열 끝에 요소 추가(Append)
//[38, 57, 50, 84, 28, 49, 80, 36, 82, 7, 7, 43, 12, 15, 38, 79, 60]

arr.insert(5, at: 2)
print(arr)
// 배열의 특정 위치에 요소 삽입(인덱스 2에 5 Insert)
// [38, 57, 5, 50, 84, 28, 49, 80, 36, 82, 7, 7, 43, 12, 15, 38, 79, 60]

arr[1] = 15
print(arr)
// 배열 요소를(arr[1] = 15) 교체 (Update)
// [38, 57, 5, 50, 84, 28, 49, 80, 36, 82, 7, 7, 43, 12, 15, 38, 79, 60]

arr.remove(at: 8)
print(arr)
//특정 인덱스 8의 요소 Delete
// [38, 15, 5, 50, 84, 28, 49, 80, 82, 7, 7, 43, 12, 15, 38, 79, 60]

arr.removeLast()
print(arr)
// 배열의 마지막 요소 Delete
//[38, 15, 5, 50, 84, 28, 49, 80, 82, 7, 7, 43, 12, 15, 38, 79]

arr.removeFirst()
print(arr)
// 배열의 첫번쨰 요소 Delete
// [15, 5, 50, 84, 28, 49, 80, 82, 7, 7, 43, 12, 15, 38, 79]

if let index = arr.firstIndex(of: 28) {
    arr.remove(at: index)
}
print(arr)
// 배열 내 특정 값 Delete
// [15, 5, 50, 84, 49, 80, 82, 7, 7, 43, 12, 15, 38, 79]

if let index = arr.lastIndex(of: 15) {
    arr.remove(at: index)
}
print(arr)
// 배열 내 특정 값 Delete
// [15, 5, 50, 84, 49, 80, 82, 7, 7, 43, 12, 38, 79]

arr.removeAll()
print(arr)
// 배열 비우기(전체 Delete)
// []
