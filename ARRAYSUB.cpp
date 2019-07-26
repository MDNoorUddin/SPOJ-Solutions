#include<bits/stdc++.h>
#define ll long long
#define ps() cout <<" ";
using namespace std;
int tree[400001];
int a[100001];

void build(int k,int s,int e)
{
    if(s==e)
    {
        tree[k]=a[s];
        return;
    }
    int mid=(s+e)/2;
    build(2*k,s,mid);
    build(2*k+1,mid+1,e);
    tree[k]=max(tree[2*k],tree[2*k+1]);
}

void update(int k,int s,int e,int id,int val)
{
    if(s==e&&s==id)
    {
        a[s]=val;
        tree[k]=a[s];
        return;
    }
    int mid=(s+e)/2;
    if(id<=mid)
    {
        update(2*k,s,mid,id,val);
    }
    else
    {
        update(2*k+1,mid+1,e,id,val);
    }
    tree[k]=max(tree[2*k],tree[2*k+1]);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int k;
    cin>>k;
    build(1,1,k);
    cout<<tree[1];
    for(int i=1,j=k+1;j<=n;i++,j++)
    {
        if(i>k)i=1;
        update(1,1,k,i,a[j]);
        ps();cout<<tree[1];
    }
}
