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
    vector<ll> a;
    ll m;
    cin >> m;
    for (int i = 0; i<=9; i++){
    	a.pb(pow(10, i));
    }
    auto it = lower_bound(all(a), m);
    if (*it != m && it != a.begin())
    	it--;
    cout << m - *it<< endl;
}
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
	#endif
    int t;
    cin >> t;
    while(t--)
        solve();
}