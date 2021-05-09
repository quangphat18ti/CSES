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
#define LT "1090"
#define maxn 200005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int a[maxn];
int kt[maxn];

void nhap()
{
    cin >> n >> k;
    For(i , 1 , n) cin >> a[i];
}

void xuli()
{
    int ans = 0;

    multiset <pii> st;
    For( i , 1 , n ) st.insert( { a[i] , i } );

    For( i , 1 , n )
    {
        if( kt[i] ) continue;
        ans++;

        kt[i] = 1;
        st.erase( st.find( {a[i] , i} ) );

        auto vt = st.upper_bound( { k - a[i] , 1e9 } );
        if( vt == st.begin() ) continue;
        vt--;

        kt[(*vt).se] = 1;
        st.erase(vt);
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

