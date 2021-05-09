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
#define LT "1091"
#define maxn 200005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int a[maxn];
multiset <int> st;

void nhap()
{
    cin >> n >> m;
    For(i , 1 , n)
    {
        int x; cin >> x;
        st.insert(x);
    }

    For( i , 1 , m ) cin >> a[i];
}

void xuli()
{
    For( i , 1 , m )
    {
        auto tam = st.upper_bound( a[i] );
        if( tam == st.begin() ) { cout << -1 << endl; continue; }
        tam--;
        cout << *tam << endl;
        st.erase( tam );
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
