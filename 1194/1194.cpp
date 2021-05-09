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
#define LT "1194"
#define maxn 1005
#define sz(A) int( A.size() )

#define f(a) f[a.fi][a.se]
#define g(a) g[a.fi][a.se]
#define tr(a) tr[a.fi][a.se]

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
char a[maxn][maxn];

int di[10] = { 0 , -1 , 0 , 1 , 0 , -1};
char huong[10] = { '0' , 'U' , 'R' , 'D' , 'L' };

pii S;
int f[maxn][maxn] , tr[maxn][maxn] , g[maxn][maxn];
vector<pii> Mon;

void nhap()
{
    cin >> n >> m;
    For( i , 1 , n ) For(j , 1 , m) cin >> a[i][j];
    For(i , 1 , n) For(j , 1 , m) if(a[i][j] == 'A') S = {i , j};
    For(i , 1 , n) For(j , 1 , m) if(a[i][j] == 'M') Mon.pb( {i , j} );
}

bool check(int x , int y) { return (x >= 1 && x <= n && y >= 1 && y <= m); }

void trace(int x , int y)
{
    vector<char> ans;
    while( x != S.fi || y != S.se )
    {
        int tam = tr[x][y];
        ans.pb( huong[tam] );
        x -= di[tam];
        y -= di[tam + 1];
    }
    cout << ans.size() << endl;
    FOr( i , ans.size()  - 1 , 0 ) cout << ans[i];
}

void bfs()
{
    For( i , 1 , n ) For( j , 1 , m ) g[i][j] = 1e9;

    queue <pii> st;
    for( pii tam : Mon )
    {
        st.push(tam);
        g(tam) = 1;
    }

    while(!st.empty())
    {
        pii tam = st.front(); st.pop();
        int x = tam.fi , y = tam.se;
        For( i , 1 , 4 )
        {
            int x_ = x + di[i] , y_ = y + di[i + 1];
            if( !check(x , y) ) continue;
            if( a[x_][y_] == '#' ) continue;
            if( g[x_][y_] < 1e9 ) continue;
            g[x_][y_] = g[x][y] + 1;
            st.push({ x_ , y_ });
        }
    }
}

void loang( pii s )
{
    queue <pii> st;    st.push(s);
    f(s) = 1;  tr(s) = 0;

    while(!st.empty())
    {
        pii tam = st.front(); st.pop();
        int x = tam.fi , y = tam.se;

        For( i , 1 , 4 )
        {
            int x_ = x + di[i] , y_ =  y + di[i + 1];

            if( !check(x_ , y_) ) /// Ngoài bảng
            {
                cout << "YES\n";
                trace(x , y);
                return;
            }

            if( f[x][y] + 1 >= g[x_][y_] ) continue;

            if( a[x_][y_] == '.' && f[x_][y_] == 0 ) ///  chưa đi
            {
                tr[x_][y_] = i;
                f[x_][y_] = f[x][y] + 1;
                st.push( { x_ , y_ } );
            }
        }
    }
    cout << "NO\n";
}

void xuli()
{
    bfs();
    loang(S);
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
