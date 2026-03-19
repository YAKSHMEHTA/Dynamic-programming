#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    int maxUncrossedLinesBU(vector<int>& arr1, vector<int>& arr2){
        int n = arr1.size();
        int m = arr2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));

            for(int i=1;i<=n;i++){
                for(int j =1;j<=m;j++){
                    if(arr1[i-1] == arr2[j-1]){
                        dp[i][j] = 1+dp[i-1][j-1];
                    }else{
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        return dp[n][m];
    }


};

int main(){ 
    Solution s;
    vector<int> nums1 = {1,4,2};
    vector<int> nums2 = {1,2,4};

    cout<<s.maxUncrossedLinesBU(nums1,nums2)<<endl;
    return 0;
}