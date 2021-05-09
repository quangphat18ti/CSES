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
#define LT ""
#define maxn 1652
#define sz(A) int( A.size() )
#define ms( f, a, b, gt ) fill( f+a , f+b+1 , gt )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int f[maxn][maxn];

void nhap()
{
    cin >> n >> m;
    For(i , 1, n)
    {
        For(j, 1, n)
        {
            char loai; cin >> loai;
            int tam = 0;
            if( loai == '*' ) tam = 1;
            f[i][j] = f[i - 1][j] + f[i][j - 1] + tam - f[i - 1][j - 1];
        }
    }
}

int Calc(int x1, int y1, int x2, int y2)
{
    return f[x2][y2] - f[x1 - 1][y2] - f[x2][y1 - 1] + f[x1-1][y1-1];
}

void xuli()
{
    while(m--)
    {
        int x1,y1 , x2,y2;
        cin>> x1>> y1>>x2>>y2;
        cout << Calc( x1, y1, x2, y2 ) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(LT".inp","r",stdin);
    //freopen(LT".out","w",stdout);
    int t = 1;
//    cin >> t;
    while( t-- )
    {
        nhap();
        xuli();
    }
}

