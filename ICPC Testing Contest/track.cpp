#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define Fi(a,n) for(int i = a; i < n; i++)
#define Fd(n,a) for(int i = n; i >= a; i--)
#define all(a) a.begin(), a.end()
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    Fi(0, n) cin >> a[i];
    vector<pair<ll, ll>> ans(n, {0, 0});
    (a[n-1] >= 0)? ans[n-1].ff = a[n-1]: ans[n-1].ss = a[n-1];
    for (int i = n - 2; i>=0; i--)
    {
        if (a[i] >= 0)
        {
            ans[i].ff = ans[i+1].ff + a[i];
            ans[i].ss = 0;
        }
        else
        {
            ans[i].ff += ans[i+1].ff + a[i];
            if (ans[i].ff >= 0)
                ans[i].ss = 0;
            else
                ans[i].ss = ans[i].ff;
        }
    }
    reverse(all(a));
    ll res = 0, position = 1, endd = 1, endd1 = n, cur = ans[0].ff;
    Fi(0, n)
    {
        if (ans[i].ff > res)
        {
            res = ans[i].ff;
            position = i + 1;
        }
    }
    for (int i = 1; i<position-1; i++)
    {
        if (ans[i].ff < cur)
        {
            cur = ans[i].ff;
            endd = i + 1;
        }
    }
    if (position != n)
    {
        ll temp = ans[position].ff;
        for (int i = position; i < n; i++)
        {
            if (ans[i].ff < temp)
            {
                cur = ans[i].ff;
                endd1 = i + 1;
            }
        }
    }
    cout << res << endl;
    if (position - endd > endd1 - position)
        cout << endd << " " << position;
    else
        cout << position << " " << endd1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
