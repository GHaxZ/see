#!/bin/bash

mkdir -p ./build/ || exit

gcc ./src/main.c ./src/search.c ./src/util.c ./src/browser.c ./src/argparse.c -o ./build/main || exit

./build/main "$@"  || exit
