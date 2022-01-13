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
    int n, m, type, u, v, q;
    cin >> n >> m;
    map<int, set<int>> ans;
    Fi(0, m)
    {
        cin >> u >> v;
        ans[u].insert(v);
        ans[v].insert(u);
    }
    int res = n;
    vector<bool> check(n+1, true);
    vector<int> cur;
    for (int i = 1; i<=n; i++)
    {
        for (auto a : cur){
            ans[i].erase(a);
        }
        if (ans[i].size()!=0 && i < *ans[i].begin())
        {
            res--;
            ans[i].clear();
            cur.pb(i);
        }
    }
    cin >> q;
    Fi(0, q)
    {
        vector<int> temp;
        cin >> type;
        if (type == 3)
        {
            cout << res << endl;
        }
        if (type == 2)
        {
            cin >> u >> v;
            if (ans[u].find(v) != ans[u].end())
                ans[u].erase(v);
            if (ans[v].find(u) != ans[v].end())
                ans[v].erase(u);
            if (u < *ans[u].begin() && ans[u].size() == 1)
                res++;
            if (v < *ans[v].begin() && ans[v].size() == 1)
                res++;
        }
        if (type == 1)
        {
            cin >> u >> v;
            for (auto a : temp){
                if (ans[u].find(a) != ans[u].end())
                    ans[u].erase(a);
            }
            for (auto a : temp){
                if (ans[v].find(a) != ans[v].end())
                    ans[v].erase(a);
            }
            ans[u].insert(v);
            ans[v].insert(u);
            if (ans[u].size()!=0 && u < *ans[u].begin() && res > 0)
            {
                res--;
                ans[u].clear();
                temp.pb(u);
            }
            if (ans[v].size()!=0 && v < *ans[v].begin() && res > 0)
            {
                res--;
                ans[v].clear();
                temp.pb(v);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}

