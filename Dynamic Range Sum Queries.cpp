///Dynamic Range Sum Queries
///https://cses.fi/problemset/task/1648
#include<bits/stdc++.h>
#define endl '\n'
#define print(x) cout << (#x) << " is " << x << endl;
using namespace std;
const int mxN = 2e5 + 10;
#define Int long long
Int N, Q;
Int b[mxN];
unordered_map<Int, Int> a;
void update(int x, Int val){
    for (int i = x;i <= N; i += (-i&i))a[i]+= val;
}
Int sum(int x){
    Int Sum = 0;
    for (int i = x; i; i -= (i & -i))Sum += a[i];
    return Sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> Q;
    for(int i = 1; i <= N; ++i){
        cin >> b[i];
        update(i, b[i]);
    }
    while(Q--){
        Int l, r, t;
        cin  >> t >> l >> r;
        if(t == 1){
            update(l, -b[l] + r);
            b[l] = r;
        }
        else cout << sum(r) - sum(l - 1) << endl;
        //for(int j = 1; j <= N; ++j)cout << a[j] << " \n"[j == N];
    }
}
