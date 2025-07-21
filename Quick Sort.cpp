#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    cout << "Nama: [Heru Dwi Setiawan]\n";
    cout << "NIM: 23533823\n";
    cout << "=== Quick Sort (Divide and Conquer) ===\n";
    
    // Berdasarkan digit NIM 23533823
    vector<int> arr = {2, 3, 5, 3, 3, 8, 2, 3};
    
    cout << "Array sebelum sorting:\n";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    quickSort(arr, 0, arr.size() - 1);
    
    cout << "Array setelah sorting:\n";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}