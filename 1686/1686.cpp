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
#define LT "1686"
#define maxn 100005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
vi ke[maxn];
pii edge[maxn * 2];
int low[maxn] , num[maxn] , cnt = 0 , nhan[maxn] , sl[maxn], vc = 1e9;
int New[maxn];
stack <int> st;
ll f[maxn] , g[maxn] , gt[maxn];

void nhap()
{
    cin >> n >> m;
    For( i , 1 , n ) cin >> gt[i];
    For(i , 1, m)
    {
        int u , v; cin >> u >> v;
        ke[u].pb(v);
        edge[i] = {u , v};
    }
}

int root( int s )
{
    if( s != nhan[s] ) nhan[s] = root(nhan[s]);
    return nhan[s];
}

void gop( int u , int v )
{
    u = root(u) , v = root(v);
    if( u == v ) return;
    if( sl[u] > sl[v] )
    {
        nhan[v] = u;
        gt[u] += gt[v];
        sl[u] += sl[v];
    }
    else
    {
        nhan[u] = v;
        gt[v] += gt[u];
        sl[v] += sl[u];
    }
}

void dfs( int u )
{
    low[u] = num[u] = ++cnt;
    st.push(u);

    for( int v : ke[u] )
    {
        if( num[v] == 0 )
        {
            dfs(v);
            low[u] = min( low[u] , low[v] );
        }
        else low[u] = min( low[u] , num[v] );
    }

    if( low[u] == num[u] ) /// Nếu u là nút gốc của 1 thành phần liên thông manhj
    {
        while( true )
        {
            int v = st.top(); st.pop();
            num[v] = vc;
            if( v == u ) break;
            gop(u , v);
        }
    }
}

void Build_graph()
{
    For( i , 1 , n ) ke[i].clear();

    For( i , 1 , m )
    {
        int u = edge[i].fi , v = edge[i].se;
        u = root(u) , v = root(v);
        if( u == v ) continue;
        ke[New[u]].pb( New[v] );
    }
}

void DFS( int u )
{
    f[u] = g[u];
    for( int v : ke[u] )
    {
        if( f[v] == -1 ) DFS(v);
        f[u] = max( f[u] , f[v] + g[u] );
    }
}

void xuli()
{
    For(i , 1 , n) nhan[i] = i , sl[i] = i;
    For( i , 1 , n )
    {
        if( num[i] ) continue;
        dfs(i);
    }

    int dem = 0;
    For( i , 1 , n ) if( root(i) == i )
    {
        New[i] = ++dem;
        g[dem] = gt[i];
    }

    Build_graph();

    For( i ,1 , dem ) f[i] = -1;
    For( i , 1 , dem )
    {
        if( f[i] == -1 ) DFS(i);
    }

    cout << *max_element( f+1 , f+dem+1 ) << endl;
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
