#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
  public:
  
    int solve(vector<int> &arr,int i,int j){
        if(j == i){
            return 0;
        }
        int mini = INT_MAX;
        for(int k =i;k<j;k++){
             int ans = arr[i-1]*arr[k]*arr[j] +solve(arr,i,k)+solve(arr,k+1,j);
             cout<<"i = "<<i<<" j = "<<j<<" k = "<<k<<" temp = "<<ans<<endl;
             if(ans < mini) mini = ans;
        }
        cout<<"returning mini = "<<mini<<" for i = "<<i<<" j = "<<j<<endl;
        return mini;
    }
  
    int matrixMultiplication(vector<int> &arr) {
       int n = arr.size();
       return solve(arr,1,n-1);
        
    }
};

int main(){ 
    Solution s;
        vector<int> arr = {10, 20, 30, 40, 50};
        cout<<"ANS => "<<s.matrixMultiplication(arr)<<"<- ans"<<endl;

    
    return 0;
}