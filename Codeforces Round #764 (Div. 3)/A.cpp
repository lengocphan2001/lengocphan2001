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
    int n, l, k;
    cin >> n >> l >> k;
    vector<int> a(n), b(n);
    read(a);
    a.pb(l);
    read(b);
    vector<pair<int, int>> ans;
    for (int i = 0; i<n; i++){
        ans.pb({b[i] * (a[i+1] - a[i]), i});
    }
    sort(all(ans));
    for (auto i: ans){
        cout << i.ff << " " << i.ss << endl;
    }
    ll res = 0;
    int tmp = 0;
    for (int i = n-k; i<n; i++){
        if (ans[i].ss == 0){
            cout << i << endl;
            a.erase(a.begin() + ans[i-1].ss - tmp);
            b.erase(b.begin() + ans[i-1].ss - tmp);
        }else{
            a.erase(a.begin() + ans[i].ss - tmp);
            b.erase(b.begin() + ans[i].ss - tmp);
        }
        tmp++;
    }
    for (auto i: a) cout << i << " ";
    cout << endl;
    for (auto i: b) cout << i << " ";
    cout << endl;
    for (int i = 0; i<sz(b); i++){
        res += b[i] * (a[i+1] - a[i]);
    }
    cout << res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}