#!/usr/bin/env bash

set -e
set -o pipefail

function print_header() {
    echo -e "\n***** ${1} *****"
}

print_header "RUN cppcheck"
if [ "${1}" == "--local" ]; then
	CPPCHECK="cppcheck"
else
	CPPCHECK="./linters/cppcheck/cppcheck"
fi
<<<<<<< HEAD
#${CPPCHECK} project --enable=all --error-exitcode=1 -I project/include --suppress=missingIncludeSystem  --check-config

print_header "RUN cpplint.py"
python2.7 ./linters/cpplint/cpplint.py --extensions=c HW_2/project/include/one/* HW_2/project/include/multi/* HW_2/project/src/one/* HW_2/project/src/multi/*

print_header "SUCCESS"
=======
${CPPCHECK} project --enable=all --error-exitcode=1 -I project/include --suppress=missingIncludeSystem  --check-config

print_header "RUN cpplint.py"
python2.7 ./linters/cpplint/cpplint.py --extensions=c project/include/* project/src/*

print_header "SUCCESS"
>>>>>>> developing_hw1
