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
vi ke[maxn];
pii bac[maxn];
vi ans;
int cha[maxn] , active[maxn] , check = 0;


void nhap()
{
    cin >> n >> m;
    For(i , 1 , m)
    {
        int u , v; cin >> u >> v;
        ke[v].pb(u);
        bac[u].fi++;
    }
    For(i , 1 , n) bac[i].se = i;
    sort( bac + 1 , bac + n + 1 );
}

void dfs( int u )
{
    active[u] = 1;
    for( int v : ke[u] )
    {
        if( cha[v] == 0 )
        {
            cha[v] = u;
            dfs(v);
        }
        else if( active[v] ) check = 1;
    }
    active[u] = 0;
    ans.pb(u);
}

void xuli()
{
    For(i , 1 , n)
    {
        int u = bac[i].se;
        if( cha[u] == 0 )
        {
            cha[u] = u;
            dfs(u);
        }
    }
    if( check ) cout << "IMPOSSIBLE" << endl;
    else for( int u : ans ) cout << u << ' '; cout << endl;
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

