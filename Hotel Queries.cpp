#include <bits/stdc++.h>
using namespace std;

#define Int long long

const Int mxN = 2e5 + 10;

Int a[4 * mxN];

Int N, Q;

void update(Int x, Int val){
    x += N;
    a[x] = val;
    x >>= 1;
    while(x){
        a[x] = max(a[2 * x], a[2 * x + 1]);
        x >>= 1;
    }
}

Int query(Int x){
    if(a[1] < x)return -1;
    Int k = 1;
    while(k < N){
        if(a[2 * k] >= x)k <<= 1;
        else k <<= 1, k++;
    }
    return k - N;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> Q;
    int n = N;
    N = ceil(1.0 * log2(1.0 * N));
    N = 1ll << N;
    for (int i = 0; i < n; ++i){
        Int x;
        cin >> x;
        update(i, x);
    }
    for (int k = 1; k <= Q; ++k){
        Int x;
        cin >> x;
        Int i = query(x);
        cout << i + 1 << endl;
        if(i >= 0){
            x = a[i + N] - x;
            update(i, x);
        }
    }

}
