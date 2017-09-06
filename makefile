all: mytime pt0

mytime: mytime.c
	cc mytime.c -o mytime

pt0: pt0.c
	cc pt0.c -o pt0
