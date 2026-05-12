// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    int total=1<<n;
    
    vector<vector<int>> dp(total,vector<int>(n,INT_MAX));
    //dp[mask][i]表示状态mask下0到点i的最短距离

    //dp[0][0]理论不存在
    dp[1<<0][0]=0;//dp[1][0]

    for(int mask=1;mask<total;mask++){
        if(!(mask&1)){//最低位代表起点，最低位不在代表起点不可达
            continue;
        }

        for(int i=0;i<n;i++){
            //第i个点
            if(!((mask>>i)&1)){
                continue;
            }
            if(dp[mask][i]==INT_MAX){
                continue;
            }

            //尝试从这个点，往下一个点找最短路径
            for(int next=0;next<n;next++){

                if(mask>>next&1){
                    continue;
                }
                int nextMask=mask|(1<<next);

                dp[nextMask][next]=min(dp[nextMask][next],dp[mask][i]+arr[i][next]);

            }
        }
    }

    cout<<dp[(1<<n)-1][n-1]<<endl;

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.