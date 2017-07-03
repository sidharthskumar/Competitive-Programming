#include <bits/stdc++.h>



using namespace std;


int main()
{
   int t;
   cin>>t;
    while(t--)
    {
         int a[13] = {0};
         int flag = 0;
         for(int i = 1; i <= 12 ;i++){
             char x;
             cin>>x;
             if(x == 'X'){ a[i] = 1; flag = 1;}
         }
         vector <int> ans;
         int b[5] = {2,3,4,6,12};
         if(flag) ans.push_back(1);
         for(int k=0; k<5;k++){
             for(int i=1 ; i<= 12; i++)
             {
                if(a[i])
                {
                     int c = 0;
                     int ind = i;
                     while(ind <= 12 && a[ind]) {
                         c++;
                         ind += 12/b[k];
                     }       
                     if(c == b[k]){
                         ans.push_back(b[k]);
                         break;
                     }
                }
             }
            
         }
         cout<<ans.size()<<" ";
         for(auto i : ans)cout<<i<<"x"<<12/i<<" ";
         cout<<endl;
         
    }



}
