#include <bits/stdc++.h>



using namespace std;




int main()
{
    string s1,s2;
    int ind = 0;
    cin>>s1>>s2;
    for(int i = 0; i < s1.length();i++) {
        if(s1[i]=='+') ind++;
        else ind--;
    }
    double uc = 0;
    for(int i=0;i < s2.length();i++){
        if(s2[i]=='+')ind--;
        else if(s2[i]=='-')ind++;
        else uc += 1;
    }
    if(abs(ind) <= uc && ((int)(uc - ind))%2==0)
    {
        double p1 =1 , p2 = 1, pn = 1;
        double c = 1;
        double targ = (uc - ind)/2;
        while(c <= uc)
        {
            if(c<= targ) p1 *= c;
            if(c <= uc - targ) p2 *= c;
            pn *= c;
            c++;
        }
        cout<<fixed<<setprecision(12)<<(pn/(p1*p2))/pow(2,uc);
    } 
    else
    {
        cout<<0<<endl;
    }
    
    


    return 0;
}
