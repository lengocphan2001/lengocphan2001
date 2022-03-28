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
bool visit[1001][1001] = {false};
char a[1001][1001], b[1001][1001];
vector<char> ans;
int n, m;
bool isOk(int x, int y){
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    if (visit[x][y] || a[x][y] == '#') return false;
    return true;
}
bool bfs(int x, int y){
    queue<pair<int, int>> q;
    visit[x][y] = true;
    q.push({x, y});
    while(!q.empty()){
        int r = q.front().ff;
        int c = q.front().ss;
        q.pop();
        if (a[r][c] == 'B'){
            while(r != x || c != y){
                ans.pb(b[r][c]);
                if (ans.back() == 'L') c++;
                if (ans.back() == 'R') c--;
                if (ans.back() == 'D') r--;
                if (ans.back() == 'U') r++;
            }
            return true;
        }
        if (isOk(r, c - 1)){
            q.push({r, c-1});
            b[r][c-1] = 'L';
            visit[r][c-1] = true;
        }
        if (isOk(r, c + 1)){
            q.push({r, c+1});
            b[r][c+1] = 'R';
            visit[r][c+1] = true;
        }
        if (isOk(r - 1, c)){
            q.push({r - 1, c});
            b[r-1][c] = 'U';
            visit[r-1][c] = true;
        }
        if (isOk(r + 1, c)){
            q.push({r + 1, c});
            b[r+1][c] = 'D';
            visit[r+1][c] = true;
        }
    }
    return false;
}
void solve()
{

    cin >> n >> m;
    int x = 0, y = 0;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            cin >> a[i][j];
            if (a[i][j] == 'A') x = i, y = j;
        }
    }
    if (bfs(x, y)){
        yes;
        cout << sz(ans) << endl;
        for (auto rit = ans.rbegin(); rit!= ans.rend(); ++rit)
            cout << *rit;
        cout << endl;
    }else cout << "NO";

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}