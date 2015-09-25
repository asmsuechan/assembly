#include<stdio.h>
//permutation
int main(void){
	int n,r,result;
	printf("input n:");
	scanf("%d",&n);
	printf("input r:");
	scanf("%d",&r);

  __asm__ volatile(
        "       movl    %1,%%eax        ;"
        "       movl    %1,%%ebx        ;"
        "       movl    %2,%%ecx        ;"
        "L2:    decl    %%ebx           ;"
        "       mull    %%ebx           ;"
        "       decl    %%ecx           ;"
        "       cmpl    $1,%%ecx        ;"
        "       ja      L2              ;"
        "       movl    %%eax,%0        ;"
	"	movl	%%eax,%0	;"
	:"=r"(result)
	:"r"(n),"r"(r));

  printf("%d P %d = %d\n",n,r,result);
  return 0;
}
