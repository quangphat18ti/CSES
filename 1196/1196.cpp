/// Cho đồ thị có hướng n đỉnh m cạnh. TÌm k dường đi có trọng số nhỏ nhất

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
#define LT "1196"
#define maxn 100005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;

vector<pii> dsk[maxn];

vector<ll> f[maxn];
ll vc = 1e16;

struct ii
{
    int u , k;
    ll w;
};
struct ss
{
    bool operator()( ii a ,ii b )
    {
        return a.w > b.w;
    }
};
priority_queue <ii , vector<ii> , ss> heapmin;

void nhap()
{
    cin >> n >> m >> k;
    For(i , 1 , m)
    {
        int u , v , w;
        cin >> u >> v >> w;
        dsk[u].pb({v , w});
    }
}

void process()
{
    For(i , 1, n ) For(j , 0 , k) f[i].pb(vc);
}

vi update( ll gt , int u )
{
    vi ans;

    For(i , 1 , k)
    {
        if( f[u][i] > gt )
        {
            ans.pb( i );
            swap( f[u][i] , gt );
        }
    }

    return ans;
}

void dijkstra( int s )
{
    process();
    update( 0 , s );
    heapmin.push( { s , 1 , f[s][1] } );

    while( !heapmin.empty() )
    {
        ii tam = heapmin.top(); heapmin.pop();
        int u = tam.u , k_ = tam.k;
        if( f[u][k_] < tam.w ) continue;

        for( pii canh : dsk[u] )
        {
            int v = canh.fi;
            vi ans = update( tam.w + canh.se , v );
            for( int tam : ans ) heapmin.push( { v , tam , f[v][tam] } );
        }
    }
}

void xuli()
{
    dijkstra(1);
    For(i , 1 ,k) cout << f[n][i] << ' ';
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

