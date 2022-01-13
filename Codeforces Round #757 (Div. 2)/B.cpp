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
    cin >> n;
    vector<pair<int, int>> a(n), res;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].ff;
        a[i].ss = i + 1;
    }
    sort(all(a), greater<pair<int, int>>());
    ll cur = 0, ans = 0;
    res.push_back({a[0].ss, cur});
    ans += 2 * a[0].ff;
    cur = 2;
    ll temp = -1;
    for (int i = 1; i < n; i++)
    {
        if (2 * abs(1 - temp) * a[i].ff > 2 * abs(1 - cur) * a[i].ff)
        {
            res.push_back({a[i].ss, cur});
            ans += 2 * abs(1 - cur) * a[i].ff;
            cur++;
        }
        else
        {
            res.push_back({a[i].ss, temp});
            ans += 2 * abs(1 - temp) * a[i].ff;
            temp--;
        }
    }
    sort(all(res));
    cout << ans << endl;
    cout << 1 << " ";
    for (int i = 0; i < sz(res); i++)
    {
        cout << res[i].ss << " ";
    }
    cout << endl;
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
