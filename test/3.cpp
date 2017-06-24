#include <bits/stdc++.h>
using namespace std;
int main(){
	int q;
	cin>>q;
	typedef vector<bool> ind;
	map<string,ind> m;
	for(int bl=0;bl<q;bl++){
		string s;
		cin>>s;
		if(s=="crt"){
			string s1;
			cin>>s1;
			map<string,ind>::iterator it=m.find(s1);
			if(it==m.end()){
				ind myvector;
				myvector.push_back(1);
				 m.insert(make_pair(s1,myvector));
				cout<<"+ "<<s1<<endl;
			}
			else{
				ind::iterator j;
				for(j=m[s1].begin();j!=m[s1].end();j++){
					if(*j==0) break;
				}
				if(j==m[s1].end()) m[s1].push_back(1);
				int indexi=j-m[s1].begin();
				m[s1][indexi]=1;
				if(indexi!=0) cout<<"+ "<<s1<<"("<<indexi<<")"<<endl;
				else  cout<<"+ "<<s1<<endl;
			}
		}
		else if(s=="del"){
			string s1,s3;
			cin>>s1;
			s3=s1;
			int x=0;
			if(s1[s1.length()-1]==')'){
				int i;
				int temp=1;
				 for( i=0;s1[s1.length()-i-2]!='(';i++){
					x=x+(s1[s1.length()-2-i]-48)*temp;
//					cout<<x<<endl;
					if(s1[s1.length()-i-3]!='(') temp=temp*10;
				}
				i=s1.length()-1;
				while(s1[i]!='('){
					i--;
				}
			 s3=s1.substr(0,i);
			}
			m[s3][x]=0;
			cout<<"- "<<s1<<endl;
		}
		else if(s=="rnm"){
				string s1;
				string s3;
				string newp;
				cin>>s1;
				cin>>newp;
				s3=s1;
				cout<<"r ";
				int x=0;
				if(s1[s1.length()-1]==')'){
					int i;
					int temp=1;
					 for( i=0;s1[s1.length()-i-2]!='(';i++){
						x=x+(s1[s1.length()-2-i]-48)*temp;
	//					cout<<x<<endl;
						if(s1[s1.length()-i-3]!='(') temp=temp*10;
					}
					i=s1.length()-1;
					while(s1[i]!='('){
						i--;
					}
				 s3=s1.substr(0,i);
				}
				m[s3][x]=0;
				cout<<s1<<" -> ";
				map<string,ind>::iterator it=m.find(newp);
				if(it==m.end()){
					ind myvector;
					myvector.push_back(1);
					 m.insert(make_pair(newp,myvector));
					cout<<newp<<endl;
				}
				else{

					ind::iterator j;
					for(j=m[newp].begin();j!=m[newp].end();j++){
						if(*j==0) break;
					}
					if(j==m[newp].end()) m[newp].push_back(1);
					int indexi=j-m[newp].begin();
					m[newp][indexi]=1;
					if(indexi!=0) cout<<newp<<"("<<indexi<<")"<<endl;
					else  cout<<newp<<endl;
				}

		}

	}
}


