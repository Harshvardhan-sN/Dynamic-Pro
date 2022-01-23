#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[107][100010];

ll solve(ll ind,ll amount,vector<ll> &v1,vector<ll> &v2){
    if(amount==0 || ind<0)      return 0;
    if(dp[ind][amount]!=-1)     return dp[ind][amount];
    ll not_pick = solve(ind-1,amount,v1,v2);
    ll pick = 0;
    if(amount-v1[ind]>=0){
        pick = solve(ind-1,amount-v1[ind],v1,v2)+v2[ind];
    }

    return dp[ind][amount] = max(pick,not_pick);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp,-1,sizeof(dp));
    ll n,m;    cin>>n>>m;
    vector<ll> v1,v2;
    for(ll i=0;i<n;i++){
        ll x1,x2;  cin>>x1>>x2;
        v1.emplace_back(x1);
        v2.emplace_back(x2);
    }
    cout<<solve(n-1,m,v1,v2);

    return 0;
}