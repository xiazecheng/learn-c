#include<stdio.h>
int main(int argc,char *argv[]){
	// int a = 100;
	// int *p = &a;
	// printf("%p\n", p);
	// printf("%p\n", &a);
	// return 0;

	char *p[] = {"22","33","55"};
	char **s = p + 1;
	printf("%ld\n",sizeof(s));

	// char *t = {"12234"};
	// printf("%ld\n", sizeof(t));

	int d[] = {1,2,2,8,12,11};
	printf("%ld\n", sizeof(d));
}
