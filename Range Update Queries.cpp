#include <bits/stdc++.h>
using namespace std;

#define Int long long

const int mxN = 2e5 + 10;

Int a[2 * mxN];
Int b[mxN];

Int N, Q;

void update(Int x, Int val){
    x += N;
    while(x >= 1){
        a[x] += val;
        x >>= 1;
    }
}

Int query(Int L, Int R){
    L += N, R += N;
    Int S = 0;
    while(L <= R){
        if(L&1)S += a[L++];
        if(~R&1)S += a[R--];
        L >>= 1, R >>= 1;
    }
    return S;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> Q;
    for (Int i = 0; i < N; ++i){
        cin >> b[i];
    }
    for (Int i = 0; i < N; ++i){
        Int x = b[i] - (i > 0 ? b[i - 1] : 0);
        update(i, x);
    }
    for (Int i = 1; i <= Q; ++i){
        Int t;
        cin >> t;
        if(t == 1){
            int l, r, x;
            cin >> l >> r >> x;
            update(l - 1, x);
            if(r < N)update(r, -x);
        }
        else {
            Int r;
            cin >> r;
            cout << query(0, r - 1) << endl;
        }
    }
}
