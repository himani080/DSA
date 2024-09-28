#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int calorieLimit, vector<int>& calories, vector<int>& nutritionalValue, int n, vector<int>& includedItems) {
    vector<vector<int>> dp(n + 1, vector<int>(calorieLimit + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= calorieLimit; w++) {
            if (calories[i - 1] <= w) {
                if (dp[i - 1][w] < dp[i - 1][w - calories[i - 1]] + nutritionalValue[i - 1]) {
                    dp[i][w] = dp[i - 1][w - calories[i - 1]] + nutritionalValue[i - 1];
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    // Backtrack to find the included items
    int w = calorieLimit;
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            includedItems.push_back(i - 1);
            w -= calories[i - 1];
        }
    }
    
    // Print the cost matrix
    cout << "Cost Matrix (DP Table):\n";
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= calorieLimit; w+=100) {
            cout << dp[i][w] << "\t";
        }
        cout << endl;
    }
    
    return dp[n][calorieLimit];
}

int main() {
    vector<int> calories = {600, 400, 500, 300, 700};
    vector<int> nutritionalValue = {80, 60, 70, 40, 90};
    int calorieLimit = 2000; 
    int n = calories.size();
    
    vector<int> includedItems;
    int maxNutritionalValue = knapsack(calorieLimit, calories, nutritionalValue, n, includedItems);
    
    cout << "Maximum Nutritional Value: " << maxNutritionalValue << endl;
    
    // Print included items
    cout << " list ";
    for (int i : includedItems) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
