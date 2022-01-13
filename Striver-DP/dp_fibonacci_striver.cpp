#include<bits/stdc++.h>
using namespace std;

// Fiboncci

int solve(int n,vector<int> &a){
    if(n<=1)    return n;
    if(a[n]!=-1)    return a[n];
    return a[n] = solve(n-1,a)+solve(n-2,a);
}


int main(){
    int n;      cin>>n;
    vector<int> v1(n+1,-1);
    cout<<solve(n,v1);


    return 0;
}