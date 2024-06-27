
# GCC error message formatter

Produces concise, easy-to-read GCC error messages<br>

<img src='image.png' height='250px'>


## Overview

- Uses the `-fdiagnostics-format=json` flag
- Works with Make et al. as long as the only `[{` JSON object `}]` in the output is GCC's
- Personalize the colors in `format_gcc_output.py`:
  - Change the code line Pygments `style`
  - Change the other elements' colors individually with the values in `colors.py`


## Run tests

- Bash:
```
$ ./setup_venv
$ ./run_tests
```


## Get unformatted errors

- Bash:
```
$ ./get_unformatted_erros
```
