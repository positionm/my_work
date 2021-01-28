#include <stdio.h>
 
#define DEFARG(name, defval) ((#name[0]) ? (name + 0) : defval)
 
int _f1(int i)
{
    return 2*i;
}
#define f1(arg0) _f1(DEFARG(arg0, 0))
 
int _f2(int i, int j)
{
    return i + j;
}
#define f2(arg0, arg1) _f2(DEFARG(arg0, 0), DEFARG(arg1, 1))
 
int main()
{
    printf("%d\n", f1());
    printf("%d\n", f1(1));
 
    printf("%d\n", f2(,));
    printf("%d\n", f2(2,));
    printf("%d\n", f2(, 3));
    printf("%d\n", f2(4, 5));
    return 0;
}

tt1;
tt2;
