#include<stdio.h>
void TOH(int n,int A,int B,int C) //here n->no. of discs, A-> tower 1, B-> tower 2, C-> tower 3  (B is the using disc)
{
    if (n>0)
    {
        TOH(n-1,A,C,B);
        printf("Move a disc from %d to %d \n",A,C);
        TOH(n-1,B,A,C);
    }
}
int main()
{
    TOH(3,1,2,3);  //moving three discs, and the towers are named as 1,2 and 3
}