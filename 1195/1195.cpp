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
#define LT "1195"
#define maxn 100005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;

int i , j , n , m , k;
vector<pii> dsk[2][maxn];
ll vc = 1e18;
multiset <pair<ll,int>> st;

struct canh
{
    int u , v , w;
};
vector<canh> ds;

void nhap()
{
    cin >> n >> m;
    For( i , 1 , m )
    {
        int u , v , w;
        cin >> u >> v >> w;
        dsk[0][u].pb({v , w});
        dsk[1][v].pb({u , w});
        ds.pb( {u , v , w} );
    }
}

vll dijkstra( int l , int s )
{
    vll f(n + 1 , vc);
    vi kt(n + 1 , 0);
    f[s] = 0; st.insert( {f[s] , s} );

    while( !st.empty() )
    {
        pair<ll,int> tam = *st.begin(); st.erase( st.begin() );
        int u = tam.se;
        if( f[u] < tam.fi ) continue;
        kt[u] = 1;
        for( pii tmp : dsk[l][u] )
        {
            int v = tmp.fi;
            if( kt[v] ) continue;
            if( f[v] > f[u] + tmp.se )
            {
                f[v] = f[u] + tmp.se;
                st.insert( {f[v] , v} );
            }
        }
    }

    return f;
}

void xuli()
{
    vll f1 = dijkstra(0 , 1);
    vll fn = dijkstra(1 , n);

    ll ans = vc;
    For( i , 0 , m - 1 )
    {
        int u = ds[i].u;
        int v = ds[i].v;
        int w = ds[i].w;
        ans = min(ans , f1[u] + fn[v] + w/2 );
    }
    cout << ans << endl;
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
