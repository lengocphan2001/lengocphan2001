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
class Seg{
public:
	vector<ll> seg;
	int n;
public:
	void build(vector<ll> a, int id, int l, int r){
		if (l == r){
			seg[id] = a[l];
			return;
		}
		int mid = l + (r - l)/2;
		build(a, id * 2, l, mid);
		build(a, id * 2 + 1, mid + 1, r);
		seg[id] = seg[id * 2] + seg[id * 2 + 1];
	}
	Seg(vector<ll> a, int nn){
		n = nn;
		build(a, 1, 1, n);
	}
	void update(int id, int u, int v, int l, int r, ll val){
		if (u > r || v < l || l > r){
			return;
		}
		if (l == r){
			seg[id] += val;
		}else{
			int mid = l + (r - l)/2;
			update(id * 2, u, v, l, mid, val);
			update(id * 2 + 1, u, v, mid + 1, r, val);
			seg[id] = seg[id * 2] + seg[id * 2 + 1];
		}
	}
	ll get(int id, int pos, int l, int r){
		if (l == r){
			return seg[id];
		}
		if (l > r) return 0;
		int mid = l + (r - l)/2;
		if (pos <= mid){
			return get(id * 2, pos, l, mid);
		}else{
			return get(id * 2 + 1, pos, mid + 1, r);
		}
	}
};
void solve()
{
    int n, q;
    cin >> n >> q;
   	vector<ll> a(n + 1);
   	for (int i = 1; i<=n; i++) cin >> a[i];
   	Seg t(a, n);
   	while(q--){
   		int type, u, v;
   		ll val;
   		cin >> type;
   		if (type == 1){
   			cin >> u >> v >> val;
   			t.update(1, u, v, 1, n, val);
   		}else{
   			cin >> u;
   			cout << t.get(1, u, 1, n) << endl;
   		}
   	}
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
