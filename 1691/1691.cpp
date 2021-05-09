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
#define LT "1691"
#define maxn 100005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
vii ke[maxn];
int kt[maxn * 2];

void nhap()
{
    cin >> n >> m;
    For( i , 1 , m )
    {
        int u , v; cin >> u >> v;
        ke[u].pb( {v , i} );
        ke[v].pb( {u , i} );
    }
}

void xuli()
{
    For( i , 1 , n )
    {
        if( sz(ke[i]) % 2 )
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    vi ans;
    stack <int> st;  /// chứa giá trị các đỉnh chưa được đi
    st.push(1);
    while( !st.empty() )
    {
        int u = st.top();

        while( (ke[u].size() > 0) && kt[ ke[u].back().se ] == 1 ) ke[u].pop_back();

        if( ke[u].size() == 0 )
        {
            st.pop();
            ans.pb(u);
        }
        else
        {
            st.push( ke[u].back().fi );
            kt[ ke[u].back().se ] = 1;
            ke[u].pop_back();
        }
    }

    if( ans.size() - 1 != m ) { cout << "IMPOSSIBLE" << endl; return; }
    if( ans[0] != ans.back() ) { cout << "IMPOSSIBLE" << endl; return; }

    for( int u : ans ) cout << u << ' '; cout << endl;
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

