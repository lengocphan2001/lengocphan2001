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
bool check(ll a, ll b, ll c){
	return (b - a == c - b);
}
const ll mod = 1e9 + 7;void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c){
    	yes;
    	return;
    }
    ll cur = abs(b - c), cur1 = abs(a - c), cur2 = abs(a - b);
	if ((cur + b) % a == 0 && check(((cur + b)/a)*a, b, c)){
		yes;
		return;
	}
	if ((a + cur1) % b == 0 && check(a, ((a-cur1)/b)*b, c)){
		yes;
		return;
	}
	if ((b + cur2) % c == 0 && check(a, b, ((b-cur2)/c)*c)){
		yes;
		return;
    }
    no;
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