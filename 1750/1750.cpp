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
#define LT "1750"
#define maxn 200005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int f[maxn][35];

void nhap()
{
    cin >> n >> m;
    For(i , 1 , n)
    {
        int x; cin >> x;
        f[i][0] = x;
    }

    For(j , 1 , 30) For(i , 1 , n)
        f[i][j] = f[ f[i][j - 1] ][j - 1];
}

void xuli()
{
    while(m--)
    {
        int u , k; cin >> u >> k;
        FOr(i , 30 , 0)
            if( (k >> i) & 1 ) u = f[u][i];

        cout << u << endl;
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
