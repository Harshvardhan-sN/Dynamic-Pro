#include<bits/stdc++.h>
using namespace std;

//  House are in cycle

long long int solve(long long int i,vector<int> &v1,vector<long long> &dp){
    if(i == 0)    return v1[i];
    if(i < 0)     return 0;
    if(dp[i]!=-1)	return dp[i];

    long long int left = INT_MIN;
    long long int right = INT_MIN;

    left = solve(i-2,v1,dp)+v1[i];
    right = solve(i-1,v1,dp);

    return dp[i] = max(left,right);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	long long int n;        cin>>n;
    vector<int> valueInHouse;

    for(int i=0;i<n;i++){
        int c;      cin>>c;
        valueInHouse.emplace_back(c);
    }
    vector<long long> dp(n,-1),dp1(n,-1);

    if(n==1){
        cout<<valueInHouse[0];
    }
    else{
        long long int ans1 = solve(n-2,valueInHouse,dp);
        reverse(valueInHouse.begin(),valueInHouse.end());
        long long int ans2 = solve(n-2,valueInHouse,dp1);
        cout<<max(ans1,ans2);
    }


    return 0;
}

