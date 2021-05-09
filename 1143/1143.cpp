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
ll IT[maxn * 4];

void Build(int id, int l, int r)
{
    if(l == r) {IT[id] = a[l]; return;}
    int mid = (l+r) >> 1;
    Build(id*2, l, mid);
    Build(id*2+1, mid+1, r);
    IT[id] = max(IT[id*2] , IT[id*2+1]);
}

void update(int id, int l, int r, int vt, int gt)
{
    if( l > vt || r < vt ) return;
    if(l == r){ IT[id] += gt; return; }
    int mid = (l+r) >> 1;
    update(id*2, l, mid, vt, gt);
    update(id*2+1, mid+1, r, vt, gt);
    IT[id] = max(IT[id*2] , IT[id*2+1]);
}

int get( int id, int l, int r, int gt )
{
    if( l == r ) return l;
    int mid = (l+r) >> 1;
    if( IT[id*2] >= gt ) return get(id*2, l, mid, gt);
    return get(id*2+1, mid+1, r, gt);
}

void nhap()
{
    cin >> n >> m;
    For( i , 1 , n ) cin >> a[i];
    Build(1, 1, n);
}

void xuli()
{
    while(m--)
    {
        int x; cin >> x;
        ll Lim = IT[1];
        if( x > Lim ) { cout << 0 << ' '; continue; }
        int gt = get(1, 1, n, x);
        cout << gt << ' ';
        update(1, 1, n, gt, -x);
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


