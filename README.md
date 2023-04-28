![My_simple_shell (1)](https://user-images.githubusercontent.com/63271720/235030205-9105a2ca-b207-4649-8814-6db68cb435b4.png)


My_simple_shell is a UNIX command interpreter that replicates the main functionality of the sh shell. This project was developed as part of the first cycle curriculum at Holberton School.

## Requirements

- Linux or Unix-based operating system
- C programming language
- Compilation made on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- Standard C libraries

## Flowchart



![diagram2](https://user-images.githubusercontent.com/63271720/235029597-0dd0d8d1-3076-499f-98c4-c0c90ce615ac.JPG)

[code2flow_RUhP4s.pdf](https://github.com/HaroldS10/holbertonschool-simple_shell/files/11348948/code2flow_RUhP4s.pdf)

## Usage

Proper use of the simple shell consists of compiling all the files in the repository. After this executing the resulting file. From now on this file will be called hsh. Simple Shell has the ability to execute any executable file, which can be called in interactive mode, or in non-interactive mode. Next an example.

### Example
In interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
In non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## Description

### Syntaxis
```
($)[program name] [options]
```
When `simple_shel` is run, command line are written as any other line interpreter. Hsh will attempt to execute the program name (searching into the PATH environment variable) with the arguments specified by [options]. There's a limit of 100 characters per line, including the new line character. All the tabs characters (\t) that are found in the line are removed and are not considered in the code.
### Files
Files implemented for the operation of the simple_shell are.
|File| Description |
|--|--|
|`execute.c`| |
|`src_path.c`|groups the needed functions to initialize and run the command interpreter|
|`parse_line.c`|groups the functions that transforms a line into an array of strings used by the execve function|
|`main.c`| main function for hsh|
|`get_env.c`| main function for hsh|
|`execute.c`| |

## Authors
* Harold Suarez <[HaroldS10](https://github.com/HaroldS10/holbertonschool-simple_shell)> 
* Julian Garcia <[Julibeto84](https://github.com/Julibeto84/holbertonschool-simple_shell)>


