#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+10;

#define ll long long
#define ll long long
#define nl endl
#define pb push_back
#define all(x) x.begin(),x.end()
#define meme(x) memset(x,-1,sizeof x);

int dp[210][20010];

bool solve(int i,int sum,vector<int> &v1){
    if(sum==0)  return true;
    if(i<0)     return false;
    if(dp[i][sum]!=-1)  return dp[i][sum];
    // not pick
    bool ispossible = solve(i-1,sum,v1);
    // pick
    if(sum-v1[i]>=0)
        ispossible |= solve(i-1,sum-v1[i],v1);
    return dp[i][sum] = ispossible;
}

bool canPartition(vector<int>& nums) {
    meme(dp);
    int n = nums.size();
    int sum = accumulate(all(nums),0);
    if(sum%2!=0)    return false;
    sum = sum/2;
    return solve(n-1,sum,nums);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;  cin>>n;
    vector<int> v1;
    for(int i=0;i<n;i++){
        int c;  cin>>c;
        v1.pb(c);
    }
    cout<<boolalpha;
    cout<<canPartition(v1)<<nl;







    return 0;
}
