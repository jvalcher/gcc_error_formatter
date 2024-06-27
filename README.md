
# GCC error message formatter

Produces concise, easy-to-read GCC error messages<br>

<img src='image.png' height='250px'>


## Overview

- Uses the `-fdiagnostics-format=json` flag
- Works with Make et al. as long as the only `[{` JSON object `}]` in the output is GCC's


## Run demonstration

```
$ bash setup.sh
$ python format_gcc_output.py
```


