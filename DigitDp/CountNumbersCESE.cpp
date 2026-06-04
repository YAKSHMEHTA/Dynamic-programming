#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
#include<string>
#include<cstring>
using namespace std;

using ll = long long;
int dp[20][2][11][2];

int solve(string s,bool t,int idx,int prev,bool lz){
    if(idx == s.size()){
        return 1;
    }
    if(dp[idx][t][prev][lz] != -1) return dp[idx][t][prev][lz];
        ll ans = 0;
        ll lb = 0;
        ll ub = (t == true) ? s[idx] -'0' : 9;

        for(int i = lb;i<=ub;i++){
            if(i == prev && !lz) continue;

            ans += solve(s,((t && i == ub) ? true:false),idx+1,i,(lz && i == 0));

        }

        return dp[idx][t][prev][lz] = ans;

}


int main(){
    // hardcoded input
    ll a = 123;
    ll b = 312;
    memset(dp,-1,sizeof(dp));
    int cnt = 0;

        cnt = solve(to_string(b),true,0,10,true);

    memset(dp,-1,sizeof(dp));
    int cnt2 = 0;

        cnt2 = solve(to_string(a-1),true,0,10,true);

    cout<<cnt - cnt2; 

    return 0;

}