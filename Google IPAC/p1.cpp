#include <iostream>

using namespace std;

int main()
{
    while(1){
   int n;
   cin>>n;
   if(n<=1)
   {
       cout<<"You cannot generate christmas tree";
       return 0;
   }

   if(n>20)
   {
       cout<<"Tree is no more";
       return 0;
   }
   int count=1;
   for(int i=0;i<=n;i++)
   {
       for(int j=n-i;j>0;j--)
            cout<<" ";
        for(int j=0;j<count;j++)
            cout<<"*";
        cout<<endl;
        count+=2;
   }
   int temp=n-1;
   for(int k=n-2;k>1;k--)
   {
       int count1=3;
       int count2=n-1;
        for(int i=0;i<=k;i++)
        {
           for(int j=0;j<count2;j++)
                cout<<" ";
            for(int j=0;j<count1;j++)
                cout<<"*";
            cout<<endl;
            count1+=2;
            count2-=1;
         }
   }
   count=3;

   for(int i=0;i<=n-3;i++)
   {
       for(int j=n-i;j>1;j--)
            cout<<" ";
        for(int j=0;j<count;j++)
            cout<<"*";
        cout<<endl;
        count+=2;
   }




   for(int i=0;i<n;i++)
    cout<<" ";
    cout<<"*"<<endl;
    for(int i=0;i<n;i++)
    cout<<" ";
    cout<<"*"<<endl;

    }
   return 0;
}
