#include<bits/stdc++.h>
using namespace std;
#define ll long long

int dp[207][207];

int solve(int i, int j, vector<vector<int>> &v1){
    if(i>=0 && j>=0 && v1[i][j]==-1)    return 0;

    if(i==0 && j==0){
        return 1;
    }
    if(i<0 || j<0){
        return 0;
    }

    if(dp[i][j]!=-1)    return dp[i][j];
    int left = solve(i-1,j,v1);
    int up = solve(i,j-1,v1);

    return dp[i][j] = left+up;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    int n,m;    cin>>n>>m;
    vector<vector<int>> v1;

    for(int i=0;i<n;i++){
        vector<int> a;
        for(int j=0;j<m;j++){
            int c;  cin>>c;
            a.push_back(c);
        }
        v1.push_back(a);
    }

    cout<<solve(n-1,m-1,v1)<<endl;


    //   *********************** Approach 2 ***************** 

    int dp1[n][m];


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v1[i][j]==-1)    dp1[i][j] = 0;
            else if(i==0 && j==0)   dp1[i][j] = 1;
            else{
                int up = 0,left = 0;
                if(i>0)     up = dp1[i-1][j];
                if(j>0)     left = dp1[i][j-1];
                dp1[i][j] = (up+left);
            }
        }
    }
    cout<<dp1[n-1][m-1]<<endl;


    return 0;
}