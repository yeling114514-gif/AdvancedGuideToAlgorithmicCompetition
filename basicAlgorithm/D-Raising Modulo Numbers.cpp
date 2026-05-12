#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

ll quickPower(ll a,ll b,ll p){
    ll res=1%p;

    a%=p;
    while(b){
        if(b&1){
            res=(res*a)%p;
        }
        a=a*a%p;
        b>>=1;
    }

    return res%p;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Z;
    cin>>Z;
    while(Z--){
        ll MOD;
        cin>>MOD;
        ll H;
        cin>>H;
        ll sum=0;
        while(H--){
            ll a,b;
            cin>>a>>b;
            sum=(sum+quickPower(a,b,MOD))%MOD;
        }
        cout<<sum<<endl;
    }


    return 0;
}