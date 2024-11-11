#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

const int TABLE_SIZE = 10007;

// 간단한 해시 함수
int hashFunction(const char* key) {
    int hash = 0;
    int length = strlen(key);
    for (int i = 0; i < length; ++i)
        hash = (hash * 31 + key[i]) % TABLE_SIZE;  // 31은 흔히 사용하는 해시 상수

    return hash;
}

int main() {
    int hashTable[TABLE_SIZE] = {0};
    unordered_map<string, int> umap;

    char* key = "apple";
    int value = 42;
    int i = hashFunction(key);
    hashTable[i] = value;

    char* searchKey = "apple";
    int searchIndex = hashFunction(searchKey);

    if (hashTable[searchIndex] != 0) {
        cout << searchKey << ": " << hashTable[searchIndex] << endl;
    } else {
        cout << searchKey << ": null" << "\n";
    } // apple: 42

    umap["apple"] = 10;
    umap["banana"] = 20;
    umap["orange"] = 30;

    for (const auto& ele : umap) {
        cout << ele.first << " : " << ele.second << endl;
    }
    
// orange : 30
// banana : 20
// apple : 10

    return 0;
}
