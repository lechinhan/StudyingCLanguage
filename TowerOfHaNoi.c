#include <stdio.h>

void Move (int n, char start, char middle, char end){
    if (n==1)
    {
        printf("%c -> %c\n",start,end);
        return ;
    }
    Move(n-1,start,end,middle);
    Move(1,start,middle,end);
    Move(n-1,middle,start,end);
}
int main   (){
    Move(5,'A','B','C');
    return 0;
}