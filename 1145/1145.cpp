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
#define LT "1145"
#define maxn 200005
#define sz(A) int( A.size() )
 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
 
int i , j , n , m , k;
int a[maxn];
int f[maxn] , g[maxn] , mx = 0;
 
void nhap()
{
    cin >> n;
    For( i , 1 , n  ) cin >> a[i];
}
 
int chat( int l , int r , int gt )
{
    while( l <= r )
    {
        int mid = (l + r) >> 1;
        if( g[mid] < gt ) l = mid + 1;
        else r = mid - 1;
    }
    return l - 1;
}
 
void xuli()
{
    mx = 0; g[mx] = 0;
    For( i , 1 , n )
    {
        int tam = chat( 0 , mx , a[i] );
        f[i] = tam + 1;
        if( f[i] > mx ) mx = f[i] , g[mx] = a[i];
        else g[f[i]] = min( g[f[i]] , a[i] );
    }
    cout << *max_element( f + 1 , f + n + 1 ) << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp","r",stdin);
//    freopen(LT".out","w",stdout);
    nhap();
    xuli();
}
