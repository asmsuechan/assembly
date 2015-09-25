#include<stdio.h>
int main(void){
  int n,s;
  printf("put a number:");
  scanf("%d",&n);
  
  __asm__ volatile(
	"	movl	%1,%%eax	;"
	"	movl	%1,%%ebx	;"
	"L:	decl	%%ebx		;"
	"	addl	%%ebx,%%eax	;"
	"	cmpl	$0,%%ebx	;"
	"	ja	L				;"
	"	movl	%%eax,%0	;"
	:"=r"(s)
	:"r"(n));

  printf("sum = %d\n",s);
  /* e.x.
   * put a number:5
   * sum = 5 + 4 + 3 + 2 + 1 =15
   */
  return 0;
}
