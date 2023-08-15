// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &array, int begin, int mid, int end) {
    vector<int> left(array.begin() + begin, array.begin() + mid);
    vector<int> right(array.begin() + mid, array.begin() + end);

    int leftIdx = 0, rightIdx = 0, arrayIdx = begin;

    while (leftIdx < left.size() && rightIdx < right.size()) {
        if (left[leftIdx] <= right[rightIdx]) {
            array[arrayIdx++] = left[leftIdx++];
        } else {
            array[arrayIdx++] = right[rightIdx++];
        }
    }

    while (leftIdx < left.size()) {
        array[arrayIdx++] = left[leftIdx++];
    }

    while (rightIdx < right.size()) {
        array[arrayIdx++] = right[rightIdx++];
    }
}

void mergesort(vector<int> &array, int begin, int end) {
    if (end - begin > 1) {
        int mid = (end + begin) / 2;
        mergesort(array, begin, mid);
        mergesort(array, mid, end);
        merge(array, begin, mid, end);
    }
}

int main() {
    vector<int> array = {4, 67, 1, 3, 6, 324, 57, 2, 5, 7, 8};
    
    int end = array.size(); int begin = 0;

    mergesort(array, begin, end);
       for(int i = 0; i < array.size(); i++) {
        cout << array[i] << endl;
    }
    return 0;
}
