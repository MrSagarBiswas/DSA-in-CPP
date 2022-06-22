#include <bits/stdc++.h>
using namespace std;

int length(char s[]){
	if(s[0]=='\0')
		return 0;
	return 1+length(s+1);
}

void removeX(char s[]){
	if(s[0]=='\0')
		return;
	if(s[0]!='x'){
		removeX(s+1);
	} else {
		for(int i=0; s[i]!='\0'; i++){
			s[i]=s[i+1];
		}
		return removeX(s);
	}
}

int main()
{
	char s[100]= "Hexy I'mx sagarx Biswas";
	cin>>s;
	cout<<s<<endl;
	cout<<length(s)<<endl;
	removeX(s);
	cout<<s<<endl;
	cout<<length(s)<<endl;
}