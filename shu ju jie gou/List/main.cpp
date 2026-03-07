#include<stdio.h>
#define maxsize 10
#include<stdbool.h>
typedef char Elem_type;
typedef struct{
    char data[maxsize];
    int top;
}stack;
void init_stack(stack *S){
    S->top=-1;
}
bool stack_empty(stack s){
    if(s.top==-1){
        return true;}
        else{
            return false;
        }
    }
bool push(stack *s,Elem_type x){
    if(s->top==maxsize-1){
        return false;
    }
    s->top++;
    s->data[s->top]=x;
    return true;
}
bool pop(stack *s,Elem_type *x){
    if(s->top==-1)
    {
        return false;
    }
    *x=s->data[s->top];
    s->top--;
    return true;
}
bool check(char str[],int length){
    stack s;
    init_stack(&s);
    stack_empty(s);
    for(int i=0;i<length;i++){
        if(str[i]=='(' || str[i]=='[' || str[i]=='{') {
            push(&s,str[i]);
        }
        else{
            if(stack_empty(s)) {
                return false;
            }
            char topelem;
            pop(&s,&topelem);
            if((str[i]==')' && topelem!='(') || (str[i]==']' && topelem!='[') || (str[i]=='}' && topelem!='{'))
            {
                return false;
            }
        }
    }
    return stack_empty(s);
}
int main(){
    char str[10];
    char Str;
    int length=0,i=0;
    while(i<maxsize && scanf("%c",&Str) && Str!=' '){
        str[i]=Str;
        i++;
        length++;
    }
    if(check(str,length)){
        printf("yes");
    }
    else{
        printf("no");
    }
    return 0;
}