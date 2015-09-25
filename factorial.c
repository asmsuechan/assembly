#include<stdio.h>

int main(void){
  int n,fac;
  printf("put a number n:");
  scanf("%d",&n);

  __asm__ volatile(
	"	movl	%1,%%ebx	;"
	"	movl	$1,%%eax	;"
	"L:	mull	%%ebx		;"
	"	decl	%%ebx		;"
	"	cmpl	$1,%%ebx	;"
	"	ja	L		;"
	"E:	movl	%%eax,%0	;"
	:"=a"(fac)
	:"b"(n)
	:);

  printf("%d! = %d\n",n,fac);
  return 0;
}
