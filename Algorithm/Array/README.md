# Array(배열)

> 컴퓨터 과학에서 배열은 번호와 번호에 대응하는 데이터들로 이루어진 자료 구조를 나타낸다.


**Array(배열) == Sequential List(순차 리스트)**, 연속적인 메모리 위치의 집합이라고 정의되어짐

<div style="text-align: center;">
<img src="https://github.com/BOLTB0X/DataStructure-Algorithm/blob/main/Algorithm/Array/%EC%98%88%EC%8B%9C.png?raw=true" alt="Example Image" width="100%">

</div>


> 배열은 고정된 크기의 연속된 메모리 공간에 저장되는 데이터 구조로, 인덱스를 통해 요소에 접근

배열 내 각 요소는 고유한 인덱스(숫자로 나타냄)를 가지며, 이 인덱스를 사용하여 해당 요소에 접근하는 것

```c
// c
int arr[5]
```

```swift
// swift
@frozen
struct Array<Element>
```

## 특징

- **연속된 메모리**
  배열은 연속된 메모리 공간에 저장되므로 메모리 접근 속도를 빠르게 직접 접근 가능

- **인덱스 기반 접근**
  배열의 요소는 인덱스를 통해 `O(1)` 시간 복잡도로 접근

- **고정 크기**
  배열은 선언 시 크기가 고정되며, 이후 크기를 변경 X

- **장점**

  - 탐색에 유리
    인덱스 기반 접근 덕분에 데이터를 빠르게 조회 가능
    메모리가 연속적이라 접근 시간이 일정하고 효율적

- **단점**

  - 크기가 고정

  - 동적으로 크기를 변경하는 것이 어려움

  - 요소의 추가 및 삭제가 비효율적(추가/삭제할 때마다 배열을 재구성해야 할 수 있음)

## 배열의 활용

- **data 저장 및 관리**

  List, table, graph 등의 data를 저장하고 관리할 때 사용


- **알고리즘 구현**

  정렬, 탐색, 그래프 등 다양한 알고리즘을 구현할 때 활용


- **다차원 배열**

  행렬, 이미지, 다차원 데이터 등을 표현할 때 사용


- **컬렉션 관리**

  많은 요소를 한 번에 관리하거나 순회할 때 사용

## CRUD

- **Create/Init(생성)**

  ```swift
  // swift
  var arr: [Int] = [38, 57, 50, 84, 28, 49, 80, 36, 82, 7, 7, 43, 12, 15, 38, 79]

  print(arr)
  // 배열 Create/Init
  // [38, 57, 50, 84, 28, 49, 80, 36, 82, 7, 7, 43, 12, 15, 38, 79]
  ```

  ---


- **Read(읽기)**

  ```swift
  // swift
  print("index 2인 요소: \(arr[2])")
  //배열의 요소 index로 Read
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
  ```

  ---

- **Update(수정)**

  - **append**(맨 뒤 추가)

    ```swift
    // swift
    arr.append(60)
    print(arr)
    // 배열 끝에 요소 추가(Append)
    //[38, 57, 50, 84, 28, 49, 80, 36, 82, 7, 7, 43, 12, 15, 38, 79, 60]
    ```

     <br/>

  - **insert**(특정 index 위치 추가)

    ```swift
    // swift
    arr.insert(5, at: 2)
    print(arr)
    // 배열의 특정 위치에 요소 삽입(인덱스 2에 5 Insert)
    // [38, 57, 5, 50, 84, 28, 49, 80, 36, 82, 7, 7, 43, 12, 15, 38, 79, 60]
    ```

    ---

  - **Update**(요소 인덱스로 접근하여 수정)
    ```swift
    // swift
    arr[1] = 15
    print(arr)
    // 배열 요소를(arr[1] = 15) 교체 (Update)
    // [38, 57, 5, 50, 84, 28, 49, 80, 36, 82, 7, 7, 43, 12, 15, 38, 79, 60]
    ```

    ---

- **Delete**(삭제)

  - **remove**(특정 위치 삭제)

    ```swift
    // swift
    arr.remove(at: 8)
    print(arr)
    //특정 인덱스 8의 요소 Delete
    // [38, 15, 5, 50, 84, 28, 49, 80, 82, 7, 7, 43, 12, 15, 38, 79, 60]
    ```

     <br/>

  - **removeLast**(마지막 요소 삭제)

    ```swift
    // swift
    arr.removeLast()
    print(arr)
    // 배열의 마지막 요소 Delete
    //[38, 15, 5, 50, 84, 28, 49, 80, 82, 7, 7, 43, 12, 15, 38, 79]
    ```

    ---

  - **removeFirst**(배열의 첫번쨰 요소 삭제)

    ```swift
    // swift
    arr.removeFirst()
    print(arr)
    // 배열의 첫번쨰 요소 Delete
    // [15, 5, 50, 84, 28, 49, 80, 82, 7, 7, 43, 12, 15, 38, 79]
    ```

    ---

  - **firstIndex**(첫번쨰 인덱스(0)으로 부터 요소(of: value)인 삭제)

    ```swift
    // swift
    if let index = arr.firstIndex(of: 28) {
       arr.remove(at: index)
    }
    print(arr)
    // 배열 내 특정 값 Delete
    // [15, 5, 50, 84, 49, 80, 82, 7, 7, 43, 12, 15, 38, 79]
    ```

    ---

  - **lastIndex**(마지막 인덱스(배열의 크기 - 1)으로 부터 요소(of: value)인 삭제)

    ```swift
    // swift
    if let index = arr.lastIndex(of: 15) {
       arr.remove(at: index)
    }
    print(arr)
    // 배열 내 특정 값 Delete
    // [15, 5, 50, 84, 49, 80, 82, 7, 7, 43, 12, 38, 79]
    ```

    ---

  - **RemoveAll**(배열 전체 삭제)
    ```swift
    // swift
    arr.removeAll()
    print(arr)
    // 배열 비우기(전체 Delete)
    // []
    ```

    ---

## 바로 공부하기 좋은 알고리즘

- [BruteForce](https://github.com/BOLTB0X/DataStructure-Algorithm/tree/main/Algorithm/BruteForce)



## 참고

- [공식문서 - Array](https://developer.apple.com/documentation/swift/array)

- [위키백과 - 배열](https://ko.wikipedia.org/wiki/%EB%B0%B0%EC%97%B4)

- [블로그 참고 - web-km(배열)](https://web-km.tistory.com/52)

- [블로그 참고 - limecoding(배열)](https://limecoding.tistory.com/78)

- [이미지 생성 - visualgo](https://visualgo.net)
