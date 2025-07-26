#include <bits/stdc++.h>
using namespace std;
vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    // for(auto it : s) cout<<it<<" ";
    // cout<<endl;
    vector<int> p(n + 2);
    int l = 0, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = min(r - i, p[l + (r - i)]);
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}
vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res)+1, end(res)-1 );
}

int main() {
      string a;
      cin>>a;
      auto p=manacher(a);
    //   for(auto it : p) cout<<it<<" ";
    //   cout<<endl;
      int mxl = -1; /// maximum length;
      int tc = 0; /// total char before the mxl;
      for(auto it : p)
      {
        mxl = max(mxl,it-1);
      }
    //   cout<<mxl<<endl;
      string ans = "";
      for(int i = 0;i<p.size();i++)
      {
        if(i % 2 == 0) tc++;
        if(p[i]-1 == mxl) break;
      }
      //cout<<tc<<" "<<mxl<<endl;
      int ind = tc - 1;
      for(int i = ind-(mxl/2)+(mxl%2==0);ans.size()<mxl;i++) ans += a[i];
      /// maximum length(mxl) even hole 1 add korte hobe.tokhon # value thakbe tai
      cout<<ans<<endl;
}
