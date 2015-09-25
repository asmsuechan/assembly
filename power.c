#include<stdio.h>
//power
int main(void){
  int m,n,pow;
  printf("put a number(base) m:");
  scanf("%d",&m);
  printf("put a number(exponent) n:");
  scanf("%d",&n);

  __asm__ volatile(
	"	movl	%1,%%eax	;"
	"	movl	%1,%%ebx	;"
	"	movl	%2,%%ecx	;"
	"L:	mull	%%ebx		;"
	"	decl	%%ecx		;"
	"	cmpl	$1,%%ecx	;"
	"	ja	L				;"
	"	movl	%%eax,%0	;"
	:"=a"(pow)
	:"r"(m),"c"(n));

  /* e.x.
   * m = 5, n = 2
   * pow = 25
   */
  printf("%d ^ %d = %d\n",m,n,pow);
  return 0;
}
