#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<vector<int>> dist (n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>dist[i][j];
        }
    }

    int total = 1<<n;//2^n
    vector<vector<int>> dp(total,vector<int>(n,INT_MAX));
    //dp[mask][i]表示已经访问过的点集为mask,当前位于点i时的最短路径
    dp[1<<0][0]=0;
    
    for(int mask=1;mask<total;mask++){
        if(!(mask&1)){//如果这个路径方式不包含起点，（起点位置为0）
            continue;
        }
        for(int i=0;i<n;i++){
            if(!((mask>>i)&1)){//如果第i个点没在集合里,意味着人在一个没访问的点上
                continue;
            }
            if(dp[mask][i]==INT_MAX){//这个点从起点无法到达
                continue;
            }
            for(int j=0;j<n;j++){
                if(mask>>j&1){
                    //此点已经访问(不重不漏)
                    continue;
                }
                int nextMask=mask|(1<<j);//将第j个点加入集合
                dp[nextMask][j]=min(dp[nextMask][j],dp[mask][i]+dist[i][j]);
            }
        }
    }

    int full=(1<<n)-1;
    cout<<dp[full][n-1]<<endl;

    return 0;
}