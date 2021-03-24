#include<bits/stdc++.h>
#define endl '\n'
#define print(x) cout << (#x) << " is " << x << endl;
using namespace std;
const int mxN = 2e5 + 10;
#define Int long long
Int N, Q;
unordered_map<Int, Int> a;
void update(int node, int s, int e, int p, int val){
    if(s > p || e < p)return;
    if(s == e){
        a[node] = val;
        return;
    }
    int mid = s + e >> 1;
    update(2 * node, s, mid, p, val);
    update(2 * node + 1, mid + 1, e, p, val);
    a[node] = min(a[2 * node], a[2 * node + 1]);
}
int query(int node, int s, int e, int l, int r){
    if(s > r || e < l)return (1 << 30);
    if(s >= l && e <= r)return a[node];
    int mid = s + e >> 1;
    return min(query(2 * node, s, mid, l, r), query(2 * node + 1, mid + 1, e, l, r));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> Q;
    for(int i = 1; i <= N; ++i){
        Int x;
        cin >> x;
        update(1, 1, N, i, x);
    }
    while(Q--){
        Int l, r;
        cin >> l >> r;
        cout << query(1, 1, N, l, r) << endl;
    }
}
