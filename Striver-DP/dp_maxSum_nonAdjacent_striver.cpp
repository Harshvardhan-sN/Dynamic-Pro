#include<bits/stdc++.h>
using namespace std;
#define ll long long

int dp[1010],dp2[1010];

int first_approach(int i,vector<int> &v1){
    if(i == 0)    return v1[i];
    if(i < 0)     return 0;
    if(dp[i]!=-1)    return dp[i];
    int left = INT_MIN;
    int right = INT_MIN;

    left = first_approach(i-2,v1)+v1[i];
    right = first_approach(i-1,v1);

    return dp[i] = max(left,right);
}

int second_approach(int i,vector<int> &v1){
    if(i == 0)    return v1[i];
    if(i < 0)     return 0;
    if(dp2[i]!=-1)	return dp2[i];
    int left = INT_MIN;
    int right = INT_MIN;

    left = second_approach(i-2,v1)+v1[i];
    right = second_approach(i-1,v1);

    return dp2[i] = max(left,right);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    memset(dp2,-1,sizeof(dp2));
    int n;      cin>>n;
    vector<int> v1;
    for(int i=0;i<n;i++){
        int c;      cin>>c;
        v1.emplace_back(c);
    }

    cout<<first_approach(n-1,v1)<<endl;
    cout<<second_approach(n-1,v1)<<endl;

    return 0;
}
