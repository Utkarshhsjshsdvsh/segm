#include <bits/stdc++.h>
using namespace std;
void build(int ind,int lo,int hi,vector<int>&arr,vector<int>&seg,int orr)
{
    if(hi==lo){
        seg[ind]=arr[lo];
        return;
    }
    int mid=(hi+lo)/2;
    build(2*ind+1,lo,mid,arr,seg,!orr);
    build(2*ind+2,mid+1,hi,arr,seg,!orr);
    if(orr)
    seg[ind]=seg[2*ind+1]|seg[2*ind+2];
    else
    seg[ind]=seg[2*ind+1]^seg[2*ind+2];
}
void update(int ind,int lo,int hi,int i,int val,vector<int>&seg,int orr)
{
    if(lo==hi)
    {
        seg[ind]=val;
        return;
    }
    int mid=(hi+lo)/2;
    if(i<=mid)
    update(2*ind+1,lo,mid,i,val,seg,!orr);
    else
    update(2*ind+2,mid+1,hi,i,val,seg,!orr);
    if(orr)
    seg[ind]=seg[2*ind+1]|seg[2*ind+2];
    else
    seg[ind]=seg[2*ind+1]^seg[2*ind+2];
}
void solve()
{
    int n,q;
    cin>>n>>q;
    int el=pow(2,n);
    vector<int>arr(el);
    vector<int>seg(4*el);
    for(int i=0;i<el;i++)
    cin>>arr[i];
    if(n%2==0)
    build(0,0,el-1,arr,seg,0);
    else
    build(0,0,el-1,arr,seg,1);
    for(int i=0;i<q;i++)
    {
        int p,val;
        cin>>p>>val;
        p--;
        if(n%2==0)
        {
            update(0,0,el-1,p,val,seg,0);
            arr[p]=val;
        }
        else
        {
            update(0,0,el-1,p,val,seg,1);
            arr[p]=val;
        }
        cout<<seg[0]<<endl;
    }
}
int main() {
	solve();
	return 0;
}