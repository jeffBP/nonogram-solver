#!/bin/bash

NONOGRAM_TEST_FILE="./build/src/test/nonogram_test"

if [[ -f "$NONOGRAM_TEST_FILE" ]]; then
    ./build/src/test/nonogram_test
fi
