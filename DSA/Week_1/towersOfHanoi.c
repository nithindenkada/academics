#include<stdio.h>
void tower_of_hanoi(int n, char s_poll, char d_poll, char i_poll){
if(n == 1)
    printf("Move disk %d from %c to %c\n", n, s_poll, d_poll);
else{
    tower_of_hanoi(n - 1, s_poll, i_poll, d_poll);
    printf("Move disk %d from %c to %c\n", n, s_poll, d_poll);
    tower_of_hanoi(n - 1, i_poll, d_poll, s_poll);
}
}
int main(){

int n = 0;
printf("Enter no of disks: ");
scanf("%d", &n);
tower_of_hanoi(n, 'S', 'I', 'D');
return 0;
}