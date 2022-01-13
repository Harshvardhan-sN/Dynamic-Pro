#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int ans[N],dp[N],k=0;

int frog1(int i){
    if(i==0)    return 0;
    if(dp[i]!=-1)   return dp[i];
    int cost = INT_MAX;

    cost = min(cost,frog1(i-1)+abs(ans[i]-ans[i-1]));
    if(i>1)
        cost = min(cost,frog1(i-2)+abs(ans[i]-ans[i-2]));
    return dp[i] = cost;
}

int frog2(int i){
    if(i==0)    return 0;
    if(dp[i]!=-1)   return dp[i];
    int cost = INT_MAX;
    for(int j=1;j<=k;j++){
        if(i-j>=0)
        cost = min(cost,frog2(i-j)+abs(ans[i]-ans[i-j]));
    }
    return dp[i] = cost;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    int n;  cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>ans[i];
    }
    cout<<frog1(n-1)<<endl;
    cout<<frog2(n-1)<<endl;

    return 0;
}