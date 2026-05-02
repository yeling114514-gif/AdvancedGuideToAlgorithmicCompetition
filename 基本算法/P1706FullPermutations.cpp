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
    vector<int> arr(n);
    iota(arr.begin(),arr.end(),1);

    do{

        for(int i=0;i<n;i++){
            cout<<setw(5)<<arr[i];
        }
        cout<<endl;

    }while(next_permutation(arr.begin(),arr.end()));

    return 0;
}