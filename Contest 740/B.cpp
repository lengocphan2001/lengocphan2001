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
    int a, b;
    cin >> a >> b;
    if (a == 0 || b == 0){
        cout << 2 << endl;
        cout << max(a, b)/2 << " " << (max(a, b) + 1)/2 << endl;
    }else{

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
