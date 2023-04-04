#include <stdio.h>
int a[100][100],v[50][50],n,count=0;
void findpath(int m[][],int r,int c,int n){
    if(r==n-1 && c==n-1){
        v[r][c]=1;
        count++;
        printf("Solution %d \n ",count);

    }
}