///

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define INC( i , a , b ) for(int i = int(a) ; i <= int(b) ; i++)
#define For( i , a , b ) for(int i = int(a) ; i <= int(b) ; i++)
#define DEC( i , a , b ) for(int i = int(a) ; i >= int(b) ; i--)
#define FOr( i , a , b ) for(int i = int(a) ; i >= int(b) ; i--)
#define fi first
#define se second
#define mp make_pair
#define LT "1667"
#define maxn 100005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
vi dsk[maxn];
int tr[maxn];

void nhap()
{
    cin >> n >> m;
    For(i , 1 , m)
    {
        int u , v; cin >> u >> v;
        dsk[u].pb(v);
        dsk[v].pb(u);
    }
}

void loang()
{
    queue <int> st; st.push(1);
    while(!st.empty())
    {
        int u = st.front(); st.pop();
        for(int v : dsk[u])
        {
            if(tr[v]) continue;
            tr[v] = u;
            st.push(v);
        }
    }
}

void truyvet()
{
    vector<int> ans;
    int u = n;
    while( u != 1 )
    {
        ans.pb(u);
        u = tr[u];
    }
    ans.pb(1);
    reverse( ans.begin() , ans.end() );
    cout << ans.size() << endl;
    for( int u : ans ) cout << u << ' '; cout << endl;
}

void xuli()
{
    tr[1] = 1;
    loang();
    if( tr[n] == 0 ) { cout << "IMPOSSIBLE" << endl; return; }
    truyvet();
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
