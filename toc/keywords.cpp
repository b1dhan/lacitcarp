#include<string>
#include<unordered_set>
#include<iostream>
using namespace std;
int main(){
	string str;
	cout<<"Enter a string: ";
	cin>>str;
	
	if(!isalpha(str[0]) && str[0]!='_'){
		cout<<"Invalid identifier"<<endl;
		return 0;
	}

unordered_set<string> keywords={"auto", "break", "case", "char", "const", "continue", "default", 
								"do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
if(keywords.count(str)){
	cout<<"Keyword"<<endl;
}
else{
	cout<<"Valid identifier"<<endl;
}
return 0;
}

