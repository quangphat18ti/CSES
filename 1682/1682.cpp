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
#define LT "1682"
#define maxn 200005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int ke[maxn] , gt[maxn];
vi dsk[maxn];
int active[maxn] , tr[maxn];

void nhap()
{
    cin >> n >> m;
    For( i , 1 , m )
    {
        int u , v; cin >> u >> v;
        dsk[u].pb(v);
    }
}

int root( int u )
{
    if( u != ke[u] ) ke[u] = root(ke[u]);
    return ke[u];
}

void gop( int u , int v )
{
    u = root(u) , v = root(v);
    if( u == v ) return;
    ke[v] = u;
}

/// Tìm chu trình trên đồ thị có hướng
void dfs( int u )
{
    active[u] = 1;
    for( int v : dsk[u] )
    {
        if( tr[v] == 0 ) tr[v] = u , dfs(v);
        else
        {
            v = root(v);
            if( active[v] )
            {
                int ures = u;
                while( u != v )
                {
                    gop( tr[u] , u );
                    u = tr[u];
                }
                u = ures;
            }
        }
    }
    active[u] = 0;
}

void xuli()
{
    For(i , 1 , n) ke[i] = i , gt[i] = 1;
    For( i , 1 , n )
    {
        if( tr[i] ) continue;
        tr[i] = i;
        dfs(i);
    }

    /// Xét trên đồ thị có cạnh nối
    For(u , 1 , n)
    {
        for( int v : dsk[u] )
        {
            int x = root(u) , y = root(v);
            if( x != y )
            {
                cout << "NO\n";
                cout << v << ' ' << u << endl;
                return;
            }
        }
    }

    /// xét những đồ thị riêng biệt
    vi ans;
    For( i , 1 , n ) if( i == ke[i] ) ans.pb(i);

    if( ans.size() >= 2 )
    {
        cout << "NO\n";
        cout << ans[0] << ' ' << ans[1] << endl;
    }
    else cout << "YES\n";
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
