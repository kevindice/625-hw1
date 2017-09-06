all: mytime pt0_default pt0_unroll8 pt0_unroll16 pt0_block2 pt0_block4 pt0_block8 pt0_compiler_optimized pt0_o_fast

mytime: mytime.c
	cc mytime.c -o mytime

pt0_default: pt0_default.c
	cc pt0_default.c -o pt0_default

pt0_compiler_optimized: pt0_compiler_optimized.c
	cc -O3 pt0_compiler_optimized.c -o pt0_compiler_optimized

pt0_o_fast: pt0_o_fast.c
	cc -Ofast pt0_o_fast.c -o pt0_o_fast

pt0_unroll8: pt0_unroll8.c
	cc pt0_unroll8.c -o pt0_unroll8

pt0_unroll16: pt0_unroll16.c
	cc pt0_unroll16.c -o pt0_unroll16

pt0_block2: pt0_block2.c
	cc pt0_block2.c -o pt0_block2

pt0_block4: pt0_block4.c
	cc pt0_block4.c -o pt0_block4

pt0_block8: pt0_block8.c
	cc pt0_block8.c -o pt0_block8

