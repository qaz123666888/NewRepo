    #include <stdio.h>
    int recursion(int i){
        if(1==i) {
            return 1;
        }
        if(i==2){
            return 2;
        }else {
            return recursion(i-2)+recursion(i-1);
        }
    }
    int main() {
        int n;
        scanf("%d",&n);
        printf("%d",recursion(n));
        return 0;
    }
