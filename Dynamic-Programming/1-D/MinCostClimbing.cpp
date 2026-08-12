#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution { // Top-Down Approach
public:

    int solve(vector<int>& arr,int i,vector<int>& dp){
        if(i >= arr.size()){
            return 0;
        }
        if(i == arr.size()-1){
            return arr[i];
        }

        if(dp[i] != -1){
            return dp[i];
        }

        return dp[i] =  min(arr[i]+solve(arr,i+1,dp),arr[i]+solve(arr,i+2,dp));

    }

    int minCostClimbingStairs(vector<int>& arr) {
        vector<int> dp(arr.size()+1,-1);
        return min(solve(arr,0,dp),solve(arr,1,dp));
    }
};


int main(){ // Bottom-Up Approach
    vector<int> cost = {10, 15, 20};
    int n = cost.size();
    vector<int> dp(n+1, 0);
    for(int i=2; i<=n; i++){
        dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
    }
    cout << dp[n] << endl;
    return 0;
}