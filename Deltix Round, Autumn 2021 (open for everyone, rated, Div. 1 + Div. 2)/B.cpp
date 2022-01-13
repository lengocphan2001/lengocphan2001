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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    set<int> cur;
    for (int i = 0; i <= n - 3; i++)
    {
        if (s.substr(i, 3) == "abc")
        {
            cur.insert(i);
        }
    }
    char c;
    int pos;
    for (int i = 0; i < m; i++)
    {
        cin >> pos >> c;
        pos--;
        s[pos] = c;
        if (pos <= n - 3 && s.substr(pos, 3) == "abc")
        {
            cur.insert(pos);
        }
        for (int j = max(pos - 2, 0); j <= n - 3 && j <= pos; j++)
        {
            if (s.substr(j, 3) == "abc")
            {
                cur.insert(j);
            }
            else
                cur.erase(j);
        }
        cout << sz(cur) << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}