#!/bin/bash

EXE=./scalar_converter

tests=(
    # === basic ints ===
    "0"
    "1"
    "-1"
    "42"
    "-42"

    # === edge ints ===
    "2147483647"       # INT_MAX
    "-2147483648"      # INT_MIN
    "2147483648"       # overflow
    "-2147483649"      # underflow
    "999999999999999"  # way too big

    # === floats ===
    "0.0f"
    "1.0f"
    "-1.0f"
    "42.42f"
    "-42.42f"
    "123456.789f"
    "1e10f"            # scientific notation (if you support)
    "1e-10f"

    # === doubles ===
    "0.0"
    "1.0"
    "-1.0"
    "42.42"
    "-42.42"
    "123456.789"
    "1e10"
    "1e-10"

    # === chars ===
    "a"
    "z"
    "0"
    "9"
    "~"

    # === pseudo-literals ===
    "nan"
    "nanf"
    "+inf"
    "-inf"
    "+inff"
    "-inff"

    # === invalid junk ===
    "--1"
    "++1"
    "1.1ff"
    "1.1.1"
    "abc"
    "42ff"
    "'a'"
    "   123   "
    "  1.1.  "
    ""
    "   "
)

for t in "${tests[@]}"; do
    echo ">>> Test: \"$t\""
    $EXE "$t"
    echo "-------------------------------------"
done
