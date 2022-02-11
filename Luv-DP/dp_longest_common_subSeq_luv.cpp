#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+10;

#define ll long long
#define ll long long
#define nl endl
#define pb push_back

int dp[1007][1007];

int f(int i,int j,string &s1,string &s2){
    if( i < 0 || j < 0 )  return 0;
    if( dp[i][j] != -1)    return dp[i][j];
    int ans = f( i-1, j, s1, s2);
    ans = max( ans, f( i, j-1, s1, s2));
    ans = max( ans, f( i-1, j-1, s1, s2)+( s1[i] == s2[j] ));
    return dp[i][j] = ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;
    memset( dp, -1, sizeof(dp));
    int n = s1.length();
    int m = s2.length();
    cout << f( n-1, m-1, s1, s2);

    return 0;
}