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
    if (n == 1){
    	cout << 0 << endl;
    	return;
    }
    ll ans = 1;
    int odd = 0, even = 0;
    int l = n/2, r = n - n/2;
    for (int i = 0; i<n; i++){
    	ll cur;
    	if (i % 2 == 0){
    		cur = l - even;
    		even++;
    	}else{
    		cur = r - odd;
    		odd++;
    	}
    	cur %= 998244353;
    	ans *= cur;
    	ans %= 998244353;
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
