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
    int n;
    cin >> n;
    vector<tuple<int, int, int>> a(n);
    set<int> cur;
    for (int i = 0; i < n; i++)
    {
        cin >> get<0>(a[i]) >> get<1>(a[i]);
        get<2>(a[i]) = i;
        cur.insert(i);
    }
    int ans = 0;
    sort(all(a), greater<tuple<int, int, int>>());
    while (!cur.empty())
    {
        int temp = *cur.begin(), mx = -1;
        vector<tuple<int, int, int>> tmp;
        for (auto i : cur)
        {
            vector<tuple<int, int, int>> res = a;
            int m = 0, x = 0;
            for (int j = 0; j < n; j++)
            {
                if (get<2>(res[j]) == i)
                {
                    m = j;
                    get<0>(res[j]) += get<1>(res[j]);
                    break;
                }
            }
            sort(all(res), greater<tuple<int, int, int>>());
            for (int j = 0; j < n; j++)
            {
                if (get<2>(res[j]) == i)
                {
                    x = j;
                    break;
                }
            }
            if (abs(m - x) > mx)
            {
                mx = abs(m - x);
                temp = i;
                tmp = res;
            }
        }
        a = tmp;
        ans += mx;
        cur.erase(temp);
    }
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}