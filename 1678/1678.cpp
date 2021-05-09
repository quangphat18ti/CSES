/// Tìm 1 chu trình trên đồ thị có hướng

//Nhận xét:
//    - Nếu u -> v và v đã được đi rồi và đang đi trong cây con gốc v thì ta sẽ tìm ra được chu trình.
//    - Từ ý tưởng trên thì ta sẽ lưu 1 mảng active[u].
//    - Nếu active[u] = 1 thì đang đi trong cây con gốc u và nếu là 0 thì không đi

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
#define LT "1678"
#define maxn 100005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
vector<int> ke[maxn];
pii bac[maxn];
int kt[maxn] , tr[maxn] , active[maxn] , check = 0;

void nhap()
{
    cin >> n >> m;
    For(i , 1 , m)
    {
        int u , v;
        cin >> u >> v;
        bac[v].fi++;
        ke[u].pb(v);
    }
    For(i , 1, n) bac[i].se = i;
    sort( bac + 1 , bac + n + 1 );
}

void truyvet( int u , int v )
{
    vi ans;
    ans.pb(v);
    while( u != v )
    {
        ans.pb(u);
        u = tr[u];
    }
    ans.pb(v);
    cout << ans.size() << endl;
    FOr( i , ans.size() - 1 , 0 ) cout << ans[i] << ' ';
}

void dfs( int u  )
{
    kt[u] = 1;
    active[u] = 1;
    for( int v : ke[u] )
    {
        if( kt[v] == 0 ) tr[v] = u , dfs(v);
        else
        {
            if( active[v] && check == 0 )
            {
                check = 1;
                truyvet( u , v );
            }
        }
    }
    active[u] = 0;
}

void xuli()
{
    For(i , 1 , n)
    {
        int u = bac[i].se;
        if( kt[u] ) continue;
        dfs(u);
        if( check ) return;
    }
    cout << "IMPOSSIBLE\n";
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

