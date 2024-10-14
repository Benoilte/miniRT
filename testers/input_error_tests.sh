#!/bin/bash

EXPECTED_DIR=expected_output_files/

TESTS=(
    "no_input" ""
    "no_rights" scenes/no_rights.rt
    "no_camera" "scenes/no_camera.rt"
    "no_ambient" "scenes/no_ambient.rt"
    "no_light" "scenes/no_light.rt"
    "no_shape" "scenes/no_shape.rt"
)


RED="\033[0;31m"
GREEN="\033[0;32m"
RST="\033[0;0m"

OUTPUT_FILE="output.txt"
ERROR_FILE="err_output.txt"

STDOUT_DIFF="stdout.diff"
STDERR_DIFF="stderr.diff"

chmod -r scenes/no_rights.rt

for ((i = 0; i < ${#TESTS[@]}; i += 2)); do
    TESTNAME=$EXPECTED_DIR${TESTS[$i]}
    ARGS=${TESTS[$i + 1]}
    
    ../miniRT_bonus $ARGS 1> $OUTPUT_FILE 2> $ERROR_FILE

    echo "Testing: "${TESTS[$i]}

    echo -n "STDOUT: "
    if diff $OUTPUT_FILE "${TESTNAME}_stdout.txt" > $STDOUT_DIFF
    then
        echo -e "${GREEN}OK"
    else
        echo -e "${RED}KO" ; cat $STDOUT_DIFF
    fi
    echo -en "${RST}"

    echo -n "STDERR: "
    if diff $ERROR_FILE "${TESTNAME}_stderr.txt" > $STDERR_DIFF
    then
        echo -e "${GREEN}OK"
    else
        echo -e "${RED}KO" ; cat $STDERR_DIFF
    fi
    echo -en "${RST}"

    rm $OUTPUT_FILE $ERROR_FILE $STDERR_DIFF $STDOUT_DIFF
done

chmod +r scenes/no_rights.rt
