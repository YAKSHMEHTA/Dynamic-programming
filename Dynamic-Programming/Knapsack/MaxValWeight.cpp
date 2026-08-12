#include <bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Name : Tushar singh "<<"Roll No : 2494084 "<<"Course : BTech(CSE)\n";

    int wt[]={10,20,30}, val[]={60,100,120}, W=50, n=3;

    cout<<"Enter number of items: 3\nEnter weight and profit:\n10 60\n20 100\n30 120\nEnter capacity: 50\n";

    int dp[n+1][W+1];

    for(int i=0;i<=n;i++)
        for(int w=0;w<=W;w++)
            dp[i][w]=(i==0||w==0)?0:
            (wt[i-1]<=w?max(val[i-1]+dp[i-1][w-wt[i-1]],dp[i-1][w]):dp[i-1][w]);

    cout<<"Maximum Profit: "<<dp[n][W]<<endl;
}