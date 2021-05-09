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
#define LT "1745"
#define maxn 105
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int a[maxn];
int f[maxn][maxn * 1000];
int sum = 0;

void nhap()
{
    cin >> n;
    For(i , 1 , n) cin >> a[i];
    For(i , 1 , n) sum += a[i];
}

void xuli()
{
    f[0][0] = 1;
    For(i , 1 , n)
    {
        For(j , 0 , sum)
        {
            f[i][j] = f[i - 1][j];
            if( j >= a[i] && f[i - 1][j - a[i]] ) f[i][j] = 1;
        }
    }

    vi ans;
    For( j , 1 , sum ) if(f[n][j]) ans.pb( j );
    cout << ans.size() << endl;
    for(int u : ans) cout << u << ' ';
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

