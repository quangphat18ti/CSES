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
#define LT "1629"
#define maxn 400005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
pii a[maxn];
unordered_map <int,int> dd;
vi ke[maxn];
int f[maxn];

void nen()
{
    vi u;
    For( i , 1 , n ) u.pb( a[i].fi ) , u.pb( a[i].se );
    sort( u.begin() , u.end() );

    m = unique( u.begin() , u.end() ) - u.begin() - 1;
    For( i , 1 , m ) dd[u[i]] = i + 1;

    For( i , 1 , n ) a[i].fi = dd[a[i].fi] , a[i].se = dd[a[i].se];
}

void nhap()
{
    cin >> n;
    For( i , 1 , n ) cin >> a[i].fi >> a[i].se;
    sort( a + 1 , a + n + 1 );
    nen();
}

void xuli()
{
    For( i , 1 , n ) ke[a[i].se].pb( a[i].fi );

    f[0] = 0;
    For( i , 1 , m + 1 )
    {
        f[i] = f[i - 1];
        for( int u : ke[i] ) f[i] = max( f[i] , f[u] + 1 );
    }
    cout << f[m + 1] << endl;
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

