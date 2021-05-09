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
#define LT ""
#define maxn 100005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int mod = 1e9 + 7;
int a[maxn];
unsigned int f[maxn][105];

void nhap()
{
    cin >> n >> m;
    For(i , 1 , n) cin >> a[i];
}

void xuli()
{
    if( a[1] > 0 ) f[1][a[1]] = 1;
    else For(i , 1 , m) f[1][i] = 1;

    For(i , 2 , n)
    {
        if(a[i] != 0)
        {
            f[i][a[i]] = ( f[i - 1][a[i] + 1] + f[i - 1][a[i]] + f[i - 1][a[i] - 1] ) % mod;
            continue;
        }

        For(j, 1 , m) f[i][j] = ( f[i - 1][j + 1] + f[i - 1][j] + f[i - 1][j - 1] ) % mod;
    }

    int ans = 0;
    For(i , 1 , m) ans = ( ans + f[n][i] ) % mod;
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

