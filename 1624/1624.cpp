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
#define LT "1624"
#define maxn 30
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int a[maxn][maxn];
int co[maxn] , c1[maxn] , c2[maxn];
int ans = 0;
int d[maxn][maxn];

void nhap()
{
    n = 8;
    For( i , 1 , 8 ) For( j , 1 , 8 )
    {
        char tam; cin >> tam;
        if( tam == '*' ) a[i][j] = 0;
        else a[i][j] = 1;
    }
}

void vet( int tam )
{
    if( tam > n )
    {
        ans++;
        return;
    }
    For( i , 1 , n )
    {
        if( !a[tam][i] ) continue;
        if( co[i] ) continue;
        if( c1[i + tam] ) continue;
        if( c2[i - tam + 8] > 0 ) continue;

        co[i]++;
        c1[i + tam]++;
        c2[i - tam + 8]++;
        d[tam][i] = 1;

        vet(tam + 1);

        co[i]--;
        c1[i + tam]--;
        c2[i - tam + 8]--;
        d[tam][i] = 0;
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

