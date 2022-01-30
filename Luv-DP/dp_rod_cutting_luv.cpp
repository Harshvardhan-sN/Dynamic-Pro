#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+10;

#define ll long long
#define ll long long
#define nl endl
#define pb push_back

int dp[1007];

int solve(int len,vector<int> &v1){
    if(len==0)  return 0;
    int ans = 0;
    if(dp[len]!=-1)     return dp[len];
    for(int length=1;length<=len;length++){
        if(len-length>=0)
            ans = max(ans,solve(len-length,v1)+v1[length-1]);
    }

    return dp[len] = ans;
}

int cutRod(int price[], int n) {
    vector<int> v1(price,price+n);
    memset(dp,-1,sizeof dp);
    return solve(n,v1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;  cin>>n;
    int v1[n];
    for(int i=0;i<n;i++){
        cin>>v1[i];
    }

    cout<<cutRod(v1,n);

    return 0;
}