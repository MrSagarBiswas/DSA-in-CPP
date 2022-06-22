#include <bits/stdc++.h>
using namespace std;

void removeDuplicates(char s[]){
	if(s[0]=='\0'){
		return;
	}
	if(s[0]!=s[1]){
		return removeDuplicates(s+1);
	} else {
		for(int i=1; s[i]!='\0'; i++){
			s[i]=s[i+1];
		}
		return removeDuplicates(s);
	}
}

int main()
{
	char s[100]= "Hexy I'mx sagarx Biswas";
	cin>>s;
	removeDuplicates(s);
	cout<<s<<endl;
}