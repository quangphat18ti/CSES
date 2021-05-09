#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define db double
#define LT "1666"
#define maxn 100005
#define fi first
#define se second
#define For(i , a , b) for( int i = int(a) ; i <= int(b) ; i++ )
#define FOr(i , a , b) for( int i = int(a) ; i >= int(b) ; i-- )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
vii a;
int ke[maxn] , gt[maxn];

void nhap()
{
    cin >> n >> m;
    For( i , 1 , m )
    {
        int x , y; cin >> x >> y;
        a.pb( { x , y } );
    }
}

int root( int s )
{
    if( s != ke[s] ) ke[s] = root(ke[s]);
    return ke[s];
}

void Union( int u , int v )
{
    u = root(u); v = root(v);
    if( u == v ) return;
    if( gt[u] > gt[v] ) ke[v] = u , gt[u] += gt[v];
    else ke[u] = v , gt[v] += gt[u];
}

void xuli()
{
    For(i , 1 , n)
    {
        ke[i] = i;
        gt[i] = 1;
    }

    For( i , 0 , m - 1 )
    {
        int u = a[i].fi , v = a[i].se;
        Union(u , v);
    }

    vector<int> ans;
    For( i , 1 , n ) if( ke[i] == i ) ans.pb( i );
    cout << ans.size() - 1 << endl;
    For( i , 0 , ans.size() - 2 ) cout << ans[i] << ' ' << ans[i + 1] << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp","r",stdin);
//    freopen(LT".out","w",stdout);
    nhap();
    xuli();
}

