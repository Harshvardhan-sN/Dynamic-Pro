#include<bits/stdc++.h>
using namespace std;


int frog1(int i,vector<int> &v1,vector<int> &dp){
    if(i==0)    return 0;
    if(dp[i]!=-1)   return dp[i];
    int left = frog1(i-1,v1,dp) + abs(v1[i]-v1[i-1]);
    int right = INT_MAX;
    if(i>1)     right = frog1(i-2,v1,dp) + abs(v1[i]-v1[i-2]);

    return dp[i] = min(left,right);
}
int frog2(int i,vector<int> &v1,vector<int> &dp,int k){
    if(i==0)    return 0;
    if(dp[i]!=-1)   return dp[i];
    int cc = INT_MAX;
    for(int j=1;j<=k;j++){
        if(i-j>=0){
            cc = min(cc,frog2(i-j,v1,dp,k)+abs(v1[i]-v1[i-j]));
        }
    }
    return dp[i] = cc;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;      cin>>n>>k;
    vector<int> v1,v2(n+1,-1);
    for(int i=0;i<n;i++){
        int c;      cin>>c;
        v1.emplace_back(c);
    }
    // cout<<frog1(n-1,v1,v2);

    cout<<frog2(n-1,v1,v2,k);

    return 0;
}