#include<bits/stdc++.h>
using namespace std;
#define ll long long


int solve(int i,vector<int> &v1){
    if(i == 0)    return v1[i];
    if(i < 0)     return 0;
    int left = INT_MIN;
    int right = INT_MIN;

    left = solve(i-2,v1)+v1[i];
    right = solve(i-1,v1);

    return max(left,right);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;      cin>>n;
    vector<int> v1;
    for(int i=0;i<n;i++){
        int c;      cin>>c;
        v1.emplace_back(c);
    }

    cout<<solve(n-1,v1);

    return 0;
}