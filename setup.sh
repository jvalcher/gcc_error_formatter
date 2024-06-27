#!/bin/bash

# deactivate virutual environment with:  $ deactivate

printf "\nInstalling requirements... "

python -m venv venv
source ./venv/bin/activate

pip install -r requirements.txt > /dev/null 2>&1

printf "done\n\n"

