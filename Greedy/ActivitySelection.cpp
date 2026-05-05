#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {

        int n = start.size();
        vector<vector<int>> arr;
        
        for(int i=0;i<n;i++){
            arr.push_back({finish[i], start[i]});
        }
        
        sort(arr.begin(), arr.end());
        
        int starti = arr[0][0];
        int endi = arr[0][0];
        int count =1;
        for(int i=1;i<n;i++){
            if(arr[i][1] > endi){
                endi = arr[i][0];
                count++;
            }
        }
        return count;
    }
};

int main(){

    Solution sol;
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};

    cout << sol.activitySelection(start, finish) << endl;

    return 0;
}