# ALX SIMPLE SHELL

> This is an alx team project, aimed to make us understand the importance of team work, how to effectively use branching, pull request, merging and properly handle conflicts.

## Description
Our project **hsh**, is a simple implementation of the bash shell, which is a command-line interface that allows users to execute commands and run scripts by typing them in at a command prompt.

## Tools used
The c programming language
Betty linter: checks code structure and proper formatting
valgrind: Checks for unfreed memory space

### Compilation
All files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
**Eg:**`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

> In case you were wondering why everything was implemented from scratch, here are the list of allowed functions

### List of allowed functions and system calls
* access (man 2 access)
* chdir (man 2 chdir)
* close (man 2 close)
* closedir (man 3 closedir)
* execve (man 2 execve)
* exit (man 3 exit)
* _exit (man 2 _exit)
* fflush (man 3 fflush)
* fork (man 2 fork)
* free (man 3 free)
* getcwd (man 3 getcwd)
* getline (man 3 getline)
* getpid (man 2 getpid)
* isatty (man 3 isatty)
* kill (man 2 kill)
* malloc (man 3 malloc)
* open (man 2 open)
* opendir (man 3 opendir)
* perror (man 3 perror)
* read (man 2 read)
* readdir (man 3 readdir)
* signal (man 2 signal)
* stat (__xstat) (man 2 stat)
* lstat (__lxstat) (man 2 lstat)
* fstat (__fxstat) (man 2 fstat)
* strtok (man 3 strtok)
* wait (man 2 wait)
* waitpid (man 2 waitpid)
* wait3 (man 2 wait3)
* wait4 (man 2 wait4)
* write (man 2 write)

### Usage
- ./hsh (interactive mode)
- echo "echo 'awesome'" | ./hsh (non-interactive mode)
- ./hsh file (the file contains all commands to be executed. each command must appear on a seperate line.)

## All our shell can do and how to use
> prompts user with ($) and ready to take commands

### 1. Handles command with arguments
> whether it is the full file path or just file name

```
($) ls
AUTHORS      env1.c        getline1.c      main.c        string1.c
boolean.c    env.c         getline.c       README.md     ...
($) /bin/ls 
AUTHORS      env1.c        getline1.c      main.c        string1.c
boolean.c    env.c         getline.c       README.md     ...
($) ls -l
total 136
-rw-r--r-- 1 root root   187 Apr 26 19:54 AUTHORS
-rw-r--r-- 1 root root  2198 Apr 26 21:01 boolean.c
-rw-r--r-- 1 root root  2868 Apr 26 21:01 builtins1.c ...
($) echo "Alx is awesome"
"Alx is awesome"
```

### 2. Handles the builtins
> cd, exit, alias

```
root@98598560789c:~/simple_shell# ./hsh
($) pwd
/root/simple_shell
($) cd /
($) pwd
/
($) cd -
/root/simple_shell
($) pwd
/root/simple_shell
($) alias l=ls
($) alias c=clear
($) alias
l='ls'
c='clear'
($) exit
root@98598560789c:~/simple_shell#
```

### 3. Handles the Environment variables
> env prints the whole environment, setenv and unsetenv set and unset variables respectively. (...) means the ouput was cut short

```
($) env
HOSTNAME=98598560789c
LANGUAGE=en_US:en
PWD=/root/simple_shell
TZ=America/Los_Angeles
HOME=/root ...
($) setenv  school book
($) setenv hardwork success
($) env
...
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
OLDPWD=/
_=./hsh
school=book
hardwork=success
($) unsetenv school
($) unsetenv hardwork
($) env
...
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
OLDPWD=/
_=./hsh
```

### 4. Handle the commands separator ';'
> This is called command chaining, you can pass as many commands you want in one line must seperated by a semi colon.

```
($) ls; echo alx; exit 0 
AUTHORS      env1.c        getline1.c      main.c        string1.c
boolean.c    env.c         getline.c       README.md     .......
($) alx
($) root@98598560789c:~/simple_shell#
```

### 5. Handle the && and || shell logical operators
> The '&&' executes the second command only if the first executes successfully and '||' executes the second command only when the first fails(it can only execute one
```
($) ls && echo alx && exit
AUTHORS      env1.c        getline1.c      main.c        string1.c
boolean.c    env.c         getline.c       README.md	 ........
($) alx
($) root@98598560789c:~/simple_shell# ./hsh
($) ls || echo alx
AUTHORS      env1.c        getline1.c      main.c        string1.c
boolean.c    env.c         getline.c       README.md     ........
($)gg || echo alx
./hsh: 2: gg: not found
($) alx
```

### 6. Handle variables replacement (`$?` and `$$`)
> `$?` contains the exit status of the last comand and `$$` gets the pid of the current process

```
($) echo $?
0
($) echo $$
11891
($) echo $$
11891
```

### 7. Expands the alias builtin
> user defined alias are being expanded to thier equialent commands
```
($) alias l=ls
($) l
AUTHORS      env1.c        getline1.c      main.c        string1.c
boolean.c    env.c         getline.c       README.md     ......
($)
```

### 8. Handle comments (#)
> any word, characters or even commands preceeded by '#' are been ignored
```
($) echo "C is fun" # echo "python is awesome"
"C is fun"
($)
```

### 9. ./hsh [filename]
> executes a comands in a file passed as arguments to the shell
```
root@98598560789c:~/simple_shell# cat file
ls
echo "hard man"
root@98598560789c:~/simple_shell# ./hsh file
AUTHORS      env1.c        getline1.c      main.c        string1.c
boolean.c    env.c         getline.c       README.md     ........
"hard man"
root@98598560789c:~/simple_shell#
```

### 10. Handle the errors
> we were told to handle the errors just the way it would have been hadled in sh shell

```
root@98598560789c:~/simple_shell# ./hsh
($) l
./hsh: 1: l: not found
($) ech alx
./hsh: 2: ech: not found
($) exit
root@98598560789c:~/simple_shell# ./hsh file
./hsh: 0: Can't open file
root@98598560789c:~/simple_shell#
```

### 11. Handle SIGINT(signal interrupt or Ctrl+c)
> code can only exit with `exit` command, with or without status and `Ctrl+d (EOF). Any input of Ctrl+c will be ignored

```
root@98598560789c:~/simple_shell# ./hsh
($) ^C
($) ^C
($)`Ctrl+d` 
root@98598560789c:~/simple_shell# ./hsh
($) ^C
($) ^C
($) exit
root@98598560789c:~/simple_shell#
```

# AUTHORS

* Ekekwe Chinonso <ekekwecharles50@gmail.com>
* Opeyemi Sarah <sarahopeyemi@yahoo.com>
