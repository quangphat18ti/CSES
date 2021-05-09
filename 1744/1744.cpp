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
#define LT "1744"
#define maxn 505
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int f[maxn][maxn];

void nhap()
{
    cin >> n >> m;
}

void Min( int &a , int b ) { if( a > b ) a = b; }

void xuli()
{
    For( i , 1 , n )
    {
        For( j , 1 , m )
        {
            f[i][j] = 1e9;
            if( i == j ) { f[i][j] = 0; continue; }

            For( ires , 1 , i/2 )
                Min( f[i][j] , f[ires][j] + f[i - ires][j] + 1 );

            For( jres , 1    , j/2 )
                Min( f[i][j] , f[i][jres] + f[i][j - jres] + 1 );
        }
    }

    cout << f[n][m];
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

