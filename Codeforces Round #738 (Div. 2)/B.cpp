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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string a = s;
    int cur = -1;
    for (int i = 0; i<n; i++){
        if (s[i]!='?'){
            cur = i;
            break;
        }
    }
    if (cur == -1){
        for (int i = 0; i<n; i++)
            (i%2==0)?cout << 'B': cout << 'R';
        cout << endl;
    }else{
        for (int i = cur - 1; i >=0; i--){
            if (s[i] == '?'){
                s[i] = (s[i+1] == 'B')?'R':'B';
            }
        }
        for (int i = cur + 1; i<n; i++){
            if (s[i] == '?'){
               s[i] = (s[i-1] == 'B')?'R':'B';
            }
        }
        cout << s << endl;
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
