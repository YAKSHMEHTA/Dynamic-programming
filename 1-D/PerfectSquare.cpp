#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;    

class SolutionBU { // bottom up approach
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            for(int j =1;j*j<=n;j++){
                if(j*j <= i){
                    dp[i] = min(dp[i],1+dp[i - (j*j)]);
                }
            }
        }
        return dp[n];
    }
};

class Solution { // top down approach
public:

int ps(int n, vector<int>& dp) {
    if (n <= 0) return 0;

    if (dp[n] != -1) return dp[n];

    int ans = INT_MAX;

    for (int i = 1; i * i <= n; i++) {
        ans = min(ans, 1 + ps(n - (i * i), dp));
    }

    return dp[n] = ans;
}

    int numSquares(int n) {
      vector<int> dp(n + 1, -1);
      return ps(n,dp);
        
    }
};

int main() {
    Solution sol;
    int n = 12;
    cout << "The least number of perfect square numbers which sum to " << n << " is: " << sol.numSquares(n) << endl;
    return 0;
}