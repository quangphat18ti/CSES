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
#define LT "1637"
#define maxn 1000005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int f[maxn];

void nhap()
{
    cin >> n;
}

void xuli()
{
    For( i , 0 , n ) f[i] = -1;
    queue <int> st;
    st.push(n); f[n] = 0;
    while( !st.empty() )
    {
        int u = st.front(); st.pop();
        if( u == 0 ) break;
        /// loang

        int tam = u;
        while( tam > 0 )
        {
            int cs = tam % 10;
            tam /= 10;
            int v = u - cs;
            if( f[v] == -1 )
            {
                f[v] = f[u] + 1;
                st.push(v);
            }
        }

        ///
    }

    cout << f[0] << endl;
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

