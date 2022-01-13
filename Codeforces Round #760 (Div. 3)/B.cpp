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
    if ((s[sz(s) - 2] == 'p' || s[sz(s) - 2] == 'P') && (s[sz(s) - 1] == 'Y' || s[sz(s) - 1] == 'y') && sz(s) >= 4 && s[sz(s) - 3] == '.')
        cout << "yes";
    else cout << "no";
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}