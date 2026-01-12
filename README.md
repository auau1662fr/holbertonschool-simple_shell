Simple Shell
Description

Simple Shell is a minimal UNIX command-line interpreter written in C.
It reproduces the core behavior of the standard /bin/sh shell, allowing users
to execute commands in both interactive and non-interactive modes.

This project focuses on understanding process creation, system calls,
environment variables, and command execution in a UNIX environment.

Features

Interactive mode with custom prompt ($)

Non-interactive mode (input via pipe or file)

Command execution using the PATH environment variable

Built-in commands:

exit — exits the shell

env — displays environment variables

Proper handling of Ctrl + C (SIGINT)

Error handling for invalid commands

Memory-safe (no memory leaks)

Compliant with Betty coding style

Usage
Compilation
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o hsh

interactive Mode
./hsh
($) ls
($) pwd
($) exit

Non-Interactive Mode
echo "ls -l" | ./hsh
cat file.txt | ./hsh


🛠️ Project Structure
├── main.c        # Program entry point and main loop
├── parse.c       # Command parsing and tokenization
├── exec.c        # Process creation and command execution
├── path.c        # PATH handling and command lookup
├── builtins.c    # Built-in commands implementation
├── signals.c     # Signal handling (Ctrl + C)
├── hsh.h         # Header file
├── man_1_simple_shell
└── README.md


System Calls Used

fork

execve

wait

getline

access

signal
