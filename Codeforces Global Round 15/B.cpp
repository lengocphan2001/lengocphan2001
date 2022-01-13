#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define NAME "equal."
ifstream fi(NAME "in");
ofstream fo(NAME "out");

int main()
{
    int n;
    fi >> n;
    long long mx = 0, x;
    set<long long> cur;
    long long lcm = 1;
    vector<long long> temp;
    map<long long, int> a;
    for (long long i = 0; i < n; i++)
    {
        fi >> x;
        a[x]++;
        lcm = (lcm * x) / __gcd(lcm, x);
        cur.insert(x);
        mx = max(mx, x);
    }
    long long ans = cur.size();
    for (auto i : cur)
    {
        if (i != lcm)
            temp.push_back(a[i]);
    }
    sort(temp.begin(), temp.end());
    bool check = false;
    for (auto i : temp)
    {
        for (int j = 0; j < i; j++)
            fo << ans << " "; 
        if (check)
            ans--;
        else
        {
            if (lcm == mx)
                ans--;
            check = true;
        }
    }
    if (lcm == mx)
    {
        for (int i = 0; i < a[mx]; i++)
            fo << 1 << " ";
    }
    fo << 1;
}