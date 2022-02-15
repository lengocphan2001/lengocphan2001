#include <bits/stdc++.h>
using namespace std;
#define MAX 30000
vector<int> BIT(MAX);
inline void update(int i, int v){
    for (; i<=MAX; i+=(i & -i)) BIT[i]+=v;
}
inline int query(int i){
    int res=0;
    for (; i>0; i-=(i & -i)) res += BIT[i];
    return res;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> ans(MAX, 0);
    BIT.resize(MAX, 0);
    for (int i=1; i<=n; i++) update(i, 1);
    int m = n, l = 1;
    for(int i = 1; i<=n; i++){
        l = (l + i) % m;
        l = (!l)? m: l; 
        m--;
        int s = 1, e = n;
        while(s <= e){
            int mid = (s + e) / 2;
            if (query(mid) >= l) e = mid - 1;
            else if (query(mid) < l) s = mid + 1;
        }
        ans[s] = i; 
        update(s, -1);
    }
    for (int i = 1; i<=n; i++) cout << ans[i] << " ";
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--) solve();
}