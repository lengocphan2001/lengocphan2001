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
    string s;
    cin >> s;
    string cur = s;
    int i, j;
    if (s == string(sz(s), '9')){
    	cout << "1" + string(sz(s) - 1, '0') + "1" << endl;
    	return;
    }
    if (sz(s) % 2 == 1){
    	i = sz(s)/2;
    	j = sz(s)/2;
    	if (s[i] != '9'){
    		if (i > 0 && s[i-1] > s[j+1]){
    			s[j+1] = s[i-1];
    			i--;
    			j++;
    		}else
	    		s[i]++;
	    	for (int t = 0; t < i; t++){
	    		j++;
	   			s[j] = s[t];
	   		}
	    	cout << s << endl;
	    	return;
	    }
    }else{
    	i = sz(s)/2 - 1;
    	j = sz(s)/2;
	   	if (s[i] <= s[j]){
	   		if (s[i] == s[j] && s[i] == '9'){
	   			s[i] = s[j] = '0';
	   		}
   			s[i]++;
   			s[j] = s[i];
	   		for (int t = 0; t < i; t++){
	   			j++;
	   			s[j] = s[t];
	   		}
	   		cout << s << std::endl;
	   		return;
	   	}else{
	   		s[i] = s[j];
	   		for (int t = 0; t < i; t++){
	   			j++;
	   			s[j] = s[t];
	   		}
	   		cout << s << std::endl;
	   		return;
	   	}
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}