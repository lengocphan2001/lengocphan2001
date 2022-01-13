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
    vector<ll> a(n), ans;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll res = 0;
    sort(all(a), greater<int>());
    for (int i = 0; i < sz(a); i++)
    {
        vector<ll> cur = a;
        ll temp = a[i];
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                while (cur[j] >= 1 && cur[j] % 2 == 0)
                {
                    cur[j] /= 2;
                    temp *= 2;
                }
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (i != j)
                temp += cur[j];
        }
        res = max(res, temp);
    }
    cout << res << endl;
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