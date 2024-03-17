#include<bits/stdc++.h>
using namespace std;


int minimumSwaps(vector<int>& arr) {
    int n = arr.size();
    vector<int> sortedArr(arr);
    sort(sortedArr.begin(), sortedArr.end());
    vector<bool> visited(n, false);
    int swaps = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] || arr[i] == sortedArr[i]) {
            continue;
        }
        int j = i;
        int cycle_size = 0;
        while (!visited[j]) {
            visited[j] = true;
            j = find(sortedArr.begin(), sortedArr.end(), arr[j]) - sortedArr.begin();
            cycle_size++;
        }
        swaps += cycle_size - 1;
    }
    return swaps;
}

int main() {
    vector<int> arr(7);
    for(int i=0;i<7;i++){
        cin>>arr[i];
    }
    int swaps = minimumSwaps(arr);
    cout << "Minimum number of swaps required to sort the array in descending order: " << swaps << endl;
    return 0;
}