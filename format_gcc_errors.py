import subprocess
import json
from stringcolor import *
import textwrap
import re
import shutil
from pygments import highlight
from pygments.lexers import get_lexer_by_name
from pygments.formatters import Terminal256Formatter

from colors import *



compile_command = ['gcc', '-Wall', '-Wextra', '-Werror', '-fdiagnostics-format=json', 'test.c']
#compile_command = ['make', 'dev']


ERROR_COLOR     = BOLD_RED
FILE_PATH_COLOR = GREEN
LINE_NUM_COLOR  = B_MAX_YELLOW
MSG_ARROW_COLOR = MAX_YELLOW
MSG_COLOR       = CYAN
MSG_STR_COLOR   = PURPLE
CARET_COLOR     = BOLD_RED

err_num = 1
code_indent = '              '
msg_indent = '          '
term_size = shutil.get_terminal_size()
term_cols = term_size.columns

# run gcc
process = subprocess.Popen(compile_command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
stdout, stderr = process.communicate()
output = stdout + stderr

# proceed through output intil GCC json reached
i = output.find("[{")
j = output.rindex("}]")
msg_dict = json.loads(output[i:j+2])

# print errors
print ("")
print ("")
for msg in msg_dict:

    type_str = msg['kind']
    file_path = ''
    line_number = 0
    caret_cols_list = []
    caret_cols = 0
    caret_indent = ''
    for loc in msg['locations']:
        if 'caret' in loc:
            caret = loc['caret']
            file_path = caret.get('file')
            line_number = caret.get('line')
            caret_cols_list.append(caret.get('column'))

    # Error  :  <file path>  :  <line number>
    error = f" {ERROR_COLOR}Error {err_num}{RESET}  :  {FILE_PATH_COLOR}{file_path}{RESET}  :  {LINE_NUM_COLOR}{line_number}{RESET}"

    # message
    prompt = ">>> "
    msg_str = ''.join([c.upper() if i == 0 else c for i,c in enumerate(msg['message'])])
    msg_str = f"{MSG_ARROW_COLOR}{prompt}{MSG_COLOR}{msg_str}{RESET}"
    msg_str = textwrap.fill (msg_str, initial_indent=msg_indent, subsequent_indent= msg_indent + f"{'': <{len(prompt)}}", width=term_cols)
    msg_str = re.sub (r"‘([^‘]*)’", rf"‘{MSG_STR_COLOR}\1{RESET}{MSG_COLOR}’", msg_str)

    # line of code
    code_line = ''
    stripped_spaces = 0
    try:
        with open(file_path, 'r') as file:
            for current_line_number, line in enumerate(file, start=1):
                if current_line_number == line_number:
                    orig_code_line = line
                    code_line = orig_code_line.lstrip()
                    stripped_spaces = len(orig_code_line) - len(code_line)
                    code_line = highlight (code_line,
                                           lexer = get_lexer_by_name('c'),
                                           formatter = Terminal256Formatter (style = 'paraiso-dark'))
                    break
                else:
                    code_line = f"Unable to find line number {line_number} in \"{file_path}\""
    except FileNotFoundError:
        code_line = f"Unable to find \"{file_path}\""
    code_line = code_indent + code_line.rstrip('\n')


    # caret
    caret_cols = min(caret_cols_list)
    for _ in range(caret_cols - stripped_spaces - 2):
        caret_indent = ' ' + caret_indent
    if len(caret_indent) == 0:
        code_indent = code_indent[1:]
    caret = code_indent + caret_indent + f'{CARET_COLOR}⤴{RESET}'

    # print error message
    print (error)
    print (msg_str)
    print (code_line)
    print (caret)
    print ("")

    err_num += 1

print ("")
