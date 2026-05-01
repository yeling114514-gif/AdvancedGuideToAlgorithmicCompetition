#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

bool checkState(int State){//行内冲突
    return !(State&(State<<1));
}

int getRowScore(const vector<vector<int>> &grid,int row,int state){

    int sum=0;
    int m=grid[0].size();
    for(int j=0;j<m;j++){
        if((state>>j)&1){
            sum+=grid[row][j];
        }
    }
    return sum;

} 

bool noConflict(int cur,int prev){
    return(!((cur&prev)||(cur&(prev>>1))||(cur&(prev<<1))));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>>  grid(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>grid[i][j];
            }
        }

        vector<int> vaildStates;
        for(int i=0;i<(1<<m);i++){
            if(checkState(i)){
                vaildStates.push_back(i);
            }
        }

        int totalSize=vaildStates.size();

        vector<vector<int>> rowScore(n,vector<int> (totalSize,0));
        //第i行采取状态a的得分
        for(int i=0;i<n;i++){
            for(int j=0;j<totalSize;j++){
                rowScore[i][j]=getRowScore(grid,i,vaildStates[j]);//vaildStates[j]一定是合法的
            }
        }

        vector<vector<int>> dp(n,vector<int> (totalSize,0));
        for(int i=0;i<totalSize;i++){
            dp[0][i]=rowScore[0][i];
        }


        for(int i=1;i<n;i++){//行
            for(int j=0;j<totalSize;j++){//状态
                
                int curState = vaildStates[j];//当前行的状态
                int best=0;//当前行的状态和上一行的状态不冲突，且上一行的状态得分最大

                for(int prev=0;prev<totalSize;prev++){//上一行的状态
                    int prevState=vaildStates[prev];//上一行的状态
                    if(noConflict(curState,prevState)){//当前行的状态和上一行的状态不冲突
                        best=max(dp[i-1][prev],best);//上一行的状态得分最大
                    }
                }

                dp[i][j]=best+rowScore[i][j];//当前行的状态得分加上上一行的状态得分最大值

            }
        }

        int ans=0;
        for(int i=0;i<totalSize;i++){
            ans=max(ans,dp[n-1][i]);//最后一行的所有状态取最大值
        }

        cout<<ans<<endl;

    }


    return 0;
}