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
#define LT "1671"
#define maxn 100005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
vector<pii> dsk[maxn];

struct ii
{
    int u;
    ll w;
};
struct ss
{
    bool operator()( ii a , ii b )
    {
        return a.w > b.w;
    }
};
priority_queue <ii , vector<ii> , ss> heapmin;

ll f[maxn] , vc = 1e18;
int kt[maxn];

void nhap()
{
    cin >> n >> m;
    For( i , 1 , m )
    {
        int u , v , w;
        cin >> u >> v >> w;
        dsk[u].pb( {v , w} );
    }
}

void dijkstra( int s )
{
    For( i , 1 , n ) f[i] = vc , kt[i] = 0;
    f[s] = 0;
    heapmin.push( { s , f[s] } );

    while( !heapmin.empty() )
    {
        ii tam = heapmin.top(); heapmin.pop();
        int u = tam.u;
        if( f[u] < tam.w ) continue;
        kt[u] = 1;

        for( pii res : dsk[u] )
        {
            int v = res.fi;
            if( kt[v] ) continue;
            if( f[v] > f[u] + res.se )
            {
                f[v] = f[u] + res.se;
                heapmin.push({ v , f[v] });
            }
        }
    }
}

void xuli()
{
    dijkstra(1);
    For( i , 1 , n ) cout << f[i] << ' '; cout << endl;
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

