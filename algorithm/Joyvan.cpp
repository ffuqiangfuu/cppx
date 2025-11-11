#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void swapRows(vector<vector<int>>& arr, int x, int y) {
    if (x < arr.size() && y < arr.size()) {
        swap(arr[x], arr[y]);
    }
}


void swapCols(vector<vector<int>>& arr, int x, int y) {
    if (arr.empty()) {
        return; // 
    }
    int numRows = arr.size();
    if (x < arr[0].size() && y < arr[0].size()) {
        
        for (int i = 0; i < numRows; i++) {
            swap(arr[i][x], arr[i][y]);
        }
    }
}


int getValue(vector<vector<int>>& arr, int x, int y) {
    return arr[x][y];
}

int main() {
    cout << "helloworld" << endl;
    return 0;
}