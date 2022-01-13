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
bool isOk(vector<ll> a, vector<ll> b, ll m, ll need){
    ll cur = 0;
    for (int i = 0; i<sz(a); i++){
        ll temp = m/b[i];
        while(temp * b[i] + temp >= m){
            temp--;
        }
        ll day = temp * b[i] + (m - temp*b[i] - temp);
        cur += day * a[i];
    }
    return (cur>=need);
}
void solve()
{
    ll n, need;
    cin >> n >> need;
    vector<ll> a(n), b(n);
    for (int i = 0; i<n; i++) cin >> a[i] >> b[i];
    ll i = 1, j = need;
    ll ans = LONG_MAX;
    while(i <= j){
        ll mid = (i + j)/2;
        if (isOk(a, b, mid, need)){
            ans = min(ans, mid);
            j = mid - 1;
        }else{
            i = mid + 1;
        }
    }
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}