#include<stdio.h>
//calc_decimal
int main(void){
  double x,y,z;
  printf("put a number(decimal) x:");
  scanf("%lf",&x);
  printf("put a number(decimal) y:");
  scanf("%lf",&y);

  __asm__ volatile(
	"	fldl	%1	;"
	"	fldl	%2	;"
	"	fmul	%%st,%%st(0)	;"
	"	fstpl	%0	;"
	:"=m"(z)
	:"m"(x),"m"(y));

  /* e.x.
   * x:0.785
   * y:0.785
   * z = 0.616225
   */
  printf("%f * %f = %f\n",x,y,z);
  return 0;
}
