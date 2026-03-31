#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

// https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/
// Top-Down Approach

int solve(string s, int i, int j, bool isTrue, unordered_map<string,int> &mp){
    if(i > j){
        return 0;
    }

    if(i == j){
        if(isTrue){
            if(s[i] == 'T'){
                return 1;
            }else{
                return false;
            }
        }else{
            if(s[i] == 'T'){
                return 0;
            }else{
                return 1;
            }
        }
    }

    string st = "";
    st.append(to_string(i));
    st.append(" ");    st.append(to_string(j));
    st.append(" ");    st.append(to_string(isTrue));
    if(mp.find(st) != mp.end()){
        return mp[st];
    }

    int ans = 0;
    for(int k =i+1;k<j;k+= 2){
        int lt = solve(s,i,k-1,true,mp);
        int rt = solve(s,k+1,j,true,mp);
        int lf = solve(s,i,k-1,false,mp);
        int rf = solve(s,k+1,j,false,mp);
        
        if(s[k] == '|'){
            if(isTrue){
                ans += lt*rt +lt*rf+rt*lf;
            }else{
                ans += lf+rf;
            }
        }else if(s[k] == '&'){
            if(isTrue){
                ans += rt*lt;
            }else{
                ans += rf*lf+lt*rf+lf*rt;
            }
        }else if(s[k] == '^'){
            if(isTrue){
                ans += rf*lt+lf*rt;
            }else{
                ans += rf*lf+rt*lt;
            }
        }
    }

    return mp[st] = ans;

}

int main(){ 
    string s = "T|F&F^T";
    unordered_map<string,int> mp;
    cout<<solve(s,0,s.size()-1,true,mp)<<endl;
    
    return 0;
}