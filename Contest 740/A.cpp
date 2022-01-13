#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define Fi(a,n) for(int i = a; i < n; i++)
#define Fd(n,a) for(int i = n; i >= a; i--)
#define all(a) a.begin(), a.end()
#define pb push_back
bool check(vector<int> a)
{
    for (int i = 0; i<a.size()-1; i++)
    {
        if (a[i] > a[i+1])
            return false;
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    Fi(1,n + 1) cin >> a[i];
    if (check(a)){
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    for (int i = 1; i<=n; i++)
    {
        if (i % 2 == 1)
        {
            for (int i = 1; i<=n-2; i+=2)
            {
                if (a[i] > a[i+1])
                {
                    swap(a[i], a[i+1]);
                }
            }
            if (check(a))
            {
                cout << i << endl;
                return;
            }
        }
        else
        {
            for (int i = 2; i<=n-1; i+=2)
            {
                if (a[i] > a[i+1])
                {
                    swap(a[i], a[i+1]);
                }
            }
            if (check(a))
            {
                cout << i << endl;
                return;
            }
        }
    }
    cout << 0 << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}
