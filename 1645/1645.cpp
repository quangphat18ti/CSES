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
#define LT "1645"
#define maxn 200005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int a[maxn];
int Fen[maxn];

void nen()
{
    vi u;
    For( i , 1 , n ) u.pb(a[i]);
    sort( u.begin() , u.end() );
    u.resize( unique( u.begin() , u.end() ) - u.begin() );
    For( i , 1 , n ) a[i] = lower_bound( u.begin() , u.end() , a[i] ) - u.begin() + 1;
}

void nhap()
{
    cin >> n;
    For( i , 1 , n ) cin >> a[i];
    nen();
}

int get( int i )
{
    int ans = 0;
    while( i > 0 )
    {
        ans = max( ans , Fen[i] );
        i -= i&-i;
    }
    return ans;
}

void update( int i , int gt )
{
    while( i <= n )
    {
        Fen[i] = max( Fen[i] , gt );
        i += i & -i;
    }
}

void xuli()
{
    For( i , 1 , n )
    {
        cout << get( a[i] - 1 ) << ' ';
        update( a[i] , i );
    }
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
