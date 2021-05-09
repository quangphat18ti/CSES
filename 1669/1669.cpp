///

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define INC( i , a , b ) for(int i = int(a) ; i <= int(b) ; i++)
#define For( i , a , b ) for(int i = int(a) ; i <= int(b) ; i++)
#define DEC( i , a , b ) for(int i = int(a) ; i >= int(b) ; i--)
#define FOr( i , a , b ) for(int i = int(a) ; i >= int(b) ; i--)
#define fi first
#define se second
#define mp make_pair
#define LT "1669"
#define maxn 100005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
vi dsk[maxn];
int f[maxn] , tr[maxn];
int ans = 0;

void nhap()
{
    cin >> n >> m;
    For( i , 1 , m )
    {
        int u , v; cin >> u >> v;
        dsk[u].pb(v);
        dsk[v].pb(u);
    }
}

void trace( int u , int v )
{
    vector<int> ans; ans.pb(v);
    while( u != v )
    {
        ans.pb(u);
        u = tr[u];
    }
    ans.pb(v);

    cout << ans.size() << endl;
    FOr( i , ans.size() - 1 , 0 ) cout << ans[i] << ' '; cout << endl;
}

void dfs( int u , int p )
{
    for( int v : dsk[u] )
    {
        if( v == p ) continue;
        if( f[v] == 0 )
        {
            tr[v] = u;
            f[v] = f[u] + 1;
            dfs( v , u );
        }
        else if( ans == 0 )
        {
            trace( u , v );
            ans = 1;
        }
    }
}

void xuli()
{
    For( i , 1 , n )
    {
        if( f[i] > 0 ) continue;
        f[i] = 1;
        dfs(i , i);
    }

    if( ans == 0 ) cout << "IMPOSSIBLE";
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
