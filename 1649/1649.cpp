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
int IT[maxn*4];

void update( int id, int l, int r, int vt, int gt )
{
    if( l > vt || r < vt ) return;
    if( l == r )
    {
        IT[id] = gt;
        return;
    }

    int mid = (l+r) >> 1;
    update(id*2,l,mid,vt,gt);
    update(id*2+1,mid+1,r,vt,gt);
    IT[id] = min ( IT[id*2] , IT[id*2+1] );
}

int get(int id, int l, int r, int u, int v)
{
    if( l > v || r < u ) return 1e9+5;
    if( l >= u && r <= v ) return IT[id];
    int mid = (l+r) >> 1;
    return min( get(id*2,l,mid,u,v) , get(id*2+1,mid+1,r,u,v) );
}

void nhap()
{
    cin >> n >> m;
    For( i , 1 , n )
    {
        int x; cin >> x;
        update(1, 1, n, i, x);
    }
}

void xuli()
{
    while(m--)
    {
        int loai , x , y;
        cin >> loai >> x >> y;

        if( loai == 1 )
        {
            update(1, 1, n, x, y );
        }
        else cout << get(1, 1, n, x, y) << endl;
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


