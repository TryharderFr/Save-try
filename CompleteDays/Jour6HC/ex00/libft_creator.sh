gcc -c *.c
ar rc libstr.a *.o
rm *.o
ranlib libstr.a
