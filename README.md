<img src="https://imgur.com/Ulbbb4m.png" width=400 height=400/>

## Simple Shell

This repository contains all the necessary files to run a Simple Shell with some of the most used commands (ls, pwd, echo, cat).This shell interface was created from the C programming language, it gives the user a prompt "Holy_Shell>"; when entering a command accepted by the shell, it will be executed in a child process.

## This Shell has the following characteristics:

* This program automatically displays a prompt for the user to enter a command to be executed.
* The command line will always end on a new line when the user presses ENTER.
* when a command finishes executing, the prompt will appear again on a new line.
* when the user types the exit command, the program will exit and display the original LINUX prompt again.
* the program will stop when the user types CTRL + D (end of file).
* This shell handles the command line as arguments or as paths.
* The user will not exit this shell by typing ^C (CTRL + C).
* If the user types the env command, it will print the current work environment.
* if the shell does not find any commands within the given path, it will print an error message.
* This shell does not support wildcards, pipes, or logical operators ( * , | , && , || ).

## known bugs:

* when the user types an argument that the shell does not accept as a command and then types the command exit, the shell will not effectively exit on the first try.

## Flowchart:

<img src="https://imgur.com/uooUqjF.png"/>

## Requirements:

### General.

* Allowed editors: `vi`, `vim`, `emacs`
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options `-Wall` `-Werror` `-Wextra` `-pedantic` `-std=gnu89`
* All your files should end with a new line
* A `README.md` file, at the root of the folder of the project is mandatory
* Your code should use the `Betty` style. It will be checked using betty-style.pl and betty-doc.pl
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded.

## Examples:

* ls

```shell
Holy_Shell> ls
README.md  aux_funct.c  hsh  ps_getenv.c  shell.c  shell.h  tokenizer.c
```
