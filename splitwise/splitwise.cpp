#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int t; // no. of transaction
    cin>>t;
    
     map<string,int> net;  // find net  
    
    while(t--){
    	string x,y; // persons name
    	int amount;	
    	cin>>x>>y>>amount;
    	//  cout<<x<<y<<amount;
        
        if(net.count(x)==0){   //initailize map to 0
            net[x]=0;
        }
        if(net.count(y)==0){
            net[y]=0;
        }
        
      	net[x]-=amount; 
        net[y]+=amount; 
      
        
    }
    
    multiset<pair<int,string>> m; 	
    
    for(auto it :net ){
        string person = it.first;
        int n=it.second;
        if(n!=0){
            m.insert(make_pair(n,person));
        }
        
        
        
    }
    
    int count=0;
    while(!m.empty()){
        
        auto l = m.begin();
        auto r = prev(m.end());
        int lowvalue = l->first;
        string lowperson = l->second;
        int highvalue = r->first;
        string highperson = r->second;
        m.erase(l);
        m.erase(r);
        
        
        int settle=min(-lowvalue,highvalue);
        cout<<lowperson<< " gives " << settle << " to" << highperson<<endl;
        lowvalue+=settle;
        highvalue-=settle;
        if(lowvalue!=0){
            m.insert(make_pair(lowvalue,lowperson));
        }
        if(highvalue!=0){
            m.insert(make_pair(highvalue,highperson));
        }
        count++;
        
        
        
        
    }
    
    cout<<count<<endl;
   
    
    
    
    
    
}