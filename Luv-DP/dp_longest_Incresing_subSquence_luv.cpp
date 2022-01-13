#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 25e2+10;
vector<int> dp(N,-1);

int solve(int i,vector<int> &it){
    if(dp[i]!=-1)    return dp[i];
    int ans = 1;
    for(int j=0;j<i;++j){
        if(it[i]>it[j]){
            ans = max(ans,solve(j,it)+1);
        }
    }
    return dp[i] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;  cin>>n;
    vector<int> v1;
    for(int i=0;i<n;i++){
        int c;  cin>>c;
        v1.emplace_back(c);
    }
    int cc = 0;
    for(int i=0;i<n;i++){
        cc = max(cc,solve(i,v1));
    }
    cout<<cc;

    return 0;
}