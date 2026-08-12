#include<iostream>
#include<vector>
using namespace std;



class Solution {
public:

    int solve(vector<int>& nums1, vector<int>& nums2,int i1,int i2,vector<vector<int>> &dp){
        if(i1 >=nums1.size() || i2 >= nums2.size()){
            return 0;
        }
        
        if(dp[i1][i2] != -1){
            return dp[i1][i2];
        }
        if(nums1[i1] == nums2[i2]){
            return dp[i1][i2] =  1+solve(nums1,nums2,i1+1,i2+1,dp);
        }
        int pick = solve(nums1,nums2,i1+1,i2,dp);
        int skip = solve(nums1,nums2,i1,i2+1,dp);
        return dp[i1][i2]  =max(pick,skip);
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        return solve(nums1,nums2,0,0,dp);
    }
};

int main(){



    return 0;
}