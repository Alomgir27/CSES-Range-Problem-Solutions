//Static Range Sum Queries
///https://cses.fi/problemset/task/1646
#include<bits/stdc++.h>
#define endl '\n'
#define print(x) cout << (#x) << " is " << x << endl;
using namespace std;
const int mxN = 2e5 + 10;
#define Int long long
Int N, Q;
Int a[mxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> Q;
    for(int i = 1; i <= N; ++i){
        Int x;
        cin >> x;
        a[i] = a[i - 1] + x;
    }
    while(Q--){
        Int l, r;
        cin >> l >> r;
        cout << a[r] - a[l - 1] << endl;
    }
}
