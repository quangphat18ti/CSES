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
#define LT "1093"
#define maxn 505
#define sz(A) int( A.size() )
 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
 
int i , j , n , m , k;
unsigned int mod = 1e9 + 7;
int tong = 0;
unsigned int f[maxn][maxn * maxn];
 
void nhap()
{
    cin >> n;
    tong = n * (n + 1) / 2;
}
 
void xuli()
{
    if( tong % 2 ) { cout << 0 << endl; return; }
 
    mod *= 2;
 
    tong /= 2;
    f[0][0] = 1;
    For( i , 1 , n )
    {
        For( j , 0 , tong )
        {
            f[i][j] = f[i - 1][j];
            if( j >= i ) f[i][j] = ( f[i][j] + f[i - 1][j - i] ) % mod;
        }
    }
 
    cout << f[n][tong] / 2 << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp","r",stdin);
//    freopen(LT".out","w",stdout);
    nhap();
    xuli();
}
