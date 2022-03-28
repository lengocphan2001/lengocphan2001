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
    string s;
    cin >> n >> s;
    int idx = 0;
    int ans = 0;
    vector<int> l, r;
    for (int i = 0; i<n; i++) {
    	if (s[i] == '('){
    		r.pb(i);
    	}else l.pb(i);
    }
    while(idx < n){
    	if (s[idx] == '('){
    		if (idx < n - 1){
    			ans++;
    			idx+=2;
    		}else break;
    	}else{
    		auto it = upper_bound(all(l), idx);
    		if (it != l.end()){
    			ans++;
    			idx = l[it - l.begin()] + 1;
    		}else break;
    	}
    }
    cout << ans << " " << n - idx << endl;
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