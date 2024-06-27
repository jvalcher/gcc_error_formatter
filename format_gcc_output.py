import subprocess
import sys
import json
from stringcolor import *
import textwrap
import re
import shutil
from pygments import highlight
from pygments.lexers import get_lexer_by_name
from pygments.formatters import Terminal256Formatter

from colors import *



def format_gcc_output (command):
    
    FILE_PATH_COLOR   = B_MAX_GREEN
    LINE_NUM_COLOR    = B_MAX_YELLOW
    MSG_PROMPT_COLOR  = B_MAX_BLUE
    MSG_COLOR         = CYAN
    MSG_STR_COLOR     = PURPLE
    CODE_PROMPT_COLOR = B_MAX_YELLOW
    CARET_COLOR       = BOLD_RED

    code_indent = '           '
    msg_indent  = '           '
    term_size = shutil.get_terminal_size()
    term_cols = term_size.columns

    # run gcc
    process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    stdout, stderr = process.communicate()
    output = stdout + stderr
    process.kill()

    # proceed through output intil GCC json reached
    i = output.find("[{")
    if i == -1:
        print ("No error messages found")
        sys.exit(1)
    j = output.rindex("}]")
    msg_dict = json.loads(output[i:j+2])

    #print (json.dumps (msg_dict, indent=4))

    print ("")
    print ("")

    # print errors
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
        type_str = ''.join([c.upper() if i == 0 else c for i,c in enumerate(type_str)])
        err_buff = ''
        if type_str == 'Error':
            ERROR_COLOR = B_MAX_RED
            err_buff = '  '
        elif type_str == 'Warning':
            ERROR_COLOR = B_MAX_YELLOW
            err_buff = ''
        else:
            ERROR_COLOR = B_MAX_BLUE
        error = f" {ERROR_COLOR}{type_str}{RESET}: {err_buff}{FILE_PATH_COLOR}{file_path}{RESET}  :  {LINE_NUM_COLOR}{line_number}{RESET}"

        # message
        prompt = ">>>  "
        msg_str = ''.join([c.upper() if i == 0 else c for i,c in enumerate(msg['message'])])
        msg_str = f"{MSG_PROMPT_COLOR}{prompt}{MSG_COLOR}{msg_str}{RESET}"
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
        code_line = code_indent + f"{CODE_PROMPT_COLOR}{prompt}{RESET}" + code_line.rstrip('\n')


        # caret
        caret_cols = min(caret_cols_list)
        for _ in range(caret_cols - stripped_spaces - 2):
            caret_indent = ' ' + caret_indent
        if len(caret_indent) == 0:
            code_indent = code_indent[1:]
        caret = code_indent + caret_indent + f'{"": <{len(prompt)}}' + f'{CARET_COLOR}⤴{RESET}'

        # print error message
        print (error)
        print (msg_str)
        print (code_line)
        print (caret)
        print ("")

    print ("")


if __name__ == '__main__':

    # C
    c_command = ['gcc', '-Wall', '-Wextra', '-fdiagnostics-format=json', '-o', 'test1', 'test1.c']
    format_gcc_output (c_command)

    # C++
    cpp_command = ['g++', '-Wall', '-Wextra', '-fdiagnostics-format=json', '-o', 'test2', 'test2.cpp']
    format_gcc_output (cpp_command)


