/// Cho 1 số n. Nếu n == 1 thì dừng.
/// if n lẻ thì thì n = n * 3 + 1;
/// if n chẵn thì n = n / 2;

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
#define LT "1068"
#define maxn
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , m , k;
ll n;

void nhap()
{
    cin >> n;
}

void xuli()
{
    while( n != 1 )
    {
        cout << n << ' ';
        if( n % 2 ) n = n * 3 + 1;
        else n /= 2;
    }
    cout << 1 << endl;
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
