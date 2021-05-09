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
#define LT "1634"
#define maxn 105
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int a[maxn];
int f[1000005];
int vc = 1e9;

void nhap()
{
    cin >> n >> k;
    INC( i , 1 , n ) cin >> a[i];
    sort( a + 1 , a + n + 1 );
}

void xuli()
{
    INC( i , 1 , k ) f[i] = vc;

    f[0] = 0;
    INC( i , 1 , k )
    {
        INC( j , 1 , n )
        {
            if( a[j] > i || f[i - a[j]] == vc ) continue;
            f[i] = min( f[i] , f[i - a[j]] + 1 );
        }
    }

    if( f[k] >= vc ) cout << - 1 << endl;
    else cout << f[k] << endl;
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

