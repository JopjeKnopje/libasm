# TODO
- Setup debugger

# Subject
## Common instructions
- Your Makefile must at least contain the rules `$(NAME)`, `all`, `clean`, `fclean` and
`re`. It must recompile/relink only the necessary files.
- You must write **64-bit** assembly, beware of the "calling convention".
- You **can’t do** inline ASM, you must do ’*s’ files.
- You must compile your assembly code with nasm.
- You must use the **Intel syntax**, not the AT&T syntax.
- It is forbidden to use the compilation flag: `-no-pie`.

## Mandatory part

- The library must be called `libasm.a`.
- You must submit a main function that will test your functions and compile with
your library to demonstrate that it is functional.
### Functions
- You must rewrite the following functions in assembly:
	- ft_strlen (man 3 strlen)
	- ft_strepy (man 3 strepy)
	- ft_stremp (man 3 strcmp)
	- ft write (man 2 write)
	- ft_read (man 2 read)
	- ft_strdup (man 3 strdup, you can call to malloc)
- You must check for errors during syscalls and handle them properly when needed.
- Your code must set the variable errno properly. For that, you are allowed to call the extern `___error` or `errno_location`.


# Commands
List the symbols in the lib
```bash
nm lib/libasm.so
```

# Dev setup
## Tool chain
### clang-format
[clang-format](https://clang.llvm.org/docs/ClangFormat.html) is part of clang-tools, install with.
```bash
apt install clang-tools
```
### prek
This will install [prek](https://github.com/j178/prek?tab=readme-ov-file#installation) into `~/.local/bin`
```bash
curl --proto '=https' --tlsv1.2 -LsSf https://github.com/j178/prek/releases/download/v0.2.27/prek-installer.sh | sh
```
### nasm
Not installed by default on my pop-os.
```
apt install nasm
```

## Dependencies
- [criterion](https://github.com/Snaipe/Criterion?tab=readme-ov-file#packages) for unit tests.


# 🤓 Knowledge


## Makefile automatic variables
[gnu.org](https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html#Automatic-Variables)[stackoverflow](https://stackoverflow.com/a/3220288)
```makefile
all: library.cpp main.cpp
```
- `$@` evaluates to all
- `$<` evaluates to library.cpp
- `$^` evaluates to library.cpp main.cpp


## Architecture
### x86-64
[wiki](https://en.wikipedia.org/wiki/X86-64)
x86-64 is a 64-bit extension of the x86 instruction set.


# Sources
- [Intel vs AT&T ASM](https://stackoverflow.com/a/8550917)
- [UNIX Syscalls table]()
