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
    int n, ans = 0;
    string s;
    cin >> n >> s;
    vector<int> l;
    for (int i = 0; i<n; i++){
    	if (s[i] == '0') l.pb(i);
    }
    if (sz(l) == 0){
    	cout << 0 << endl;
    	return;
    }
    for (int i = 0; i<sz(l) - 1; i++){
    	int cur = 0;
    	for (int j = l[i] + 1; j < l[i+1]; j++){
    		if (s[j] == '1') cur++;
    	}
    	if (cur < 2){
    		ans += 2 - cur;
    	}
    }
    cout << ans << endl;
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