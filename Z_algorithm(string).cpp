#include <bits/stdc++.h>
using namespace std;
vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main() {
  string a,b;
  cin>>a>>b;
  int sz = b.size();
  b += '#';
  b += a;
  auto vec = z_function(b);
  int ans = 0;
  for(auto it : vec)
  {
    if(it == sz) ans++;
  }
  cout<<ans<<endl;
      
}
