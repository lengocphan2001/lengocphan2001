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
    int n;
    cin >> n;
    vector<ll> a(n);
    read(a);
    if (n == 1){
    	yes;
    }else{
    	ll cur = accumulate(all(a), 0LL);
    	sort(all(a));
    	map<ll, int> ta;
    	for (int i = 0; i<n; i++) ta[a[i]]++;
    	vector<ll> b = a;
    	queue<ll> res;
    	res.push(cur);
    	vector<ll> tmp;
    	int cnt = 0;
    	while(!res.empty() && cnt <= n && sz(tmp) <= n){
    		ll t = res.front();
    		if (ta[t] == 0 && t >= 2){
    			if (t - t/2 <= t/2){
	    			res.push(t/2);
	    			res.push(t - t/2);
    			}else{
    				res.push(t - t/2);
	    			res.push(t/2);
    			}
    			cnt++;
    		}else{
    			ta[t]--;
    			tmp.pb(t);
    			a.pop_back();
    		}
    		res.pop();
    	}
    	sort(all(tmp));
    	if (tmp == b && res.empty()) yes;
    	else no;
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