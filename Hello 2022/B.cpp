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
    vector<tuple<ll, ll, ll>> a(n);
    vector<ll> dp(n, 0);
    for (int i = 0; i<n; i++){
    	cin >> get<0>(a[i]) >> get<1>(a[i]) >> get<2>(a[i]);
    	if (i == 0) dp[i] = get<2>(a[i]);
    }
    stack<int> rem;
    rem.push(0);
    ll l = get<0>(a[0]), r = get<1>(a[0]);
    for (int i = 1; i<n; i++){
    	dp[i] = dp[i-1];
    	if (get<0>(a[i]) >= l && get<1>(a[i]) <= r){
    		dp[i] += get<2>(a[i]);
    		if (!rem.empty() && get<2>(a[rem.top()]) > get<2>(a[i])){
    			dp[i] -= get<2>(a[rem.top()]);
    			rem.pop();
    		}else{
    			dp[i] -= get<2>(a[i]);
    			rem.push(i);
    		}
    	}else{
    		dp[i] += get<2>(a[i]);
    		if (get<0>(a[i]) < l){
    			while(!rem.empty() && get<0>(a[rem.top()]) >= get<0>(a[i]) && get<1>(a[rem.top()]) <= get<1>(a[i])){
    				dp[i] -= get<2>(a[rem.top()]);
    				rem.pop();
    			}
    			l = min(l, get<0>(a[i]));
    		}
    		if (get<1>(a[i]) > r){
    			while(!rem.empty() && get<1>(a[rem.top()]) <= get<1>(a[i]) && get<0>(a[rem.top()]) >= get<0>(a[i])){
    				dp[i] -= get<2>(a[rem.top()]);
    				rem.pop();
    			}
    			r = max(r, get<1>(a[i]));
    		}
    		rem.push(i);
    	}
    }
    for (auto i: dp) cout << i << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}