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
    string s;
    cin >> s;
    map<char, int> cur;
    for (auto i: s) cur[i]++;
    int ans = 0;
    for (auto i: cur){
        ans += (i.ss * (i.ss - 1)/2);
    }
    int n = sz(s);
    for (int i = 0; i<n; i++){
        for (int j = i + 1; j<n; j++){
            string tmp = s.substr(i, j - i + 1);
            reverse(all(tmp));
            if ((s.begin() + s.find(tmp)) != i) ans++;
        }
    }
    cout << ans << endl;
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