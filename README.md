
# GCC error message formatter

Produces concise, easy-to-read GCC error messages<br>

<img src='output.png' height='250px'>


## Overview

- Uses the `-fdiagnostics-format=json` flag
- Works with Make et al. as long as the only `[{` JSON object `}]` in the output is GCC's

### Color configuration

Personalize the colors at the top of `format_gcc_output.py` with the values in `colors.py`.<br>
<br>
Code line syntax formatting via Pygments is disabled by default, as it can make things look a bit cluttered. Enable it by setting the `lexer` variable from `'none'` to a Pygments lexer short name as shown in `./run_tests`. You can then change the `style` variable at the top of `format_gcc_output.py`.<br>



## Development

### Run tests
```
$ ./setup_venv
$ ./run_tests
```


### Get unformatted errors
```
$ ./get_unformatted_errors
```
