///Range Xor Queries
///https://cses.fi/problemset/task/1650

#include <bits/stdc++.h>
using namespace std;

#define Int long long

const Int mxN = 2e5 + 10;

Int a[mxN];

Int N, Q;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i){
        Int x;
        cin >> x;
        a[i] = a[i - 1] ^ x;
    }
    for (int i = 1; i <= Q; ++i){
        int l, r;
        cin >> l >> r;
        cout << (a[r] ^ a[l - 1]) << endl;
    }
}
