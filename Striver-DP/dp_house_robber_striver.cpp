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

long long int second_approach(vector<long long> &v1){
    long long int n = v1.size();
    long long int prev = v1[0];
    long long int prev2 = 0;
    for(int i=1;i<n;i++){
        long long int take = v1[i];
        if(i>1) take+=prev2;
        long long int notTake = prev;
        long long int current = max(take,notTake);
        prev2 = prev;
        prev = current;
    }
    return prev;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //  ******************  Input
	long long int n;        cin>>n;
    vector<int> valueInHouse;
    for(int i=0;i<n;i++){
        int c;      cin>>c;
        valueInHouse.emplace_back(c);
    }

    // *********************  DP array
    vector<long long> dp(n,-1),dp1(n,-1);

    // **********************  first approach
    if(n==1){
        cout<<valueInHouse[0];
    }
    else{
        long long int ans1 = solve(n-2,valueInHouse,dp);
        reverse(valueInHouse.begin(),valueInHouse.end());
        long long int ans2 = solve(n-2,valueInHouse,dp1);
        cout<<max(ans1,ans2)<<endl;
    }

    //   *************** Second Approach *********************

    vector<long long> temp1,temp2;
    for(int i=0;i<n;i++){
        if(i!=0)    temp1.push_back(valueInHouse[i]);
        if(i!=n-1)    temp2.push_back(valueInHouse[i]);
    }

    if(n==1)    cout<<valueInHouse[0];
    else{
        cout<<max(second_approach(temp1),second_approach(temp2));
    }

    return 0;
}

