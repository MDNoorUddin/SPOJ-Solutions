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
vector<string> g(2001);
vector<string> G(2001);

int mn=0;
int n,m;
int II,JJ;
void dfs(int I,int J,int dis)
{
    if(dis>mn)
    {
        mn=dis;
        II=I;
        JJ=J;
    }
    g[I][J]='#';
    if(I+1<n&&g[I+1][J]=='.')
    {
        //g[I+1][J]='#';
        dfs(I+1,J,dis+1);
    }
    if(I-1>=0&&g[I-1][J]=='.')
    {
        //g[I-1][J]='#';
        dfs(I-1,J,dis+1);
    }
    if(J+1<m&&g[I][J+1]=='.')
    {
        //g[I][J+1]='#';
        dfs(I,J+1,dis+1);
    }
    if(J-1>=0&&g[I][J-1]=='.')
    {
        //g[I+1][J]='#';
        dfs(I,J-1,dis+1);
    }
}
int main() {

  //ios::sync_with_stdio(false);
  //cin.tie(0);
  int t,x,y;
  sf(t);
  in(l,t)
  {
      sf(n);sf(m);
      swap(n,m);
      bool x=false;
      int I,J;
      for(int i=0;i<n;i++)
      {
          sf(g[i]);
          G[i]=g[i];
          if(x)continue;
          for(int j=0;j<g[i].length();j++)
          {
              if(g[i][j]=='.')
              {
                  I=i;
                  J=j;
                  x=true;
                  break;
              }
          }
      }
      dfs(I,J,0);
      //cout<<mn;ps();cout<<II;ps();pf(JJ);
      g=G;
      mn=0;
      dfs(II,JJ,0);
      //cout<<mn;ps();cout<<II;ps();pf(JJ);
      cout<<"Maximum rope length is ";cout<<mn<<".\n";
      mn=0;
  }
}
