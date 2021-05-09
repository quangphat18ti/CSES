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

int Fen[2][maxn * 3] , maxx ;

struct query
{
    char loai;
    int x , y;
};
query q[maxn];

void nen()
{
    vi b; b.pb(0);
    For(i , 1 , n) b.pb(a[i]);
    For(i , 1 , m)
    {
        b.pb(q[i].y);
        if( q[i].loai == '?' ) b.pb(q[i].x);
    }
    sort(b.begin() , b.end());
    b.resize( unique(b.begin() , b.end()) - b.begin() );
    For(i , 1 , n) a[i] = lower_bound( b.begin() , b.end() , a[i] ) - b.begin();
    For(i , 1 , n)
    {
        q[i].y = lower_bound( b.begin() , b.end() , q[i].y ) - b.begin();
        if( q[i].loai == '?' )  q[i].x = lower_bound( b.begin() , b.end() , q[i].x ) - b.begin();
    }
}

void nhap()
{
    cin >> n >> m;
    For(i , 1 , n) cin >> a[i];
    For(i , 1 , m) cin >> q[i].loai >> q[i].x >> q[i].y;
    nen();

    maxx = n + m * 2;
}

void update( int i , int gt )
{
    Fen[0][i] += gt;
    while( i <= maxx )
    {
        Fen[1][i] += gt;
        i += i&-i;
    }
}

int get(int j , int i)
{
    int ans = 0;
    while( j <= i )
    {
        int tam = i&-i;
        if( i - tam + 1 >= j ) ans += Fen[1][i] , i -= tam;
        else ans += Fen[0][i] , i--;
    }
    return ans;
}

void xuli()
{
    For(i , 1 , n)
    {
        update(a[i] , 1);
    }
    For(i , 1 , m)
    {
        int x = q[i].x , y = q[i].y;
        if( q[i].loai == '!' )
        {
            update( a[x] , -1 );
            update( y , 1 );
            a[x] = y;
        }
        else
        {
            cout << get(x , y) << endl;
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


