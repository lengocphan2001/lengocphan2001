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
void solve()
{
    ll l, r;
    vector<ll> ans;
    cin >> l >> r;
    vector<ll> a(r - l + 1);
    read(a);
    sort(all(a));
    for (int i = 0; i<r-l+1; i+=2) ans.pb(i);
    for (int i = 1; i<r-l+1; i+=2) ans.pb(i);
    ll x = 0, y = 1e12;
	ll tmp = a[r - l];
    while(x <= y){
    	ll mid = (x + y)/2;
    	vector<ll> cur;
    	ll temp = 0;
    	for (int i = 0; i<r-l+1; i++){
    		cur.pb(ans[i] ^ mid);
    		temp = max(temp, cur.back());
    	}
    	if (temp > tmp){
    		y = mid - 1;
    	}else{
    		sort(all(cur));
	    	bool check = true;
	    	for (int i = 0; i<r-l+1; i++){
	    		if (a[i] != cur[i]){
	    			check = false;
	    			break;
	    		}
	    	}
	    	if (check) {
	    		cout << mid << endl;
	    		return;
	    	}
	    	x = mid + 1;
	    }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    	solve();
}