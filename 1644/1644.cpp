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
#define LT "1644"
#define maxn 200005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int a[maxn];
int l , r;
ll vc = 1e16;
ll IT[maxn*4];
ll f[maxn];

void nhap()
{
    cin >> n >> l >> r;
    For(i, 1, n) cin >> a[i];
}

void update(int id, int l, int r, int vt, ll gt)
{
    if( l > vt || r < vt ) return;
    if( l == r ) { IT[id] = gt; return; }
    int mid = (l + r) >> 1;
    update( id*2, l, mid, vt, gt );
    update( id*2+1, mid+1, r, vt, gt );
    IT[id] = min( IT[id*2], IT[id*2+1] );
}

ll get( int id, int l, int r, int u, int v )
{
    if( l > v || r < u ) return vc;
    if( l >= u && r <= v ) return IT[id];
    int mid = (l + r) >> 1;
    return min( get(id*2, l, mid, u, v) , get(id*2+1, mid+1, r, u, v) );
}

void xuli()
{
    ll ans = 0 , sum = 0;

    update( 1 , 0 , n , 0 , 0 );

    sum = 0;
    For( i , 1 , n )
    {
        sum += a[i] ;
        update( 1 , 0 , n , i , sum );
    }

    sum = 0;
    For( i , 1 , n )
    {
        sum += a[i];
        f[i] = -vc;
        if( i < l ) continue;
        ll res = get( 1 , 0 , n , max(0 , i - r) , i - l );
        f[i] = sum - res;
    }

    cout << *max_element( f + 1 , f + n + 1 ) << endl;
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
