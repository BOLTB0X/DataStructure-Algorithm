#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // 배열 생성 및 초기화
    std::vector<int> arr = {10, 20, 30, 40, 50};

    // 마지막에 요소 추가
    arr.push_back(60);

    // 특정 위치에 요소 삽입
    arr.insert(arr.begin() + 2, 15);

    // 인덱스를 통한 접근
    std::cout << arr[2] << '\n';
    // at
    std::cout << arr.at(2) << '\n'; // 30

    // 배열 전체 순회
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << "index: " << i << ", value: " << arr[i] << '\n';
    }

    // 범위 기반 for문
    for (int value : arr)
    {
        std::cout << value << '\n';
    }

    // index 1의 값을 100으로 변경
    arr[1] = 100;

    // 마지막 요소 삭제
    arr.pop_back();

    // index 2의 요소 삭제
    arr.erase(arr.begin() + 2);

    // 특정 값 검색 후 삭제
    auto it = std::find(arr.begin(), arr.end(), 40);

    if (it != arr.end())
    {
        arr.erase(it);
    }

    std::cout << "Size: " << arr.size() << '\n';
    std::cout << "Capacity: " << arr.capacity() << '\n';

    // 전체 요소 삭제
    arr.clear();


    return 0;
}