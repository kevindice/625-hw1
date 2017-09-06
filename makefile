all: mytime pt0_default pt0_unroll

mytime: mytime.c
	cc mytime.c -o mytime

pt0_default: pt0_default.c
	cc pt0_default.c -o pt0_default

pt0_unroll: pt0_unroll.c
	cc pt0_unroll.c -o pt0_unroll
