#include<bits/stdc++.h>
using namespace std;
const int M = 1e5+10;
int dp[M];

                            // TOP DOWN    Fibonacci

int fibonacci(int i){
    if(i==0)    return 0;
    if(i==1)    return 1;
    if(dp[i]!=-1)   return dp[i];
    return dp[i] = fibonacci(i-1) + fibonacci(i-2);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp,-1,sizeof(dp));
    int n;  cin>>n;
    cout<<fibonacci(n);


    return 0;
}