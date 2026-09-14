// ============================================================
// File: max_profit.cpp
// Folder: Dsa
// Purpose: Finds the best profit from stock prices by tracking the minimum price seen so far.
// This file is part of the C++ practice repository and is intended for learning.
// ============================================================

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {

    // Write your solution here
    int maxprofit = 0 ; 
    int min = prices[0] ;

    for(int i = 0;i <prices.size();i++){
        int current = prices[i];
        if(current < min){
            min = current;
        }
        int profit = current - min ; 
        if(profit>maxprofit){
            maxprofit = profit;
        }

   
    
    }
    return maxprofit;

}

int main() {

    int n;
    cin >> n;

    vector<int> prices(n);

    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    cout << maxProfit(prices);

    return 0;
}