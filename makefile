all: mytime pt0_default pt0_unroll8 pt0_unroll16

mytime: mytime.c
	cc mytime.c -o mytime

pt0_default: pt0_default.c
	cc pt0_default.c -o pt0_default

pt0_unroll8: pt0_unroll8.c
	cc pt0_unroll8.c -o pt0_unroll8

pt0_unroll16: pt0_unroll16.c
	cc pt0_unroll16.c -o pt0_unroll16
