#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll quickPow(ll a, ll b, ll p)
{
    ll res = 1 % p; // 处理 p = 1 的情况
    // ll res=1;

    a %= p;
    while (b)
    {
        if (b & 1)
            res = (__int128)res * a % p;
        a = (__int128)a * a % p;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b, p;
    cin >> a >> b >> p;
    cout << quickPow(a, b, p) << endl;
    return 0;
}