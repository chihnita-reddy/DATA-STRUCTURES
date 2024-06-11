#include<stdio.h>
#include<string.h>
int main()
{
	char s[5]="ABC";
	strcat(s+1,"ABC");
	printf("%d",s[0]-s[1]);
	return 0;
}
