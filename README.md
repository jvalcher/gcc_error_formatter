
# GCC error message parser

Produces easy-to-read GCC error messages<br>

<img src='example_output.png' height='250px'>


## Overview

- Uses GCC's `-fdiagnostics-format=json` flag
- Works with GCC and Make as long as the only `[{` JSON object `}]` in the output is GCC's


## Run demonstration

```
bash run_test.sh
```

