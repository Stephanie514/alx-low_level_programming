#!/bin/bash
rm gm
echo '#include <stdio.h>\nint main() {\n    printf("--> Please make me win!\\n");\n    return 0;\n}' > gm.c gcc -o gm gm.c
