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
#define LT "1164"
#define maxn 400005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int ans[maxn];

struct ii
{
    int l , r , vt;

    bool operator < ( ii a )
    {
        return l < a.l || ( l == a.l && r < a.r );
    }
};
ii a[maxn];

multiset <pii> st;

void nhap()
{
    cin >> n;
    For( i, 1, n ) cin >> a[i].l >> a[i].r , a[i].vt = i;
    sort( a+1 , a+n+1 );
}

void xuli()
{
    int mx = 1;
    int l = 1 , r = 1;
    ans[a[1].vt] = 1;
    st.insert({a[1].r , 1});

    For( i , 2 , n )
    {
        int vt = a[i].vt;

        pii tam = *st.begin();
        if( tam.fi < a[i].l )
        {
            ans[vt] = tam.se;
            st.erase(st.begin());
            st.insert( { a[i].r , tam.se } );
            continue;
        }
        else
        {
            ans[vt] = ++mx;
            st.insert( { a[i].r , mx }  );
        }
    }

    cout << mx << endl;
    For( i , 1 , n ) cout << ans[i] << ' '; cout << endl;
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

