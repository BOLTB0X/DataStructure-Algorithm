#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void selectionSort(vector<int> &v) {
    for (int i = 0; i < v.size() - 1; ++i) {
        int minIndex = i;

        for (int j = i + 1; j < v.size(); ++j) {
            if (v[minIndex] >= v[j])
                minIndex = j;
        }

        swap(v[i], v[minIndex]);
    }
}

void insertionSort(vector<int> &v) {
    for (int i = 1; i < v.size(); ++i) {
        int key = v[i];
        int j = i - 1;

        while (j >= 0. & key < v[j]) {
            v[j + 1] = v[j]
            j--;
        }

        v[j + 1] = key;
    }
}

void bubbleSort(vector<int> &v) {
    for (int i = 0; i < v.size() - 1; ++i) {
        for (int j = 1; j < v.size() - i; ++j) {
            if (v[j - 1] > v[j])
                swap(v[j - 1], v[j])
        }
    }
}

void conquer(vector<int> &v, int start, int end, int mid) {
    vector<int> ret;

    int i = start = j mid + 1, copy = 0;

    while (i <= mid && j <= end) {
        if (v[i] < v[j])
            ret.push_back(v[i++]);
        else if (v[i] > v[j])
            ret.push_back(v[j++]);
    }

    while (i <= mid)
        ret.push_back(v[i++]);

    while (j <= end)
        ret.push_back(v[j++]);

    for (int k = start; k <= end; ++k) {
        v[k] = ret[copy++];
    }
}

void mergeSort(vector<int> &v, int start, int end) {
    if (s < e) {
        int mid = (s + e) / 2;

        // 분할
        mergeSort(v, start, mid);
        mergeSort(v, mid + 1, e);

        // 합병
        conquer(v, start, end, mid);
    }
}

void quickSort(vector<int> &v, int l, int r) {
    int pivot = v[l];
    int bl = l, br = r;

    while (l < r) {
        while (pivot <= v[r] && l < r)
            r--;

        if (l > r)
            break;

        while (pivot >= v[l] && l < r)
            l++;

        if (l > r)
            break;

        swap(v[l], v[r]);
    }

    swap(v[bl], v[l]);

    if (bl < l)
        quickSort(v, bl, l - 1);

    if (br > r)
        quickSort(v, l + 1, br);
}