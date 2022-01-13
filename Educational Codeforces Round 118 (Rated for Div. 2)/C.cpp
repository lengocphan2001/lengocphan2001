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
const ll mod = 1e9 + 7;
void solve()
{
    int n;
    ll h;
    cin >> n >> h;
    vector<ll> a(n);
    Fi(0, n) cin >> a[i];
    ll i = 1, j = h * 2;
    ll ans = LLONG_MAX;
    while (i <= j)
    {
        ll mid = (i + j) / 2;
        ll tmp = 0;
        for (int i = 1; i < n; i++)
        {
            tmp += min(mid, a[i] - a[i - 1]);
        }
        tmp += mid;
        if (tmp < h)
        {
            i = mid + 1;
        }
        else
        {
            ans = min(ans, mid);
            j = mid - 1;
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
    while (t--)
        solve();
}