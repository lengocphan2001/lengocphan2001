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
    int p1, p2, x1, x2;
    cin >> x1 >> p1 >> x2 >> p2;
    if ((int)log10(x1) + p1 > (int)log10(x2) + p2)
    {
        cout << '>' << endl;
    }
    else if ((int)log10(x1) + p1 == (int)log10(x2) + p2)
    {
        if ((int)log10(x1) > (int)log10(x2))
        {
            while ((int)log10(x1) > (int)log10(x2))
            {
                x2 *= 10;
            }
        }
        else if ((int)log10(x1) < (int)log10(x2))
        {
            while ((int)log10(x1) < (int)log10(x2))
            {
                x1 *= 10;
            }
        }
        if (x1 > x2)
            cout << '>' << endl;
        else if (x1 < x2)
            cout << '<' << endl;
        else
            cout << '=' << endl;
    }
    else
        cout << '<' << endl;
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