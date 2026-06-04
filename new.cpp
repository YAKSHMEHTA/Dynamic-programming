#include <iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;

int solve(vector<vector<int>> &arr, int i, int j)
{
    int n = arr.size();



    if(i >= n && j>= arr[i].size()){
        return INT_MIN;
    }

    int pick = solve(arr, i, j + 1);
    if (pick != INT_MAX)
    {
        pick += arr[i][j];
    }
    int skip = solve(arr, i + 1, j);

    return min(pick, skip);
}

int main()
{
    // triangle dp
    vector<vector<int> > arr = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};

    int n = arr.size();

    cout<<(arr, 0, 0);
    return 0;
}