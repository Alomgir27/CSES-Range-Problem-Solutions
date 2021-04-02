///https://cses.fi/problemset/task/1649
#include <bits/stdc++.h>
using namespace std;
#define Int long long

const Int mxN  = 2e5 + 10;

Int a[2 * mxN];
Int N, Q;

void update(int x, int val){
    x += N;
    a[x] = val;
    x >>= 1;
    while(x){
        a[x] = min(a[2 * x], a[2 * x + 1]);
        x >>= 1;
    }
}

Int query(int L, int R)
{
    L += N, R += N;
    Int mn = (1ll << 60);
    while(L <= R){
        if(L & 1)mn = min(mn, a[L++]); ///L is Left child
        if(!(R & 1))mn = min(mn, a[R--]);/// R is Right child
        L >>= 1, R >>= 1;
    }
    return mn;

}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i)
    {
        Int x;
        cin >> x;
        update(i, x);

    }
    for (int i = 1; i <= Q; ++i){
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1){
            update(l, r);
        } else cout << query(l, r) << endl;
    }
}
