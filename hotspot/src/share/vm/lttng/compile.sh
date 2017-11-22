gcc -I. -fpic -c lttng_tp.c 
gcc -shared -o libtpp.so lttng_tp.o -llttng-ust -ldl

