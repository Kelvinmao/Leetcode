#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int isVowel(char c){
	return 
	c == 'a' || c == 'A' ||
    c == 'e' || c == 'E' ||
    c == 'i' || c == 'I' ||
    c == 'o' || c == 'O' ||
    c == 'u' || c == 'U';
}

void charswp(char *a,char *b){
	char tmp=*a;
	*a=*b;
	*b=tmp;
}

char* reverseVowels(char* s) {
	if(strlen(s)<2)
		return s;
	else{
		int len=strlen(s);
		int itfwd=0,itbwd=len-1;
		while(itfwd<itbwd){
			if(isVowel(s[itfwd])&&isVowel(s[itbwd])){
				charswp(&s[itfwd],&s[itbwd]);
				++itfwd;
				--itbwd;
			} 
			while(!isVowel(s[itfwd])&&itfwd<=len-1)
				itfwd++;
			while(!isVowel(s[itfwd])&&itbwd>=0)
				itbwd--;
		}
	}
	return s;
}

int main(void){
	printf("%s","leetcode\n");
	char s[9]={'l','e','e','t','c','o','d','e'};
	printf("%s",reverseVowels(s));
}
