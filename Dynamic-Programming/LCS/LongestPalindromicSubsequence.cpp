#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    // top down approach
    int solve(string &s1,string &s2,int i1,int i2,vector<vector<int>> &dp){
        if(i1 > s1.size() || i2 >s2.size()){
            return 0;
        }

        if(dp[i1][i2] != -1){
            return dp[i1][i2];
        }

        if(s1[i1] == s2[i2]){
            return 1 + solve(s1,s2,i1+1,i2+1,dp);
        }

        int check = solve(s1,s2,i1+1,i2,dp);
        int next = solve(s1,s2,i1,i2+1,dp);

        return dp[i1][i2] =  max(check,next);
    }

    int longestPalindromeSubseq(string s) {
        string s2 = s;
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        reverse(s2.begin(),s2.end());
        return solve(s,s2,0,0,dp)-1;
    }
};

int main(){ 
    Solution s;
    string str = "bbbab";
    cout<<s.longestPalindromeSubseq(str)<<endl;

    
    return 0;
}