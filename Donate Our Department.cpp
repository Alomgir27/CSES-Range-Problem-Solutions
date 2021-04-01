///https://toph.co/p/donate-our-department
#include<bits/stdc++.h>
using namespace std;

#define Int long long

const Int mxN = 2e5 + 10;

const Int inf = 1000000000000000000ll;

Int a[2 * mxN];

Int N, Q;

void update(int node, int s, int e, int p, Int v)
{
    if(s > p || e < p)return;
    if(s == e){
        a[node] = v;
        return;
    }
    int mid = s + e >> 1;
    update(2 * node, s, mid, p, v);
    update(2 * node + 1, mid + 1, e, p, v);
    a[node] = min(a[2 * node], a[2 * node + 1]);
}
Int query(int node, int s, int e, int l, int r)
{
    if(s > r ||e < l)return 1e18 + 10;
    if(s >= l && e <= r){
        return a[node];
    }
    int mid = s + e >> 1;
    return min(query(2 * node, s, mid, l, r), query(2 * node + 1, mid + 1, e, l, r));
}
Int L[mxN], R[mxN];
Int arr[mxN];
Int find(Int x, Int y){
    if(y < x)return 0;
    Int ok = query(1, 1, N, x, y);
    if(ok == inf) ok = 0;
    return (y - x + 1) * ok;
}
Int ans[mxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; ++i){
        cin >> arr[i];
        if(arr[i] == -1)update(1, 1, N, i, inf);
        else update(1, 1, N, i, arr[i]);
    }
    int idx = -1, f = 1;
    for (int i = 1; i <= N; ++i){
        if(arr[i] != -1 && f){
            idx = i;
            f = 0;
        }
        else if(arr[i] == -1){
            f = 1;
        }
        if(!f)L[i] = idx;
        else L[i] = -1;
    }
    f = 1, idx = -1;
    for (int i = N; i >=1; --i){
        if(arr[i] != -1 && f){
            idx = i;
            f = 0;
        }
        else if(arr[i] == -1){
            f = 1;
        }
        if(!f)R[i] = idx;
        else R[i] = -1;
    }
    for (int i = 1; i <= N; i++){
        if(L[i] != -1 && R[i] != -1 && L[i] == L[i - 1] && R[i] == R[i - 1])
              continue;
        else if(L[i] != -1 && R[i] != 1){
            ans[i] = find(L[i], R[i]);
        }
    }
    L[N + 1] = N + 1;
    for (int i = N; i >= 1; --i){
        if(L[i] == -1)L[i] = L[i + 1];
    }
    for (int i = N; i >= 1; --i){
        if(R[i] == -1)R[i] = R[i + 1];
    }
    for (int i = 1; i <= N; ++i){
        ans[i] = ans[i] + ans[i - 1];
    }
    cin >> Q;
    for (int i = 1; i <= Q; ++i){
        Int l , r;
        cin >> l >> r;
            Int sum = 0;
            Int x = max(L[l], l);
            if(x == L[l])l--;
            else {
                Int ok = find(l, min(R[l], r));
                sum += ok;
                l = min(R[l], r);
            }
            Int y = min(R[r], r);
            if(y != R[r]){
                Int ok = find(max(L[r], l + 1), r);
                sum += ok;
                r = max(L[r], l + 1) - 1;
            }
            if(l <= r){
                sum += (ans[r] - ans[l]);
            }
          cout << sum << endl;
    }
}
