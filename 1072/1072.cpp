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
#define LT "1072"
#define maxn
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
ll tong = 0;

void nhap()
{
    cin >> n;
}

ll Count( int s )
{
    ll tam = 1ll * s * s - 1;
    ll tong = (tam + 1) * tam / 2;

    ll ans = 0;
    ans += max( 0ll , 4ll * (s - 2) * (s - 1) );

    return tong - ans;
}

void xuli()
{
    For( i , 1 , n )
    {
        cout << Count(i) << endl;
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
