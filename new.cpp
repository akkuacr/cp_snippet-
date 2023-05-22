  #include<bits/stdc++.h>
  
  #define int long long int
  #define F first
  #define S second
  #define pb push_back
  #define que_max priority_queue<int>
  #define que_min priority_queue<int,vector<int>,greater<int>>;
  #define endl "\n"

 using namespace std;


   
  
  int mod=1000000007;
  int N=100005;
  int fact[100005];



//***********************mod multiplicative function***************//





  int mulm(int a,int b)
  {
    return ((a%mod)*(b%mod))%mod;
  }


// ***************************power function***********************//





  int powr(int x,int y)
  {
    int res=1;
    while(y)
    {   if(y&1){
        res=mulm(res,x);}
        y/=2;
        x=mulm(x,x);
    }
    return res;
  }


  // *****************inverse function**************************//

  int inv(int x)
  {
    return powr(x,mod-2);
  }


 //*********************     factorial calculation function ***********************//


  void calcfact()
  {
    fact[0]=1;
    for(int i=1;i<N;i++)
    {
        fact[i]=mulm(fact[i-1],i);
    }
  }


  //**************************ncr calculator**********************************//

  int ncr(int n,int r)
  {
     return mulm(mulm(fact[n],inv(fact[r])),inv(fact[n-r]));
  }










   
  





// ****************************seive function  and lp and hp**************************************//////////////////////





  vector<int>sieve(N,1),hp(N,1),lp(N,1);
     vector<int>prime; 
  void primesieve()
  {
      hp[0]=hp[1]=lp[1]=lp[0]=sieve[0]=sieve[1]=0;
  
      for(int i=2;i<N;i++)
      {
          if(sieve[i]==1)
          { hp[i]=i;lp[i]=i;
              for(int j=i*i;j<N;j+=i)
              {
                  sieve[j]=0;
                  hp[j]=i;
                  if(lp[j]==1)
                  {
                      lp[j]=i;
                  }
              }
          }
      }
  
  
  }
  
  // ***********************function that return prime factorization*************************////////////////////////////////////
  
  
  vector<int> primefac(int n)
  {
       vector<int>ans;
      ans.push_back(1);
  
      while((n!=1)&&(sieve[n]!=1))
      {
             ans.push_back(lp[n]);
              n/=lp[n];
      }
      if(n>1)ans.push_back(n);
       

       
     

      return ans;
  
      
  }






// *****************************************lowwer bound and upper bound with binary search code*********************************//



int upper(vector<int>&nums,int target)
{
    int s=0,e=nums.size()-1;
    int ans=-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(nums[mid]==target)
        {
            ans=max(ans,mid);
            s=mid+1;
        }else
        if(nums[mid]>target)
        {
            e=mid-1;
        }else
        {
            s=mid+1;
        }
    }

  return ans;
}







int lower(vector<int>&nums,int target)
{
    int s=0,e=nums.size()-1;
    int ans=INT_MAX;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(nums[mid]==target)
        {
            ans=min(ans,mid);
            e=mid-1;
        }else
        if(nums[mid]>target)
        {
            e=mid-1;
        }else
        {
            s=mid+1;
        }
    }

  return ans;
}




int binary_search(vector<int>vec,int x)
{

    int s=0,e=vec.size()-1;

    while(s<=e)
    {
        int mid=(s+e)/2;
        if(vec[mid]==x)
        {
            return mid;
        }else if(vec[mid]<x)
        {
            s=mid+1;
        }else
        {
            e=mid-1;
        }

    }
  

  return -1; 


}

















  // ******************************************************************write your code here*************************************************************//////////////////////



   void solve()
   {
   


   

     
       



    return ;
   }






  
  
   
  
   int32_t main()
   {
   #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
   #endif
   
   
    primesieve();
 
  
 
    for(int i=0;i<N;i++)
    {
        if(sieve[i])
        {
         prime.push_back(i);
        }
    }
 
 
    calcfact();



 
 
 
  
    int32_t t;
  
   cin>>t;
   while(t--)
   {

     solve();
       
   }
  
  
  
  
       return 0;
   }
   
















 














  

 
















 



