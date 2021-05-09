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
#define LT "1163"
#define maxn
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int x;
set <pii> st;
multiset <int> len;

void nhap()
{
    cin >> x >> n;
}

void xuli()
{
    st.insert( { 0 , x } );
    len.insert( x );

    while( n-- )
    {
        int vt; cin >> vt;
        auto tam = --st.upper_bound( {vt , 0} );

        pii res = *tam;
        int l = res.fi , r = res.se;
        len.erase( len.find( r - l ) );
        st.erase( tam );

        st.insert( { l , vt } ); len.insert( vt - l);
        st.insert( { vt , r } ); len.insert( r - vt);

        cout << *len.rbegin() << ' ';
    }
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
