# TODO
- Setup debugger
- Project structure


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


# Questions?   
## Why does our ASM procedure need to start with an `_` for C to recognize it?
Read this on it: https://stackoverflow.com/a/1035937


## Makefile automatic variables
[gnu.org](https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html#Automatic-Variables)[stackoverflow](https://stackoverflow.com/a/3220288)
```makefile
all: library.cpp main.cpp
```
- $@ evaluates to all
- $< evaluates to library.cpp
- $^ evaluates to library.cpp main.cpp


## Architecture
### x86

### x64



# Sources
- [Intel vs AT&T ASM](https://stackoverflow.com/a/8550917)
- [UNIX Syscalls table]()
