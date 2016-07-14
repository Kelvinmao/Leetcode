#include<stdio.h>
#include<string.h>

char* reverseString(char* s) {
    int sl=strlen(s);
    char r[sl+1];
    int i;
    for(i=0;i<sl;i++){
        r[sl-i-1]=*(s+i);
    }
    r[i]='\0';
    strcpy(s,r);
    return s;
}

int main(void){
	char s[10]={'h','e','l','l','o'};
	int i=0;
	for(i=0;i<10;i++){
		printf("%c",s[i]);
	}
	printf("\n");
	printf("%s",reverseString(s));
}
