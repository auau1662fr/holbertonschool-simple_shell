# Simple Shell

## Description
This project is a simple UNIX command line interpreter written in C.
It replicates basic functionalities of the `/bin/sh` shell.

The shell works in both **interactive** and **non-interactive** modes.
It supports command execution using the PATH environment variable and
implements basic built-in commands.

---

## Features
- Interactive mode with prompt `($)`
- Non-interactive mode (input from pipe or file)
- Execution of commands using `PATH`
- Built-in commands:
  - `exit`
  - `env`
- Handles `Ctrl + C` (SIGINT)
- Proper error handling (`command not found`)
- No memory leaks

---

## Usage

### Compilation
```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o hsh
