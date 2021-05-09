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
#define LT "1662"
#define maxn 200005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int a[maxn];
map <int,int> dd;

void nhap()
{
    cin >> n;
    For( i , 1 , n ) cin >> a[i] , a[i] %= n;
    For( i , 1 , n ) if( a[i] < 0 ) a[i] += n;
}

void xuli()
{
    ll ans = 0;

    dd[0] = 1;
    int sum = 0;
    For( i , 1 , n )
    {
        sum += a[i];
        sum %= n;
        ans += dd[sum];
        dd[sum]++;
    }

    cout << ans << endl;
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

