/// Tìm chu trình trên đồ thị có hướng

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
#define LT "1683"
#define maxn 100005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
vi ke[maxn];
int nhan[maxn] , active[maxn] , tr[maxn];
int dd[maxn];

void nhap()
{
    cin >> n >> m;
    For( i , 1 , m )
    {
        int u , v; cin >> u >> v;
        ke[u].pb(v);
    }
}

int root( int s )
{
    if( s != nhan[s] ) nhan[s] = root(nhan[s]);
    return nhan[s];
}

void Union( int u, int v )
{
    u = root(u) , v = root(v);
    if( u == v ) return;
    nhan[v] = u;
}

void trace( int u , int v )
{
    while( u != v )
    {
        Union(tr[u] , u);
        if( root(u) == root(v) ) return;
        u = tr[u];
    }
}

void dfs( int u )
{
    active[u] = 1;
    for( int v : ke[u] )
    {
        if( tr[v] == 0 ) { tr[v] = u ; dfs(v); continue;}
        v = root(v);
        if( active[v] ) trace(u , v);
    }
    active[u] = 0;
}

void xuli()
{
    For( i , 1 , n ) nhan[i] = i;
    For( i , 1 , n )
    {
        if( tr[i] ) continue;
        tr[i] = i;
        dfs(i);
    }

    int dem = 0;
    For( i , 1 , n ) if( nhan[i] == i ) dd[i] = ++dem;

    cout << dem << endl;
    For( i , 1 , n )
    {
        int tam = root(i);
        cout << dd[tam] << ' ';
    }
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

