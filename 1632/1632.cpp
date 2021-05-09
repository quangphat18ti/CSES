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
#define LT "1632"
#define maxn 200005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
pii a[maxn];

bool ss( pii a , pii b )
{
    return a.se < b.se || ( a.se == b.se && a.fi > b.fi );
}

void nhap()
{
    cin >> n >> k;
    For( i , 1 , n ) cin >> a[i].fi >> a[i].se;
    sort( a + 1 , a + n + 1 , ss );
}

void xuli()
{
    int ans = 0;
    multiset<int> st;

    For( i , 1 , n )
    {
        if( st.empty() )
        {
            st.insert( a[i].se );
            ans++;
            continue;
        }

        auto tam = st.upper_bound( a[i].fi );
        if( tam == st.begin() )
        {
            if( st.size() == k ) continue;
            st.insert( a[i].se );
            ans++;
        }
        else
        {
            tam--;
            st.erase(tam);
            st.insert( a[i].se );
            ans++;
        }
    }

    cout << ans << endl;
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

