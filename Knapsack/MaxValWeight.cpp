#include <stdio.h>


class Solution {
  public:
  
    int solve(vector<int> &val, vector<int> &wt,int i,int mass,vector<vector<int>> &dp,int w){
        if(i >= val.size()){
            return 0;
        }
        if(dp[i][mass] != -1){
            return dp[i][mass];
        }
        int pick = INT_MIN;
        if(mass + wt[i] <= w){
            pick = val[i] + solve(val,wt,i+1,mass+wt[i],dp,w);
        }
        
       
        int skip = solve(val,wt,i+1,mass,dp,w);
        
        
        return dp[i][mass] = max(pick,skip);
        
    }
  
    int knapsack(int w ,vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        int sum = 0;
        for(int x:wt){
            sum += x;
        }
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        
        return solve(val,wt,0,0,dp,w);
        
    }
};

int main() {
    printf("Hello, World!\n");
    return 0;
}
