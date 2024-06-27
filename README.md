
# GCC error formatting

Enjoy easy-to-read GCC error messages<br>

<img src='output.png' height='250px'>


## Overview

- Uses the `-fdiagnostics-format=json` flag
- Works with Make et al. as long as the only `[{` JSON object `}]` in the output is GCC's


## Usage

```python
from format_gcc_output import format_gcc_output

command = ['g++', '-Wall', '-Wextra', '-fdiagnostics-format=json', 'test2.cpp']

format_gcc_output (command)
```


## Color configuration

Personalize the colors at the top of `format_gcc_output.py` with the values in `colors.py`.<br>


## Development

### Run tests
```bash
$ ./setup_venv
$ ./run_tests
```


### Get unformatted errors
```bash
$ ./get_unformatted_errors
```
