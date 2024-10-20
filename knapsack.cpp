#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

string simplifyFraction(int numerator, int denominator) {
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
    return to_string(numerator) + "/" + to_string(denominator);
}

void knapsack(vector<int>& items, vector<int>& weights, vector<int>& profits, int capacity) {
    int n = items.size();
    vector<pair<double, int>> PbyW(n); 
    for (int i = 0; i < n; i++) {
        PbyW[i] = { (double)profits[i] / weights[i], i };
    }
    sort(PbyW.begin(), PbyW.end(), greater<pair<double, int>>());
    double totalProfit = 0.0;
    vector<pair<int, string>> selectedItems; 
    for (int i = 0; i < n; i++) {
        int idx = PbyW[i].second; 
        if (capacity >= weights[idx]) {
            capacity -= weights[idx];
            totalProfit += profits[idx];
            selectedItems.push_back({ items[idx], "1" }); 
        } else {
            int numerator = capacity;
            int denominator = weights[idx];
            totalProfit += profits[idx] * ((double)capacity / weights[idx]);
            string fraction = simplifyFraction(numerator, denominator);
            selectedItems.push_back({ items[idx], fraction });
            break; 
        }
    }
    cout << "profit: " << totalProfit << endl;
    for (auto &item : selectedItems) {
        cout << item.first << "=" << item.second << endl;
    }
}

int main() {
    vector<int> items = {1, 2, 3, 4, 5};
    vector<int> weights = {600, 400, 500, 300, 700};
    
    vector<int> profits = {80, 60, 70, 40, 90};
    int capacity = 2000;

    knapsack(items, weights, profits, capacity);
    return 0;
}