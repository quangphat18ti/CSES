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
pii IT[maxn * 4];

void nhap()
{
    cin >> n;
    For(i , 1 , n) cin >> a[i];
}

void Build( int id, int l, int r )
{
    if( l == r ) { IT[id].fi = l; return; }
    int mid = (l+r) >> 1;
    Build(id*2, l, mid);
    Build(id*2+1, mid+1, r);
    IT[id].fi = max(IT[id*2].fi , IT[id*2+1].fi);
}

void pushid(int id)
{
    int tam = IT[id].se;
    IT[id].se = 0;

    IT[id*2].fi += tam;
    IT[id*2].se += tam;

    IT[id*2+1].fi += tam;
    IT[id*2+1].se += tam;
}

int get(int id, int l, int r, int gt)
{
    if( l == r ) { return l; }
    int mid = (l+r) >> 1;
    pushid(id);
    if(IT[id*2].fi >= gt) return get(id*2, l, mid, gt);
    return get(id*2+1, mid+1, r, gt);
}

void update(int id, int l, int r, int u, int v, int gt)
{
    if( l > v || r < u ) return;
    if( l >= u && r <= v )
    {
        IT[id].fi += gt;
        IT[id].se += gt;
        return;
    }

    int mid = (l+r) >> 1;
    pushid(id);

    update(id*2, l, mid, u, v, gt);
    update(id*2+1, mid+1, r, u, v, gt);
    IT[id].fi = max(IT[id*2].fi , IT[id*2+1].fi);
}

void xuli()
{
    Build(1, 1, n);
    For(z , 1 , n)
    {
        int x; cin >> x;
        int res = get( 1, 1, n, x);
        cout << a[res] << ' ';
        update( 1, 1, n, res, res, -n );
        update( 1 , 1 , n , res+1 , n , -1 );
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

