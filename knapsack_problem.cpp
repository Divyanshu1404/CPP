#include<iostream>
#include<vector>
using namespace std;

int knapsackRec(int W, vector<int>&wt,vector<int>&val, int n){
    if(n==0||W==0){
        return 0;
    }
   int pick = 0;

    if (wt[n - 1] <= W)
        pick = val[n - 1] + knapsackRec(W - wt[n - 1], val, wt, n - 1);
    
    int notPick = knapsackRec(W, val, wt, n - 1);
     
    return max(pick, notPick);
   
}
int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    return knapsackRec(W, val, wt, n);
}
int main() {
    vector<int> val = {1, 2, 3};
    vector<int> wt = {4, 5, 1};
    int W = 4;
    cout<<knapsack(W, val, wt) << endl;
    return 0;
}
