#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define Fi(a, n) for (int i = a; i < n; i++)
#define Fd(n, a) for (int i = n; i >= a; i--)
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define pb push_back
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define read(a) for (int i = 0; i<sz(a); i++) cin >> a[i]
const ll mod = 1e9 + 7;
vector<ll> seeg;
vector<ll> a;
void build(int l, int r, int v){
    if (l == r){
        seeg[v] = a[l];
        return;
    }else{
        int mid = (l + r)/2;
        build(l, mid, v * 2);
        build(mid + 1, r, v * 2 + 1);
        seeg[v] = seeg[v*2] + seeg[v*2+1];
    }
}
ll getSum(int id, int l, int r, int u, int v){
    if (v < l || r < u){
        return 0;
    }
    if (u <= l && r <= v){
        return seeg[id];
    }
    int mid = (l + r)/2;
    return getSum(id * 2, l, mid, u, v) + getSum(id * 2 + 1, mid + 1, r, u, v);
}   
void update(int id, int l, int r, int pos, ll val) {
    if(pos < l || r < pos)
        return;
    if(l == r) {
        seeg[id] = val;
        return;
    }
    int mid = (l + r)/2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    seeg[id] = seeg[2*id] + seeg[2*id + 1];
}
void solve()
{
    int n, q, pos, u, v, type;
    ll val;
    cin >> n >> q;
    a.resize(n);
    seeg.resize(4*n);
    read(a);
    build(0, n - 1, 1);
    for (int i = 0; i<q; i++){
        cin >> type;
        if (type == 1){
            cin >> pos >> val;
            update(1, 0, n - 1, pos - 1, val);
        }else{
            cin >> u >> v;
            cout << getSum(1, 0, n - 1, u - 1, v - 1) << endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}