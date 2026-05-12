#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

ll mulMod(ll a, ll b, ll p) {
    ll res = 0;
    a %= p;
    b %= p;
    while (b > 0) {
        if (b & 1)
            res = (res + a) % p;
        a = (a + a) % p;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b, p;
    cin >> a >> b >> p;
    cout << mulMod(a, b, p) << endl;

    return 0;
}
