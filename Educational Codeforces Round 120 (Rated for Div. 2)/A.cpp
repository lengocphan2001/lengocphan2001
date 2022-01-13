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
    int k;
    cin >> k;
    string s;
    cin >> s;
    int d = 0, h = 0, a = 0;
    for (auto i: s){
    	if (i == 'H') h++;
    	else if (i == 'A') a++;
    	else d++;
    } 
    if (d < k || h < k || a < k) cout << -1;
    else{
    	if (d == k && a == k && h == k) cout << 0 << endl;
    	else{
    		int i = 0, j = sz(s) - 1;
    		cout << a << ' ' << h << " " << d << endl;
    		while (true){
    			bool check = false;
    			if (s[i] == 'A' && i <= j && a > k){
    				a--;
    				i++;
    				check = true;
    			}	
    			if (s[i] == 'H' && i <= j && h > k){
    				h--;
    				i++;
    				check = true;
    			}
    			if (s[i] == 'D' && i <= j && d > k){
    				d--;
    				i++;
    				check = true;
    			}	
    			
    			if (!check) break;
    		}
    		cout << a << " " << h << " " << d << endl;
    		while(true){
    			bool check = false;
    			if (s[j] == 'A' && j >= i && a > k){
    				a--;
    				j--;
    				check = true;
    			}	
    			if (s[j] == 'H' && j >= i && h > k){
    				h--;
    				j--;
    				check = true;
    			}	
    			if (s[j] == 'D' && j >= i && d > k){
    				d--;
    				j--;	
    				check = true;
    			}	
    			if (!check) break;
    		}
    		cout << a << ' ' << h << " " << d << endl;
    		cout << i << " " << j << endl;
    		cout << (j - i + 1) - 3*k;
    	}
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}