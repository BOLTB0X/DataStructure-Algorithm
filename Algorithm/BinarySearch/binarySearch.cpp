#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print_arr(vector<int> arr)
{
    for (int a: arr)
        cout << a << ' ';
    cout << '\n';
}

// int binary_Search(vector<int> arr, int target, int start, int end)
// {
//     if (start > end)
//         return -1;

//     int mid = (start + end) / 2;

//     if (arr[mid] == target)
//         return mid;

//     if (arr[mid] > target)
//         return binary_Search(arr, target, start, mid - 1);
    
//     return binary_Search(arr, target, mid + 1, end);
// }

int binary_Search(vector<int> arr, int target)
{
    int start = 0, end = arr.size() - 1, mid = 0;
    
    while (start <= end)
    {
        mid = (start + end) / 2;

        if (arr[mid] == target)
            break;

        if (arr[mid] > target)
            end = mid - 1;
        else if (arr[mid] < target)
            start = mid + 1;
    }

    return mid;
}

int main(void) {
    vector<int> arr = {0, 1, 2, 3, 5, 7, 9, 10, 11, 13, 19, 22};

    print_arr(arr);

    // cout << "arr 내 7의 인덱스: " << binary_Search(arr, 7, 0, arr.size()-1) << '\n';
    // cout <<  "arr 내 55이 없으므로 -> " <<binary_Search(arr, 55, 0, arr.size()-1) << '\n';

    cout << "arr 내 7의 인덱스: " << binary_Search(arr, 7) << '\n';
    cout << "arr 내 55이 없으므로 -> " << binary_Search(arr, 55) << '\n';

    cout << binary_search(arr.begin(), arr.end(), 11) << '\n';

    return 0;
}