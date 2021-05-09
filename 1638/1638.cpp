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
#define LT "1638"
#define maxn 1005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
char a[maxn][maxn];
int mod = 1e9 + 7;
int f[maxn][maxn];

void nhap()
{
    cin >> n;
    For( i , 1 , n ) For( j , 1 , n ) cin >> a[i][j];
}

void xuli()
{
    f[1][0] = 1;
    For( i , 1 , n )
    {
        For( j , 1 , n )
        {
            if( a[i][j] == '*' ) f[i][j] = 0;
            else f[i][j] = f[i - 1][j] + f[i][j - 1];
            f[i][j] %= mod;
        }
    }

    cout << f[n][n] << endl;
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

