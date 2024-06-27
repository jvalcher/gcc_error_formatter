#!/bin/bash


printf "\nInstalling requirements... "
python -m venv venv
source ./venv/bin/activate
pip install -r requirements.txt > /dev/null 2>&1
printf "done\n\n"

python format_gcc_errors.py

printf "\nCleaning up... "
rm -r ./venv > /dev/null 2>&1
rm -r __pycache__ > /dev/null 2>&1
printf "done\n\n"

deactivate

