import sys

def error_message(msg='unknown error', code_error=84):
    '''
    Write an error message on stderr and exit the program with code 84
    :param msg: message we will display on our stderr
    :param code_error: code error we will use to exit
    '''
    sys.stderr.write(msg + '\n')
    sys.exit(code_error)
