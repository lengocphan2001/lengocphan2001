#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define Fi(a,n) for(int i = a; i < n; i++)
#define Fd(n,a) for(int i = n; i >= a; i--)
#define all(a) a.begin(), a.end()
#define pb push_back

void solve(){
    string s;
    cin >> s;
    map<char, int> cur;
    for (int i = 0; i<s.size(); i++){
        cur[s[i]]++;
    }
    int ans = 0;
    for (int i = 0; i<s.size(); i++){
        ans+=min(cur[s[i]], 2);
        cur[s[i]] = 0;
    }
    cout << ans/2 << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}
