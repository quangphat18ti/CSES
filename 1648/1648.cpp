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
ll Fen[2][maxn];

void update( int i , int gt )
{
    Fen[0][i] += gt;
    while( i <= n )
    {
        Fen[1][i] += gt;
        i += i&-i;
    }
}

ll get( int j , int i )
{
    ll ans = 0;
    while( i >= j )
    {
        int tam = i&-i;
        if( i - tam + 1 >= j ) ans += Fen[1][i] , i -= tam;
        else ans += Fen[0][i] , i--;
    }
    return ans;
}

void nhap()
{
    cin >> n >> m;
    For( i , 1 , n )
    {
        int x; cin >> x;
        update( i , x - Fen[0][i] );
    }
}

void xuli()
{
    while( m-- )
    {
        int loai; cin >> loai;
        int l , r; cin >> l >> r;
        if( loai == 1 )
        {
            update( l , r  - Fen[0][l] );
        }
        else
        {
            cout << get(l , r) << endl;
        }
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

