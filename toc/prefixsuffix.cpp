//wap to find prefixes, suffixes, substrings and subset of strings from a given string 

#include<iostream>
#include<string>
#include<set>
using namespace std;
int main(){
	
	string str;
	cout<<"Enter a string: ";
	getline(cin,str);
	int len = str.length();
	
	cout<<"Prefixes: ";
	for(int i=1;i<=len;++i)
		cout<<str.substr(0,i)<<" ";
		cout<<endl;
		
	cout<<"Suffixes: ";
	for(int i=0;i<=len;++i)
		cout<<str.substr(i)<<" ";
		cout<<endl;
	
	cout<<"Unique Substrings: ";
	set<string>unique_substrings;
	for(int i=0;i<len;++i){
		for(int j=i+1;j<=len;++j){
			string sub=str.substr(i,j-1);
			if(unique_substrings.insert(sub).second)
				cout<<sub<<" ";
		}
	}
cout<<endl;

return 0;
}
