#!/bin/bash
uname -a

for i in `python -c "import random; y=range(0,27); print(' '.join(list(map(lambda x: str(2 ** x), random.sample(y, len(y))))))"`
do
    ~/625/pt0 $i
done
