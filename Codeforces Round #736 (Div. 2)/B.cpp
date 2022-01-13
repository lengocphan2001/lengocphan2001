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
    int n, ans = 0;
    cin >> n;
    string s, s1;
    cin >> s >> s1;
    int pawnbot = 0, pawnreal = 0;
    Fi(0, n){
        if (s[i] == '1')
            pawnbot++;
    }
    Fi(0, n){
        if (s1[i] == '1')
            pawnreal++;
    }
    if (pawnbot == 0){
        cout << pawnreal << endl;
    }else{
        if (pawnreal == 0)
            cout << 0 << endl;
        else{
            vector<bool> check(n, false);
            for (int i = 0; i<n; i++){
                if (s1[i] == '1'){
                    if (i == 0){
                        if (s[i] == '0')
                            ans++;
                        else if (s[i+1] == '1'){
                            ans++;
                            check[i+1] = true;
                        }
                    }else if (i!= n-1){
                        if (s[i] == '0')
                            ans++;
                        else if (s[i-1] == '1' && !check[i-1]){
                            ans++;
                            check[i-1] = true;
                        }else if (s[i+1] == '1' && !check[i+1]){
                            ans++;
                            check[i+1] = true;
                        }
                    }else{
                        if (s[i] == '0')
                            ans++;
                        else if (s[i-1] == '1' && !check[i-1])
                            ans++;
                    }
                }
            }
            cout << ans << endl;
        }

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
