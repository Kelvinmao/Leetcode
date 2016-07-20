typedef struct stack{
    char * data;
    int top;
}stack;

void initStack(stack *S,int maxSize){
    S->data=(char *)malloc(maxSize*sizeof(char));
    S->top=-1;
}

void push(stack *S,char ch){
    S->top++;
    S->data[S->top]=ch;
}

void pop(stack *S){
    S->top--;
}

bool isValid(char* s) {
    if(!s||strlen(s)==1)
        return false;
    int index=0;
    stack S;
    initStack(&S,strlen(s)); 
    int i=0;
    for(i=0;i<strlen(s);i++){
        if(s[i]==')'&&S.data[S.top]=='('||s[i]==']'&&S.data[S.top]=='['||s[i]=='}'&&S.data[S.top]=='{')/*³öÕ»Ìõ¼þ*/
            pop(&S);
        else
            push(&S,s[i]);
    }
    if(S.top==-1)
        return true;
    else
        return false;
}
