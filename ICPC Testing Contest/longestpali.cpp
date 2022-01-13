#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define Fi(a,n) for(int i = a; i < n; i++)
#define Fd(n,a) for(int i = n; i >= a; i--)
#define all(a) a.begin(), a.end()
#define pb push_back
bool check(string s){
    int n = s.size();
    for (int i = 0; i<n/2; i++){
        if (s[i] != s[n - i - 1])
            return false;
    }
    return true;
}
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    if (check(s))
        cout << n;
    else{

    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}
