/*2.	Write a C program to simulate a Deterministic Finite 
Automata (DFA) for the given language 
representing strings that start with 0 and end with 1
*/
#include<stdio.h>
#include<string.h>
int main()
{
	int i;
	char a[100];
	printf("enter the string:");
	scanf("%s",&a);
		if(a[0]=='0'&&a[strlen(a)-1]=='1')
		printf("accepted");
		else
		printf("not accepted");
	return 0;
}
