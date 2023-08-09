#include <iostream>
#include <vector>

using namespace std;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

vector<int> boobleSort(vector<int> n, int s) {
    for(int i = 0; i < s; i++) {
        for(int j = i; j < s; j++) {
            if (n[i] > n[j]) {
                swap(&n[i], &n[j]);
            }
        }
    }
    
    return n;
}

int main() {
    vector<int> n = {10, 5, 4, 2, 7, 8, 9, 1, 3, 6};
    
    n = boobleSort(n, n.size());
    
    // log
    for(int i = 0; i <= n.size() - 1; i++) {
       cout << n[i] << " ,";
    }

    return 0;
}
