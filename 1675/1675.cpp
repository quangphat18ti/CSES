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
#define LT "1675"
#define maxn 200005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;

struct Edge
{
    int u , v , w;
    bool operator < (Edge a)
    {
        return w < a.w;
    }
};
Edge a[maxn];

int ke[maxn] , gt[maxn];

void nhap()
{
    cin >> n >> m;
    For(i , 1 , m) cin >> a[i].u >> a[i].v >> a[i].w;
    sort( a + 1 , a+m+1 );
}

int root( int u )
{
    if( u != ke[u] ) ke[u] = root(ke[u]);
    return ke[u];
}

void xuli()
{
    For( i , 1 , n ) ke[i] = i , gt[i] = 1;
    ll ans = 0;
    For(i , 1 ,m)
    {
        int u = a[i].u , v = a[i].v;
        u = root(u) , v = root(v);
        if( u == v ) continue;
        ans += a[i].w;

        if( gt[u] > gt[v] ) ke[v] = u , gt[u] += gt[v];
        else ke[u] = v , gt[v] += gt[u];
    }

    int dem = 0;
    For(i , 1 , n) dem += (i == ke[i]);
    if( dem > 1 ) cout << "IMPOSSIBLE\n";
    else cout << ans << endl;
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

