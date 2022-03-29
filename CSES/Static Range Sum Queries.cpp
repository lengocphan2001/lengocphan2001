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
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    read(a);
    vector<ll> dp(n + 1, 0);
    for (int i = 1; i<=n; i++){
    	dp[i] = dp[i-1] + a[i-1];
    }
    while(q--){
    	int a, b;
    	cin >> a >> b;
    	cout << dp[b] - dp[a - 1] << "\n";	
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}