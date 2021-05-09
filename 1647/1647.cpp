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
#define LT ""
#define maxn 200005
#define sz(A) int( A.size() )
#define ms( f, a, b, gt ) fill( f+a , f+b+1 , gt )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int a[maxn];
int RMQ[maxn][25];

int get( int i , int j )
{
    int kc = log2(j - i + 1);
    return min( RMQ[i][kc] , RMQ[j - (1<<kc) + 1][kc] );
}

void nhap()
{
    cin >> n >> k;
    For( i , 1 , n ) cin >> RMQ[i][0];

    For( j , 1 , log2(n) )
    For( i , 1 , n - (1 << j) + 1 ) RMQ[i][j] = min( RMQ[i][j - 1] , RMQ[i + (1<< (j - 1))][j - 1] );
}

void xuli()
{

    while( k -- )
    {
        int l , r; cin >> l >> r;
        cout <<  get(l , r) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(LT".inp","r",stdin);
    //freopen(LT".out","w",stdout);
    int t = 1;
//    cin >> t;
    while( t-- )
    {
        nhap();
        xuli();
    }
}


