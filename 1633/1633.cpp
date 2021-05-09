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
#define LT "1633"
#define maxn 1000005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int mod = 1e9 + 7;
int f[maxn];

void nhap()
{
    cin >> n;
}

void xuli()
{
    f[0] = 1;
    For( i , 1 , n )
    {
        For( j , 1 , 6 )
        {
            if( i < j ) break;
            f[i] = ( f[i] + f[i - j] ) % mod;
        }
    }
    cout << f[n] << endl;
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

