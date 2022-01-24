#include<bits/stdc++.h>
using namespace std;
#define ll long long

int dp[1010];

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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,-1,sizeof(dp));

    int n;      cin>>n;
    vector<int> v1;
    for(int i=0;i<n;i++){
        int c;      cin>>c;
        v1.emplace_back(c);
    }

    cout<<first_approach(n-1,v1)<<endl;


    // **************** Second Approach *********************

    int prev = v1[0];
    int prev2 = 0;
    for(int i=1;i<n;i++){
        int take = v1[i];
        if(i>1) take+=prev2;
        int notTake = prev;
        int current = max(take,notTake);
        prev2 = prev;
        prev = current;
    }
    cout<<prev<<endl;



    return 0;
}
