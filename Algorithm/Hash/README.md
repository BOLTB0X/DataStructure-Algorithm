# Hash

> data를 특정 규칙을 사용해 "해시 함수"를 통해 변환하여 고유한 값(해시 값 또는 해시 코드)을 얻는 자료구조

<br/>

- **hash** 는 data를 고유한 해시 값으로 변환해 관리하는 방식

  - 검색과 삽입 및 삭제 하는데 시간복잡도 `O(1)`
  - **key(index)** 와 **value(실제 data)** 가 한 쌍으로 존재
    <br/>

- **hash 함수** 는 임의 크기의 데이터를 고정된 크기의 해시 값으로 변환하는 함수
  <br/>

- **hash table** 은 해시 값을 키로 활용하여 빠른 데이터 검색과 삽입을 가능하게 함
  - 배열 기반 자료 구조이며, 각 배열의 인덱스는 해시 값과 연결
  - 새로운 data를 해시 테이블에 저장할 때, 키를 해시 함수에 넣어 해당 데이터가 저장될 인덱스를 결정함
    <br/>
- 충돌 해결 방법이 필요하며, 다양한 알고리즘과 보안 분야에서 널리 사용
  <br/>

## Hash 자료구조

> 각각의 문자(char), 문자열(String)에 대해서, 유일한 Key 값을 가지게 하며
> 만들어진 Key 값을 이용해서 자료에 접근한다면 O(1) 시간만에 접근 가능

<div style="text-align: center;">
    <img src="https://github.com/BOLTB0X/DataStructure-Algorithm/blob/main/Algorithm/Hash/hash.png?raw=true" alt="Example Image" width="90%">
</div>

<br/>

- **hash 함수** 에 의해 `key` -> `index` 로 변환

  ```cpp
  int hashFunction(const char* key) { }

  // ...
  int hashTable[TABLE_SIZE] = {0};

  char* key = "apple";
  int value = 42;
  int i = hashFunction(key);
  hashTable[i] = value;
  ```

  - ASCII 코드 이용
  - `hashFunction` 을 이용하여 배열에 저장

  <br/>

- 이 때 입력이 다르더라도 같은 해시 값을 반환을 수도 있어 주의 필요

  ```cpp
  int hashFunction(const char* key) {
     int hash = 0;
     int length = strlen(key);
     for (int i = 0; i < length; ++i)
         hash = (hash * 31 + key[i]) % TABLE_SIZE;

     return hash;
  }
  ```

  <br/>

## 예시 (직접 구현)

```cpp
#include <iostream>
#include <cstring>

using namespace std;

const int TABLE_SIZE = 10007;

// 간단한 해시 함수
int hashFunction(const char* key) {
    int hash = 0;
    int length = strlen(key);
    for (int i = 0; i < length; ++i)
        hash = (hash * 31 + key[i]) % TABLE_SIZE;

    return hash;
}

int main() {
    int hashTable[TABLE_SIZE] = {0};

    char* key = "apple";
    int value = 42;
    int i = hashFunction(key);
    hashTable[i] = value;

    char* searchKey = "apple";
    int searchIndex = hashFunction(searchKey);

    if (hashTable[searchIndex] != 0) {
        cout << searchKey << ": " << hashTable[searchIndex] << endl;
    }

    else {
        cout << searchKey << ": null" << "\n";
    } // apple: 42

    return 0;
}
```

## unordered_map (STL)

> C++에서 `unordered_map` 은 해시 테이블을 기반으로 구현된 자료 구조, key - value 쌍을 저장하는 컨테이너

- Hash table을 사용하여 data를 관리, key - value 쌍이 해시 함수를 통해 인덱스가 결정되기 때문에, data가 정렬되지 않은 상태로 저장 됌
  <br/>

- **시간 복잡도**

  - 평균적으로 `O(1)`의 시간 복잡도를 갖음 -> 빠르게 검색, 삽입, 삭제가 가능
  - 단, 해시 충돌이 발생할 경우 `O(n)`

  <br/>

- **정렬** : data를 정렬된 상태로 유지 X
  <br/>

- **메모리 사용량**: 많은 메모리를 사용
  <br/>

- `#include <unordered_map>`

## 예시

```cpp
unordered_map<string, int> umap;

// ...

umap["apple"] = 10;
umap["banana"] = 20;
umap["orange"] = 30;

for (const auto& ele : umap) {
  cout << ele.first << " : " << ele.second << '\n';
}
```

```
orange : 30
banana : 20
apple : 10
```

순서 고려 X

## 연습하기 좋은 문제

1. [BOJ-10816(숫자 카드2)](https://www.acmicpc.net/problem/10816)

2. [고득점kit-완주하지 못한 선수](https://school.programmers.co.kr/learn/courses/30/lessons/42576)

3. [고득점kit-베스트앨범](https://school.programmers.co.kr/learn/courses/30/lessons/42579)

## 참고

- [블로그 참조 - kbw1101([C++] 해시(Hash) 자료구조란? (C++로 구현하기))](https://kbw1101.tistory.com/55)

- [블로그 참조 - 기회개발자([C++] STL unordered_set, unordered_map (Hash) 정리 및 사용법)](https://chance-developer.tistory.com/entry/C-STL-unorderedset-unorderedmap-Hash-정리-및-사용법)
