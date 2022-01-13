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
bool check(vector<ll> a, vector<ll> b)
{
    for (int i = 0; i < sz(a); i++)
    {
        if (a[i] > b[i])
            return false;
    }
    return true;
}
bool check2(vector<ll> a, vector<ll> b)
{
    for (int i = 0; i < sz(a); i++)
    {
        if (2 * a[i] > b[i])
            return false;
    }
    return true;
}
void solve()
{
    ll n, r, sum = 0;
    cin >> n >> r;
    vector<ll> a(n), b(n), dp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i == 0)
            dp[i] = a[i];
        else
            dp[i] = dp[i - 1] + a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        sum += b[i];
    }
    if (check2(a, b))
    {
        cout << 0;
        return;
    }
    if (!check(a, b))
    {
        cout << -1;
        return;
    }
    if (r >= sum && check(a, b))
    {
        cout << 1 << endl;
        cout << 0;
        return;
    }
    ll s = 0, ans = 0;
    vector<ll> res;
    while (upper_bound(all(dp), s) != dp.end())
    {
        int i = lower_bound(all(dp), s) - dp.begin();
        ll cur = a[i] * 2 - b[i];
        if (cur > 0)
        {
            if (cur > r)
            {
                if (cur % r == 0)
                {
                    int t = dp[i];
                    ans += cur / r;
                    for (int i = 0; i < cur / r; i++)
                    {
                        res.pb(t);
                        t -= r;
                    }
                    s = dp[i] + r;
                }
                else
                {

                    int t = dp[i];
                    ans += cur / r + 1;
                    for (int i = 0; i < cur / r + 1; i++)
                    {
                        res.pb(t);
                        t -= r;
                    }
                    s = dp[i] + r;
                }
            }
            else
            {
                ans++;
                res.pb(dp[i] - a[i]);
                s = dp[i] + max(0LL, r - res.back());
            }
        }
        else
        {
            s = dp[i] + 1;
        }
        if (ans >= 1e5)
        {
            cout << -1;
            return;
        }
    }
    sort(all(res));
    cout << ans << endl;
    for (auto i : res)
        cout << i << ' ';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}