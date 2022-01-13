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
    ll n, m, l;
    cin >> n >> m >> l;
    vector<ll> a(n + 1, 0);
    int ans = 0;
    for (int i = 1; i<=n; i++) cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= l && a[i+1] > l)
            ans++;
    }
    for (int i = 0; i < m; i++)
    {
        int t; 
        cin >> t;
        if (t == 1)
        {
            int x, y;
            cin >> x >> y;
            if (a[x] <= l && a[x] + y > l)
            {
                if (a[x - 1] <= l)
                    ans++;
                if (x < n && a[x+1] > l)
                    ans--;
            }
            a[x] += y;
        }
        else
        {
            cout << ans << endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}