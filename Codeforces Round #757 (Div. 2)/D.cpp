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
typedef multimap<ll, ll> MapType;
const ll mod = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll ans = 0;
    sort(all(a), greater<ll>());
    for (int i = 0; i < n; i++)
    {
        vector<ll> res;
        res.pb(a[i]);
        for (int j = 0; j < n; j++)
        {
            if (a[i] % a[j] == 0 && j != i)
            {
                res.pb(a[j]);
            }
        }
        sort(all(res), greater<ll>());
        ll cur = res[0], temp = res[0];
        map<ll, ll> mp;
        for (int i = 0; i < res.size(); i++)
        {
            if (mp.find(res[i]) != mp.end())
            {
                mp[res[i]]++;
            }
            else
            {
                mp[res[i]] = 1;
            }
        }
        multimap<ll, ll> mp2;
        map<ll, ll>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++)
        {
            mp2.insert(MapType::value_type(it->second, it->first));
        }
        map<ll, ll>::reverse_iterator itr;
        for (itr = mp2.rbegin(); itr != mp2.rend(); itr++)
        {
            for (int i = 0; i < itr->first; i++)
                temp = __gcd(temp, itr->second);
            cur += temp;
        }
        cur += (n - sz(res));
        ans = max(ans, cur);
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}