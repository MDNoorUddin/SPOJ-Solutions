#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <iostream>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

#define pf(n) cout << n << endl
#define ps() cout <<" ";
#define sf(n) cin >> n
#define in(i,n) for (int i = 0; i < n; i++)
#define vi vector<int>
#define vp vector<pair<int, int>>
#define graph vector< vector<int> >
#define vs vector<string>
/**  '' "\n" ^ **/


typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    new_data_set;

vi a(1000001);
vi b(1000001);
vector<int> ans;
void sieve()
{
    for(int i=2;i<=1000000;i++)
    {
        if(b[i])continue;
        ans.push_back(i);
        for(int j=i*2;j<=1000000;j+=i)
        {
            b[j]=1;
        }
    }
    //for(int i=0;i<100;i++)cout<<ans[i]<<endl;
}

void factorization(int n)
{
    int sum=1;
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i]*ans[i]>n)break;
        int count=0;
        while(n%ans[i]==0)
        {
            count++;
            n/=ans[i];
        }
        if(count)
        {
            sum*=(count+1);
        }
    }
    if(n>1)
        sum*=2;
    cout<<sum<<endl;
}

vector<vi> g(2001);
vector<int> c(2001);

void cl()
{
    for(int i=0;i<=2000;i++)
      {
          c[i]=0;
          g[i].clear();
      }
}
bool bisex=false;
void dfs(int k)
{
    for(auto e:g[k])
    {
            if(c[e]==c[k])
            {
                bisex=true;
                return;
            }
            if(c[e]==0)
            {
                if(c[k]==1)c[e]=2;
                else
                c[e]=1;
                dfs(e);
            }
    }
    return;
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);
  int t,x,y;
  sf(t);
  in(I,t)
  {
      cl();
      int n,m;
      sf(n);sf(m);
      while(m--)
      {
          sf(x);sf(y);
          g[x].push_back(y);
          g[y].push_back(x);
      }
      for(int i=1;i<=n;i++)
      {
          if(!c[i])
          {
              c[i]=1;
              dfs(i);
          }
          if(bisex)
          {
              break;
          }
      }
      cout<<"Scenario #"<<I+1<<":\n";
      if(bisex)
      pf("Suspicious bugs found!");
      else
        pf("No suspicious bugs found!");

      /*for(int i=1;i<=n;i++)
      {
          cout<<i;ps();pf(c[i]);
      }*/
      bisex=false;
  }
}
