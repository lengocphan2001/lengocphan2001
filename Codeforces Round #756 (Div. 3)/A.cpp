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
bool isOdd(char i) { return ((i - '0') % 2 == 1); }
bool check(string s)
{
    return count_if(all(s), isOdd) == sz(s);
}
void solve()
{
    string s;
    cin >> s;
    if (check(s))
        cout << -1 << endl;
    else
    {
        if ((s[sz(s) - 1] - '0') % 2 == 0)
            cout << 0 << endl;
        else
        {
            if ((s[0] - '0') % 2 == 0)
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
    }
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