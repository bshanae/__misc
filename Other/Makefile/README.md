# Makefile script for 42 School projects

Little python program for generating makefiles for C/C++ projects.

## Usage

You need command file. By default the script looks for file called
'configuration.txt'.
When you have this file, run and you will Makefile.

```
python script.py 
``` 

## Command file

By default command should be name 'configuration.txt' and be in the
same folder as script.
However, you can use custom file by using -in flag. <br>
Here are the commands you can use in the command file :
```compiler(compiler name)``` - default 'gcc' <br>
```project(project name)``` <br>
```executable(binary name)``` <br>
```add_flag((option) flag, ...)``` <br>
Option :  <br>
OBJECT - flag is used for compilation of every object. <br>
EXECUTABLE - flag is used when linking executable. <br>
COMMON - flags is used for every step, default. <br> 
```add_source(source file, ...)``` <br>
```include_directory(header path, ...)``` <br>
```link_directory(header path, ...)``` - adds path to header of a library<br>
```link_library(library path, ...)``` - adds path to a library itself <br>
 
### Example 

```
compiler(clang++)
project(example)
executable(example)

add_flag(COMMON std=c++17)

add_source(example/main.cpp)

include_directory(example)

link_directory(example/lib)
link_library(
    example
    '-framework OpenCL')
```
 
## Flags

```-in/-input [path]``` - changes command file <br>
```-out/-output [path]``` - changes target file <br>
```-info``` - reports about some stages of script's work <br>