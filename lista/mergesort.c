#include <stdio.h>
#include <stdlib.h>
int *divide(int *arr,int begin,int end){
    int i;end++;
    int *temp = (int*)calloc(end-begin,sizeof(int));
    for(i=0;i<end-begin;i++){
        temp[i]=arr[begin+i]; 
    }
    return temp;
}
int *merge(int *left,int *right,int l,int r){
    int s=r+l;l--;r--;
    int *sorted=(int*)calloc(s,sizeof(int));
    while(s>0){
        if(l<0||r<0){
            sorted[--s]=(l>=0)?left[l--]:right[r--];
        }else{
            sorted[--s]=(left[l]>right[r])?left[l--]:right[r--];
        }
    }
    return sorted;
}
int *mergesort(int *array,int p,int r){
    if(p==r){
        return array;
    }else{
        int q=r/2;
        int *left=divide(array,p,q);
        int *right=divide(array,q+1,r);
        left=mergesort(left,p,q);
        right=mergesort(right,p,q);
        return merge(left,right,q+1,r-q);
    }
}

int main(){
    int n=8;
    int nums[]={14,3,7,12,9,11,6,2};
    int *sorted = mergesort(nums,0,n-1); 
    printf("finally\n{");
    int i;
    for(i=0;i<n;i++)
        printf("%d,",sorted[i]);
    printf("}\n");
    return 0;
}
