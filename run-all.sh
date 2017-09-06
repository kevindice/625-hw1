#!/bin/bash
#$ -t 1:200
uname -a

for i in `python -c "import random; y=range(0,27); print(' '.join(list(map(lambda x: str(2 ** x), random.sample(y, len(y))))))"`
do
    for v in `python -c "import random; versions=['block2', 'block4', 'block8', 'compiler_optimized', 'default', 'o_fast', 'unroll16', 'unroll8']; print(' '.join(random.sample(versions, len(versions))))"`
    do

    /homes/kmdice/625-hw2/pt0_$v $i

    done
done
