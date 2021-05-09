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
#define LT "1158"
#define maxn 1005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
pii a[maxn];
int f[1005][100005];

void nhap()
{
    cin >> n >> k;
    For(i , 1 , n) cin >> a[i].fi;
    For(i , 1 , n) cin >> a[i].se;
}

void xuli()
{
    For(i , 1 , n)
    {
        For( j , 1 , k )
        {
            f[i][j] = max( f[i - 1][j] , f[i][j - 1] );
            if( j >= a[i].fi ) f[i][j] = max( f[i][j] , f[i - 1][j - a[i].fi] + a[i].se );
        }
    }
    cout << f[n][k] << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp","r",stdin);
//    freopen(LT".onp","r",stdin);
    int t = 1;
//    cin >> t;
    while( t-- )
    {
        nhap();
        xuli();
    }
}
