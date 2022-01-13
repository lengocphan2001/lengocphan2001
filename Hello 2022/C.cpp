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
    stack<int> s;
    int ans = 0;
    int temp;
    int n, i = 0;
    cin >> n;
    vector<int> a(n);
    read(a);
    while (i < n)
    {
        if (s.empty() || a[s.top()] <= a[i])
            s.push(i++);
        else
        {
            int tmp = s.top();
            s.pop();
            temp = a[tmp] * (s.empty() ? i : i - s.top() - 1);
            if (ans < temp)
                ans = temp;
        }
    }
    while (!s.empty())
    {
        int tmp = s.top();
        s.pop();
        temp = a[tmp] * (s.empty() ? i : i - s.top() - 1);
        if (ans < temp)
            ans = temp;
    }
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}