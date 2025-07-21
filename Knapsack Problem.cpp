#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int id;
    int weight;
    int profit;
    double ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

void knapsackGreedy(vector<Item>& items, int capacity) {
    // Calculate profit/weight ratio for each item
    for (auto& item : items) {
        item.ratio = (double)item.profit / item.weight;
    }
    
    // Sort items based on ratio in descending order
    sort(items.begin(), items.end(), compare);
    
    int currentWeight = 0;
    double totalProfit = 0.0;
    vector<int> selectedItems;
    
    for (const auto& item : items) {
        if (currentWeight + item.weight <= capacity) {
            selectedItems.push_back(item.id);
            currentWeight += item.weight;
            totalProfit += item.profit;
        }
    }
    
    // Output results
    cout << "\nHasil Knapsack Problem (Greedy):\n";
    cout << "Item yang dipilih: ";
    for (int id : selectedItems) {
        cout << id << " ";
    }
    cout << "\nTotal bobot: " << currentWeight << "/" << capacity;
    cout << "\nTotal profit: " << totalProfit << endl;
}

int main() {
    cout << "Nama: [Heru Dwi Setiawan]\n";
    cout << "NIM: 23533823\n";
    cout << "=== Knapsack Problem (Greedy) ===\n";
    
    // Berdasarkan NIM 23533823
    vector<Item> items = {
        {1, 2, 21, 0},  // Digit 1: 2
        {2, 3, 35, 0},  // Digit 2: 3
        {3, 5, 70, 0},  // Digit 3: 5
        {4, 3, 42, 0},  // Digit 4: 3
        {5, 3, 80, 0},  // Digit 5: 3
        {6, 8, 20, 0},  // Digit 6: 8
        {7, 2, 10, 0},  // Digit 7: 2
        {8, 3, 5, 0}    // Digit 8: 3
    };
    
    int capacity = 15;
    
    // Tampilkan daftar item
    cout << "Daftar Item:\n";
    cout << "ID\tWeight\tProfit\n";
    for (const auto& item : items) {
        cout << item.id << "\t" << item.weight << "\t" << item.profit << endl;
    }
    cout << "Kapasitas maksimal: " << capacity << endl;
    
    knapsackGreedy(items, capacity);
    
    return 0;
}