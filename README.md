
# GCC error message formatter

Produces concise, easy-to-read GCC error messages<br>

<img src='output.png' height='250px'>


## Overview

- Uses the `-fdiagnostics-format=json` flag
- Works with Make et al. as long as the only `[{` JSON object `}]` in the output is GCC's
- Personalize the colors at the top of `format_gcc_output.py`:
  - Change the individual elements' colors with the values in `colors.py`
  - Change the code line's Pygments `style`



## Run tests

- Bash:
```
$ ./setup_venv
$ ./run_tests
```


## Get unformatted errors

- Bash:
```
$ ./get_unformatted_errors
```
