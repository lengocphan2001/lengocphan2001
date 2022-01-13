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
map<ll, int> pre;
void prepare()
{
    pre[1] = 0;
    for (int i = 2; i <= 1e3 + 1; i++)
    {
        if (pre[i] == 0)
        {
            for (int j = i * i; j <= 1e6 + 10; j += i)
                pre[j] = 1;
        }
    }
}
void solve()
{
    int n, e, res = 0;
    cin >> n >> e;
    vector<ll> a(n + 1);
    Fi(1, n + 1)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (pre[a[i]] == 0)
        {
            ll cnt = (a[i] > 1) ? 1 : 0, temp = a[i];
            for (int k = 1; i + k * e <= n; k++)
            {
                if (pre[a[i + k * e]] == 0)
                {
                    temp = a[i + k * e];
                    if (a[i + k * e] > 1)
                        cnt++;
                    if (cnt > 1)
                        break;
                    else
                        res++;
                }
                else
                    break;
            }
        }
    }
    cout << res << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prepare();
    int t;
    cin >> t;
    while (t--)
        solve();
}