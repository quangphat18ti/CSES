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
#define LT "1672"
#define maxn 505
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
ll f[maxn][maxn] , vc = 1e18;

void Min( ll &a , ll b ) { if( a > b ) a = b; }

void nhap()
{
    cin >> n >>  m >> k;
    For( i , 1 , n ) For( j , 1 , n ) f[i][j] = vc;
    For( i , 1 , n ) f[i][i] = 0;
    For( i , 1 , m )
    {
        int u , v; ll w;
        cin >> u >> v >> w;
        Min( f[u][v] , w );
        Min( f[v][u] , w );
    }
}

void xuli()
{
    For( k , 1 , n )
    {
        For( i , 1 , n )
        {
            For( j , 1 , n )
            {
                f[i][j] = min( f[i][j] , f[i][k] + f[k][j] );
            }
        }
    }

    while( k-- )
    {
        int u , v; cin >> u >> v;
        if( f[u][v] == vc ) cout << -1 << endl;
        else cout << f[u][v] << endl;
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

