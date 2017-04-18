#include<stdio.h>

int main(int argc, char *argv[]){
	char *name = "test";
	int t[] = {1,2,1,0};
	int *s = t;
	(*s)++;
	printf("tttt %d\n",s[0]);
	printf("tttt----%ld\n", s-t);
	printf("*name-----%x\n",&t);
	return 0;
}

