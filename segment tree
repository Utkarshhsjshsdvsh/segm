class st{
    public:
    vector<int>seg;
    st(int n)
    {
        seg.resize(4*n,0);
    }
    void build(int ind,int lo,int hi)
    {
        if(hi==lo){
            seg[ind]=0;
            return;
        }
        int mid=(hi+lo)/2;
        build(2*ind+1,lo,mid);
        build(2*ind+2,mid+1,hi);
        seg[ind]=0;
    }
    void update(int ind,int lo,int hi,int i)
    {
        if(lo==hi)
        {
            seg[ind]=seg[ind]+1;
            return;
        }
        int mid=(hi+lo)/2;
        if(i<=mid)
        update(2*ind+1,lo,mid,i);
        else
        update(2*ind+2,mid+1,hi,i);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
    int query(int ind,int lo,int hi,int l,int r)
    {
        if(hi<l || r<lo)
        return 0;
        if(lo>=l && hi<=r)
        return seg[ind];
        int mid=(hi+lo)/2;
        int left=query(2*ind+1,lo,mid,l,r);
        int right=query(2*ind+2,mid+1,hi,l,r);
        return left+right; 
    }
};
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
#include <bits/stdc++.h>
using namespace std;
class info{
    public:
    int full;
    int open;
    int close;
    info()
    {
        full=0;
        open=0;
        close=0;
    }
};
void merge(info seg1,info seg2,info &seg3)
{
    info ans;
    ans.full=seg1.full+seg2.full+min(seg1.open,seg2.close);
    ans.open=seg1.open+seg2.open-min(seg1.open,seg2.close);
    ans.close=seg1.close+seg2.close-min(seg1.open,seg2.close);
    seg3 = ans;
}
void build(int ind,int lo,int hi,string &s,info seg[])
{
    if(hi==lo){
        if(s[lo]=='(')
        seg[ind].open++;
        else
        seg[ind].close++;
        return ;
    }
    int mid=(hi+lo)/2;
    build(2*ind+1,lo,mid,s,seg);
    build(2*ind+2,mid+1,hi,s,seg);
    info m;
    merge(seg[2*ind+1],seg[2*ind+2],m);
    seg[ind]=m;
}
info query(int ind,int lo,int hi,int l,int r,info seg[])
{
    if(hi<l || r<lo)
    {
        info m;
        return m;
    }
    if(hi<=r && lo>=l)
    return seg[ind];
    int mid=(hi+lo)/2;
    info left=query(2*ind+1,lo,mid,l,r,seg);
    info right=query(2*ind+2,mid+1,hi,l,r,seg);
    info m;
    merge(left,right,m);
    return m;
}
/*void update(int ind,int lo,int hi,int i,int val,vector<int>&seg,int orr)
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
}*/
void solve()
{
    string s;
    cin>>s;
    int n;
    cin>>n;
    info seg[s.size()*4];
    build(0,0,s.size()-1,s,seg);
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        cout<<query(0,0,s.size()-1,l,r,seg).full*2<<endl;
    }
}
##hack with infy range queries
#include <bits/stdc++.h>
using namespace std;
class st{
    public:
    vector<vector<int>>seg;
    st(int n)
    {
        seg.resize(4*n,vector<int>(21,0));
    }
    void build(int ind,int lo,int hi,vector<int>&arr)
    {
        if(hi==lo){
            seg[ind][arr[lo]]++;
            return;
        }
        int mid=(hi+lo)/2;
        build(2*ind+1,lo,mid,arr);
        build(2*ind+2,mid+1,hi,arr);
        for(int i=1;i<=20;i++)
        seg[ind][i]=seg[2*ind+1][i]+seg[2*ind+2][i];
    }
    void update(int ind,int lo,int hi,int i,int val,bool inc)
    {
        if(lo==hi)
        {
            if(inc==0)
            seg[ind][val]=0;
            else
            seg[ind][val]++;
            return;
        }
        int mid=(hi+lo)/2;
        if(i<=mid)
        update(2*ind+1,lo,mid,i,val,inc);
        else
        update(2*ind+2,mid+1,hi,i,val,inc);
        seg[ind][val]=seg[2*ind+1][val]+seg[2*ind+2][val];
    }
    int query(int ind,int lo,int hi,int l,int r,int val)
    {
        if(hi<l || r<lo)
        return 0;
        if(lo>=l && hi<=r)
        return seg[ind][val];
        int mid=(hi+lo)/2;
        int left=query(2*ind+1,lo,mid,l,r,val);
        int right=query(2*ind+2,mid+1,hi,l,r,val);
        return left+right; 
    }
};
int main() {
    st s(n);
    int ans=0;
    int mod=1e9+7;
    s.build(0,0,n-1,arr);
    for(int i=0;i<q;i++)
    {
        int type=queries[i][0];
        int l=queries[i][1];
        int r=queries[i][2];
        if(type==1)
        {
            l--;
            r--;
            int maxi=0;
            for(int j=1;j<=20;j++)
            maxi=max(maxi,s.query(0,0,n-1,l,r,j));
            if((r-l+1)%2==0 && maxi<(r-l+1)/2+1)
            ans=(ans%mod+(r-l+1)%mod)%mod;
        }
        else
        {   
            l--;
            r--;
            s.update(0,0,n-1,l,arr[l],0);
            s.update(0,0,n-1,l,arr[r],1);
        }
    }
    return ans;
}
int main() {
	solve();
	return 0;
}

