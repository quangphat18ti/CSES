///

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define For( i , a , b ) for(int i = int(a) ; i <= int(b) ; i++)
#define FOr( i , a , b ) for(int i = int(a) ; i >= int(b) ; i--)
#define fi first
#define se second
#define mp make_pair
#define LT "1680"
#define maxn 100005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
vi ke[maxn];
int tr[maxn] , f[maxn];

void nhap()
{
    cin >> n >> m;
    For(i , 1 , m)
    {
        int u , v; cin >> u >> v;
        ke[u].pb(v);
    }
}

void dfs( int u )
{
    if( u == n ) f[u] = 1;
    else f[u] = -1e9;

    for( int v : ke[u] )
    {
        if( f[v] == -1 ) dfs(v);
        if( f[u] < f[v] + 1 )
        {
            f[u] = f[v] + 1;
            tr[u] = v;
        }
    }
}

void truyvet( int u , int v )
{
    vi ans;
    while( u != v )
    {
        ans.pb(u);
        u = tr[u];
    }
    ans.pb(v);
    cout << ans.size() << endl;
    for( int u : ans ) cout << u << ' '; cout << endl;
}

void xuli()
{
    For( i , 1 , n ) f[i] = -1;

    dfs(1);
    if( f[n] == -1 ) cout << "IMPOSSIBLE";
    else truyvet( 1 , n );
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp","r",stdin);
//    freopen(LT".out","w",stdout);
    int t = 1;
//    cin >> t;
    while( t-- )
    {
        nhap();
        xuli();
    }
}

