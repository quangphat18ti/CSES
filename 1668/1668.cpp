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
#define LT "1668"
#define maxn 100005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
vi dsk[maxn];
int kt[maxn];
int check = 0;

void nhap()
{
    cin >> n >> m;
    For( i, 1 , m )
    {
        int u , v; cin >> u >> v;
        dsk[u].pb(v);
        dsk[v].pb(u);
    }
}

void dfs( int u  )
{
    for( int v : dsk[u] )
    {
        if( kt[v] == -1 )
        {
            kt[v] = 1 - kt[u];
            dfs( v );
        }
        else  if( kt[v] == kt[u] ) check = 1;
    }
}

void xuli()
{
    For( i , 1,  n ) kt[i] = -1;
    For(i , 1 , n)
    {
        if( kt[i] == -1 )
        {
            kt[i] = 0;
            dfs(i);
        }
    }

    if( check ) { cout << "IMPOSSIBLE\n"; return; }
    For( i , 1 , n )
    {
        if( kt[i] == 0 ) cout << 2 << ' ';
        else cout << kt[i] << ' ';
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

