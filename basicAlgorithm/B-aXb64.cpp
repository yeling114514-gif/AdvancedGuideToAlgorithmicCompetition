#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

ll mul(ll a,ll b,ll p){
    ll ans=0;
    for(;b;b>>=1){
        if(b&1){
            ans=(ans+a)%p;
        }
        a=a*2%p;
    }
    return ans;
}

ull mull(ull a,ull b,ull p){
    a %=p,b%=p;//当a,b一定在0~p之间时，此行不必要
    ull c=(long double)a*b/p;
    ull x=a*b,y =c*p;
    ll ans =(ll)(x%p)-(ll)(y %p);
    if(ans <0)ans +=p;
    return ans;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ull a,b;
    ull p;
    cin>>a>>b>>p;
    cout<<mull(a,b,p)<<endl;

    return 0;
}