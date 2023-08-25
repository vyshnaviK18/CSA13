#include<stdio.h>
#include<string.h>
#define m 100
int main(){
	char a[m];
	int i=0,n=0,j=0;
	printf("enter=");
	scanf("%s",a);
	for(i=0;a[i]!='\0';i++){
		n++;
	}
	printf("\nlength =%d",n);
	if(a[j]=='a' && a[n-1]=='a'){
		printf("\nstring accepted");
	}
	else
		printf("\nrejected");
	return 0;
}
