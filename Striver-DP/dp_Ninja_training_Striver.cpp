#include<bits/stdc++.h>
using namespace std;
#define ll long long

int dp[100010][4];

int f(int day,int last, vector<vector<int>> &points){
    if(day==0){
        int maxi = 0;
        for(int task=0;task<3;task++){
            if(task!=last){
                maxi = max(maxi,points[0][task]);
            }
        }
        return maxi;
    }
    if(dp[day][last]!=-1)   return dp[day][last];

    int maxi = 0;
    for(int task=0;task<3;task++){
        if(task!=last){
            maxi = max(maxi,f(day-1,task,points)+points[day][task]);
        }
    }
    return dp[day][last] = maxi;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   cout.tie(NULL);
    // initializing dp array
    memset(dp,-1,sizeof(dp));
    // initializing dp vector
    // vector<vector<int>> dp(100010,vector<int> (4,-1));


    int n;  cin>>n;
    vector<vector<int>> v1;

    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<3;j++){
            int c;  cin>>c;
            temp.push_back(c);
        }
        v1.emplace_back(temp);
    }
    cout<<f(n-1,3,v1)<<endl;

    // *********** Approach 2 *************

    vector<vector<int>> temp(n,vector<int> (4,0));

    temp[0][0] = max(v1[0][1],v1[0][2]);
    temp[0][1] = max(v1[0][0],v1[0][2]);
    temp[0][2] = max(v1[0][1],v1[0][0]);
    temp[0][3] = max({v1[0][1],v1[0][2],v1[0][0]});

    for(int day=1;day<n;day++){
        for(int last=0;last<4;last++){
            temp[day][last] = 0;
            for(int task = 0;task<3;task++){
                if(task!=last){
                    temp[day][last] = max(temp[day][last],
                        temp[day-1][task]+v1[day][task]);
                }
            }
        }
    }
    cout<<temp[n-1][3]<<"\n";

    return 0;
}
