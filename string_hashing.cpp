/*
Allaih is Almighty
Bismillahhi Rahmanir Rahim
Baishakh
*/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define ll long long
const int mod = 1e9+7;
//const int mod = 1000000123; arekta mod for safe from 1e9+7;
// s.order_of_key(x) -> values total are small than x
// *s.find_by_order(x)  -> kth small elemnt (index) in pbds
const int mx = 1e6+10;
vector<ll>power(mx,1),inv(mx,1),hashv(mx);/// power value in index,
/// inverse value of index power and hashvalue for the string
ll base = 47; /// base for do char * base;
ll be(ll a,ll b) /// final exponential
{
  ll ans = 1;
  while(b)
  {
    if(b & 1) ans = (ans * a) %mod;
    b >>= 1;
    a = (a * a) % mod;
  }
  return ans;
}
void pow()
{
  for(int i = 1;i<mx;i++)
  {
    power[i] = (power[i-1] * base) % mod; /// store   (base ^ i)
    inv[i] = be(power[i],mod-2);
  }
}
void hashh(string &s) /// ((base^i) * s[i] ) % mod
{
  int n = s.size();
  ll pre = 0;
  for(int i = 0;i<n;i++)
  {
    pre = (pre + (power[i] * (s[i]-'a' + 1))) % mod; /// hash for prefix all char
    hashv[i] = pre; 
  }
}
ll chv(int i,int j) /// checking hash from string i to j index
{
  ll ans = 0;
  ans = hashv[j];
  if(i-1 >= 0) 
  ans -= hashv[i-1];
  ans += mod;
  ans = (ans * inv[i])%mod; /// power[i] divide so multiply inv of power of i
  return ans;
}
int main()
{
    string ss,tar;
    cin>>ss>>tar;
    ll t = 0;
    int n = tar.size();
    int nn = ss.size();
    pow();
    hashh(ss);
    for(int i = 0;i<n;i++) /// hash value of target index;
    {
      t = ( t + (power[i] * (tar[i]-'a'+1))) % mod;
      t = t % mod;
    }
    ll ans = 0;
    for(int i = 0;i+n-1 < nn;i++) /// check in string s how many hash equal to target hash
    {
      if(t == chv(i,i+n-1)) ans++;
    }
    cout<<ans<<endl;
  return 0;
}


//Tata Goodbye Khatam
