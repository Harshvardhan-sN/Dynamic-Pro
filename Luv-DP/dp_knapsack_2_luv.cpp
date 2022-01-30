#include<bits/stdc++.h>
using namespace std;
#define ll long long

int dp[107][100010];

ll solve(int ind, int val,vector<int> &v1,vector<int> &v2){
    if(val==0)  return 0;
    if(ind<0)   return 1e15;
    if(dp[ind][val]!=-1)    return dp[ind][val];
    ll Pick = solve(ind-1,val,v1,v2);
    ll notPick = 0;
    if(val-v1[ind]>=0){
        ll notPick = solve(ind -1, val-v1[ind],v1,v2) + v2[ind];
    }

    return dp[ind][val] = min(Pick,notPick);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    int n,m;    cin>>n>>m;
    vector<int> v1,v2;

    for(int i=0;i<n;i++){
        int c1,c2;  cin>>c1>>c2;
        v1.push_back(c1);
        v2.push_back(c2);
    }
    int maxVal = 1e5;
    for(int i = maxVal;i>=0;i--){
        if(solve(n-1,i,v1,v2)<=m){
            cout<<i<<endl;
            break;
        }
    }



    return 0;
}