/// Cho đồ thị có hướng và trọng số. Tìm 1 chu trình âm bất kì của đồ thị

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
#define LT "1197"
#define maxn 2505
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
ll f[maxn], vc = 1e16;
int tr[maxn];
int kt = 0;

struct canh { int u , v , w; };
vector<canh> st;

void nhap()
{
    cin >> n >> m;
    For(i , 1, m)
    {
        int u , v, w; cin >> u >> v >> w;
        st.pb( { u,v,w} );
    }
}

bool check( int u , int v )
{
    while( u > 0 )
    {
        if( u == v ) return 1;
        u = tr[u];
    }
    return 0;
}

void truyvet( int u , int v )
{
    vi ans; ans.pb(v);
    while( true )
    {
        ans.pb(u);
        if( u == v ) break;
        u = tr[u];
    }

    FOr( i , ans.size() - 1 , 0 ) cout << ans[i] << ' '; cout << endl;
}

void xuli()
{
    For(i , 1 , n) f[i] = vc;
    f[1] = 0;

    For(i , 1 , n)
    {
        For(j, 0 , m - 1)
        {
            int u = st[j].u , v = st[j].v , w = st[j].w;
            if( f[v] > f[u] + w )
            {
                if( check(u , v) )
                {
                    cout << "YES\n";
                    truyvet(u , v);
                    return;
                }

                f[v] = f[u] + w;
                tr[v] = u;
            }
        }
    }

    cout << "NO";
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
