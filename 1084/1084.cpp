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
#define LT "1084"
#define maxn 200005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int b[maxn];
pii a[maxn];

void nhap()
{
    cin >> n >> m >> k;
    For( i , 1 , n )
    {
        int x; cin >> x;
        a[i].fi = x - k;
        a[i].se = x + k;
    }

    For( i , 1 , m ) cin >> b[i];

    sort( a + 1 , a + n + 1 );
    sort( b + 1 , b + m + 1 );
}

bool check( int x , int y )
{
    return ( x <= n && y <= m && b[y] >= a[x].fi && b[y] <= a[x].se );
}

void xuli()
{
    int ans = 0;

    int ct1 = 1 , ct2 = 1;
    while ( ct1 <= n && ct2 <= m )
    {
        while( !check( ct1 , ct2 ) )
        {
            while( ct2 <= m && a[ct1].fi > b[ct2] ) ct2++;
            while( ct1 <= n && a[ct1].se < b[ct2] ) ct1++;
            if( ct1 > n || ct2 > m ) break;
        }
        if( check(ct1 , ct2) ) ans++;
        ct1++ , ct2++;
    }

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

