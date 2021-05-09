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
#define LT "1097"
#define maxn 5005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int a[maxn];
pair<ll,ll> f[maxn][maxn];
ll vc = 1e18;

void nhap()
{
    cin >> n;
    For(i , 1, n) cin >> a[i];
}

void Max( pair<ll,ll> &a, pair<ll,ll> b )
{
    if( a.fi < b.fi ) a = b;
}

void xuli()
{
    For( l , 0 , n - 1 )
    {
        For( i , 1 , n )
        {
            int j = i + l; if(j > n) j -= n;
            if(i == j) { f[i][j] = { a[i] , 0 }; continue; }
            f[i][j] = {-vc , -vc};
            Max( f[i][j] , { a[i] + f[i + 1][j].se , f[i + 1][j].fi } );
            Max( f[i][j] , { a[j] + f[i][j - 1].se , f[i][j - 1].fi } );
        }
    }

    cout << f[1][n].fi << endl;
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
