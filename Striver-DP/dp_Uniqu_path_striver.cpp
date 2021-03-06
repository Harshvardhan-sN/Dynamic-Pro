#include<bits/stdc++.h>
using namespace std;
#define ll long long

int dp[17][17];

// DP Solution
int solve(int i, int j){
    if(i==0 && j==0){
        return 1;
    }
    if(i<0 || j<0){
        return 0;
    }
    if(dp[i][j]!=-1)    return dp[i][j];
    int left = solve(i-1,j);
    int up = solve(i,j-1);

    return dp[i][j] = left+up;
}

// Optimal Solution
int uniquePaths(int m, int n) {
	int N = n+m-2;
    int r = m-1;
    double ans = 1;
    for(int i=1;i<=r;i++){
        ans = ans*(N-r+i)/i;
    }
    return int(ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp,-1,sizeof(dp));
    int t;  cin>>t;
    while(t--){
        int n,m;    cin>>n>>m;
        cout<<solve(n-1,m-1)<<endl;

        cout<<uniquePaths(n,m)<<endl;
    }


    return 0;
}
