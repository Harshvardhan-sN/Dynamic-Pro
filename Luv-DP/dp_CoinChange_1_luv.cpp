#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> dp(10000,-1);
int g1[310][10010];

 // First Approach
int coin_approach_1(vector<int> &m1, int a){
    if(a==0)    return 0;
    if(dp[a]!=-1)   return dp[a];

    int ans = INT_MAX;
    for(auto &it:m1){
        if(a-it>=0){
            ans = min(ans+0LL,coin_approach_1(m1,a-it)+1LL);
        }
    }
    return dp[a] = ans;
}

// second Approach         ************** INCOMPLETE *************
int coin_approach_2(int ind, vector<int> &v1 ,int amount){
    if(amount==0)   return 1;
    if(ind<0)   return 0;
    if(g1[ind][amount]!=-1)     return g1[ind][amount];

    int ways = INT_MAX;
    for(int i=0;i<=amount;i+=v1[ind]){
        ways = min(ways+0LL,coin_approach_2(ind -1 ,v1,amount-i)+1LL);
    }
    return g1[ind][amount] = ways;
}


int coinChange1(vector<int>& coins, int amount){
    int ans = coin_approach_1(coins,amount);
    return ans == INT_MAX ? -1 : ans;

    // memset(g1,-1,sizeof(g1));
    // int ans = coin_approach_2(coins.size()-1,coins,amount);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,amount;      cin>>n>>amount;
    vector<int> v1;
    for(int i=0;i<n;i++){
        int c;      cin>>c;
        v1.emplace_back(c);
    }
    cout<<coinChange1(v1,amount);

    return 0;
}