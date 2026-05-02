#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

//然后我就发现，他明明可以用DFS表示，然后递归思路反而更难懂

int n,r;
int ans[25];//用来输出答案的数组，r在20以内

void DFS(int pos,int start){

    //比如，pos为1，start为1
    if(pos>r){
        //结束条件：说明现在枚举到第r+1个位置了，肯定不能输出r+1个数啊
        //于是输出

        for(int i=1;i<=r;i++){
            cout<<setw(3)<<ans[i];
        }
        cout<<endl;
        return ;

    }

    //第一个位置从1枚举到n
    //第i 个位置从i枚举到n
    for(int i=start;i<=n;i++){
        //
        ans[pos]=i;
        DFS(pos+1,i+1);//

    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    cin>>n>>r;
    
    DFS(1,1);

    return 0;
}