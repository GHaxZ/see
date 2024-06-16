#!/bin/bash

gcc ./src/main.c ./src/search.c ./src/util.c ./src/browser.c -o ./build/main

./build/main
