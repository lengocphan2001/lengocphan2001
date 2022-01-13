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
    ll n;
    cin >> n;
    vector<tuple<ll, ll, ll>> a(n);
    set<ll> cur;
    for (ll i = 0; i < n; i++)
    {
        cin >> get<0>(a[i]) >> get<1>(a[i]);
        get<2>(a[i]) = i;
        cur.insert(i);
    }
    ll ans = 0;
    sort(all(a));
    while (!cur.empty())
    {
        ll temp = *cur.begin(), mx = -1;
        vector<tuple<ll, ll, ll>> tmp;
        for (auto i : cur)
        {
            vector<tuple<ll, ll, ll>> res = a;
            ll m = 0, x = 0;
            for (ll j = 0; j < n; j++)
            {
                if (get<2>(res[j]) == i)
                {
                    m = j;
                    get<0>(res[j]) += get<1>(res[j]);
                    break;
                }
            }
            sort(all(res));
            for (ll j = 0; j < n; j++)
            {
                if (get<2>(res[j]) == i)
                {
                    x = j;
                    break;
                }
            }
            if (abs(m - x) > mx)
            {
                mx = abs(m - x);
                temp = i;
                tmp = res;
            }
        }
        a = tmp;
        ans += mx;
        cur.erase(temp);
    }
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}