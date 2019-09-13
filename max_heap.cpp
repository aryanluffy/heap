#include <bits/stdc++.h>
#define lli long long int
#define pb push_back
#define mod 1000000007
#pragma GCC optimize ("-O2")
#define mod2 998244353
#define MAXN 1000000000
#define v32 vector<int>
#define v64 vector<lli>
#define v1024 vector <vector <int>>
#define v4096 vector <vector <lli>>
#define vt vector
#define f(x, y, z) for (lli x = y; x < z; x++)
#define fd(x, y, z) for (lli x = y; x > z; x--)
#define lb lower_bound
#define ld long double
#define m64 map<lli,lli>
#define m32 map<int,int>
#define m64it map<lli,lli>::iterator
#define m32it map<int,int>::iterator
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ist insert
#define endl "\n"
#include <ext/pb_ds/assoc_container.hpp>
#define p_q priority_queue 
#define min_p_q priority_queue <int,vt <int>,greater <int>>
using namespace std;
using namespace __gnu_pbds; 
class heap
{
public:
  v32 arr;
  int MAX(){
    return arr[0];
  }
  void heapify(int id){
    if(2*id+1>=arr.size())return;
    else if(2*id+1==arr.size()-1){
      if(arr[id]<arr[2*id+1])swap(arr[id],arr[2*id+1]);
      return;
    }
    if(arr[id]<max(arr[2*id+2],arr[2*id+1]))
    {
      if(max(arr[2*id+1],arr[2*id+2])==arr[2*id+1])
         {
           swap(arr[id],arr[2*id+1]);
           if(2*id+1<arr.size())
           heapify(2*id+1);
         }
      else{
        swap(arr[id],arr[2*id+2]);
           if(2*id+2<arr.size())
           heapify(2*id+2);
      }   
    }
    else return;
  }
  void pop(){
    if(arr.size()==0)return;
    swap(arr[0],arr[arr.size()-1]);
    arr.pop_back();
    heapify(0);
  }
  void insert(int key){
       arr.pb(key);
       int x=arr.size()-1;
       while(x!=0){
         int p=(x-1)/2;
         if(arr[p]<arr[x]){
           swap(arr[p],arr[x]);
           x=p;
         } else break;
       }
  }
};


int main() 
{  
  int n;cin>>n;
  heap HEAP;
  while(n--){
    int q;cin>>q;
    if(q==1){
      HEAP.pop();
    }
    else if(q==2){
      cout<<HEAP.MAX()<<"\n";
    }
    else {
      int x;cin>>x;
      HEAP.insert(x);
    }
  }
  return 0; 	
}
