
# GCC error formatter

<img src='formatted_output.png' height='350px'>


## Overview

- Uses the `-fdiagnostics-format=json` flag
- Works with Make et al. as long as the only `[{` JSON objects `}]` in the output are GCC's


## Usage

```python
from format_gcc_output import format_gcc_output

command = 'g++ -Wall -Wextra -fdiagnostics-format=json test2.cpp'

format_gcc_output (command)
```


## Color configuration

Personalize the colors at the top of `format_gcc_output.py` with the values in `colors.py`.<br>


## Development

```bash
$ ./run_tests
```

```bash
$ ./get_unformatted_errors
```
