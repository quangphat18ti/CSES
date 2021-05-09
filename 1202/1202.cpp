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
#define LT ""
#define maxn 100005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
vii ke[maxn];
int mod = 1e9 + 7;
int Long[maxn] , Short[maxn] , g[maxn];
ll f[maxn] , vc = 1e16;

multiset <pair<ll,int>> heapmin;

void nhap()
{
    cin >> n >> m;
    For(i , 1 , m)
    {
        int u , v , w;
        cin >> u >> v >> w;
        ke[u].pb( {v , w} );
    }
}

void Min( int &a , int b ) { if( a > b ) a = b; }
void Max( int &a , int b ) { if( a < b ) a = b; }

void dijkstra( int s )
{
    For(i , 1 , n)
        f[i] = vc , g[i] = 0 , Long[i] = -1 , Short[i] = 1e9;

    f[s] = 0; g[s] = 1; Long[s] = 0 , Short[s] = 0;
    heapmin.insert( {f[s] , s} );

    while( !heapmin.empty() )
    {
        pair<ll,int> res = *heapmin.begin(); heapmin.erase( heapmin.begin() );
        int u = res.se;
        if( f[u] < res.fi ) continue;
        for( pii tam : ke[u] )
        {
            int v = tam.fi;
            if( f[v] > f[u] + tam.se )
            {
                f[v] = f[u] + tam.se;
                g[v] = g[u];
                Long[v] = Long[u] + 1;
                Short[v] = Short[u] + 1;
                heapmin.insert( {f[v] , v} );
            }
            else if( f[v] == f[u] + tam.se )
            {
                g[v] = (g[v] + g[u]) % mod;
                Max( Long[v] , Long[u] + 1 );
                Min( Short[v] , Short[u] + 1 );
            }
        }
    }
}

void xuli()
{
    dijkstra(1);
    cout << f[n] << ' ' << g[n] << ' ' << Short[n] << ' ' << Long[n] << endl;
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

