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
#define LT "1623"
#define maxn 25
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
ll a[maxn];
ll ans = 1e18;
ll tong = 0 , res = 0;

void nhap()
{
    cin >> n;
    For( i , 1 , n ) cin >> a[i] , tong += a[i];
}

void vet( int tam )
{
    if( tam > n )
    {
        ans = min( ans , abs( (tong - res) - res ) );
        return;
    }

    For( i , 0 , 1 )
    {
        res += i * a[tam];
        vet(tam + 1);
        res -= i * a[tam];
    }
}

void xuli()
{
    vet(1);
    cout << ans << endl;
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

