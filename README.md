

<h1 align="center">libasm</h1>
<p align="center">re-writing basic C-functions in Intel x86-64 Assembly</p>

<hr />

</p>

## Overview
I've mainly used this project to dive deeper into unit-testing, since these isolated functions are perfect for that.
This is a pretty dense README file, since it contains the Codam subject. And some my notes of my freshly aquired knowledge while learning about assembly and the ELF format.

## Cloning

HTTPS
```bash
git clone --recurse-submodules https://github.com/JopjeKnopje/libasm.git
```
SSH
```bash
git clone --recurse-submodules git@github.com:JopjeKnopje/libasm.git
```




## TODO
- When running tests init submodule.
- Setup debugger.
- https://gcc.gnu.org/onlinedocs/gcc/Gcov.html
- https://www.throwtheswitch.org/unity.
- asm-lsp thinks we're doing `GAS` instead of `nasm`.
- Read about ELF format and sections.

## 📋 Subject
### Common instructions
- Your Makefile must at least contain the rules `$(NAME)`, `all`, `clean`, `fclean` and
`re`. It must recompile/relink only the necessary files.
- You must write **64-bit** assembly, beware of the "calling convention".
- You **can’t do** inline ASM, you must do ’*s’ files.
- You must compile your assembly code with nasm.
- You must use the **Intel syntax**, not the AT&T syntax.
- It is forbidden to use the compilation flag: `-no-pie`.

### Mandatory part

- The library must be called `libasm.a`.
- You must submit a main function that will test your functions and compile with
your library to demonstrate that it is functional.
#### Functions
- You must rewrite the following functions in assembly:
	- ft_strlen (man 3 strlen)
	- ft_strepy (man 3 strepy)
	- ft_stremp (man 3 strcmp)
	- ft write (man 2 write)
	- ft_read (man 2 read)
	- ft_strdup (man 3 strdup, you can call to malloc)
- You must check for errors during syscalls and handle them properly when needed.
- Your code must set the variable errno properly. For that, you are allowed to call the extern `___error` or `errno_location`.



## 🏗️ Dev setup
### Toolchain
#### clang-format
[clang-format](https://clang.llvm.org/docs/ClangFormat.html) is part of clang-tools, install with.
```bash
apt install clang-tools
```
#### prek
This will install [prek](https://github.com/j178/prek?tab=readme-ov-file#installation) into `~/.local/bin`
```bash
curl --proto '=https' --tlsv1.2 -LsSf https://github.com/j178/prek/releases/download/v0.2.27/prek-installer.sh | sh
```
#### nasm
Not installed by default on my pop-os.
```
apt install nasm
```

#### objconv
Tool for translating whatever assembly to `nasm` compatible assembly. This one kinda sucks because you have to build it from source, you can clone the repo from 

[objconv - github](https://github.com/gitGNU/objconv)

The Makefile is somewhat broken?
I fixed it by placing it in the `src/` directory and running it from there.

```bash
git clone git@github.com:gitGNU/objconv.git
cd objconv
mv Makefile src/
cd src
make
```


This is the command I use for getting the `nasm` assembly from `src/main.c`

```bash
gcc src/main.c -Og -o a.out; objconv a.out -fnasm
```

### Handy commands
List the symbols in the lib
```bash
nm lib/libasm.so
```

### Generate assembly
To generate asm from c code you can use the following command
```
gcc <FILE.C> -S -masm=intel -Og -fverbose-asm
```
- `-masm` sets the dialect, options are: [`att`, `intel`].
- `-Og` suppresses any code optimization passes, giving us a pretty clear view to how the code relates to the assembly.
- `fverbose-asm` adds extra comments to make the assembly more readable.

```bash
objdump -M intel -d
```


```
gcc src/main.c -Og && objconv a.out -fnasm
```



## 🤓 Knowledge

### Makefile Automatic Variables
[gnu.org](https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html#Automatic-Variables)[stackoverflow](https://stackoverflow.com/a/3220288)
```makefile
all: library.cpp main.cpp
```
- `$@` evaluates to all
- `$<` evaluates to library.cpp
- `$^` evaluates to library.cpp main.cpp

```makefile
all:: main.c
```

The double colon `::` is used for seperating out rules, more info [here](https://web.archive.org/web/20180122002430/http://owen.sj.ca.us/~rk/howto/slides/make/slides/makecolon.html)

```makefile
PRECIOUS: intermediate_file.c
```

Make automatically deletes intermediate file's, use `PRECIOUS` to preserve them.

### ELF
#### Sections
From: `man elf`

- `.bss` (Block Starting Symbol) holds the statically allocated variables that have not been assigned.
- `.text` holds the "text", or executable instructions of a program.
- `.data` holds initialized data, its writable (`SHF_WRITE`).
- `.rodata` read-only data, such as `const` variables..

> [!NOTE] Note to self
> I've only seen `.bss` when declaring a global variable, not when declaring a static one inside a function.

### Memory
#### Argument Calling Order
```c
void func(int arg_1, int arg_2, int arg_3, int arg_4, int arg_5, int arg_6)
```

| Argument NR        | Register           |
|:------------- |:--------------|
| `arg_1`| `rdi` |
| `arg_2`      | `rsi`      |
| `arg_3`      | `rdx`      |
| `arg_4`      | `rcx`      |
| `arg_5`      | `r8`      |
| `arg_6`      | `r9`      |

#### The stack
- The stack grows towards `0x0`
- Stack pointer `RSP` points to the last (most recent entry) on the stack.

- [The stack explained](https://youtu.be/u_-oQx_4jvo)
T.B.A

#### Calling `__errno_location`
[..plt](https://stackoverflow.com/questions/5469274/what-does-plt-mean-here)
[NASM wrt](https://www.nasm.us/doc/nasm03.html#section-3.6)

### Instructions
#### MOV vs LEA
- `LEA` means Load Effective Address
- `MOV` means Load Value

`LEA` moves a pointer to whatever you're addressing, whereas `MOV` loads the value.

### Architecture
#### x86-64
[wiki](https://en.wikipedia.org/wiki/X86-64)
x86-64 is a 64-bit extension of the x86 instruction set.
T.B.A


## 📚 Sources
- [Intel vs AT&T ASM](https://stackoverflow.com/a/8550917)
- [UNIX Syscalls table](https://www.chromium.org/chromium-os/developer-library/reference/linux-constants/syscalls/)- [Calling Convetions](https://wiki.osdev.org/Calling_Conventions)
- [CPU Registers x86](https://wiki.osdev.org/CPU_Registers_x86)
- [NASM Docs](https://www.nasm.us/docs/3.01/)
- [NASM instructions](http://www.posix.nl/linuxassembly/nasmdochtml/nasmdoca.html)
- [x86 assembly guide](https://www.cs.virginia.edu/~evans/cs216/guides/x86.html)
- [ELF Sections](https://refspecs.linuxbase.org/elf/gabi4+/ch4.sheader.html) (Scroll to "Special Sections")
- [GCC Inline Assembly](https://www.ibiblio.org/gferg/ldp/GCC-Inline-Assembly-HOWTO.html)
- [Demystifing .rodata](https://iifx.dev/en/articles/460023732/demystifying-rodata-viewing-string-literals-in-godbolt-assembly)
- [Bracket operator in ASM](https://stackoverflow.com/a/48608575/7363348)
https://www.delorie.com/djgpp/doc/ug/asm/calling.html
- [LEA vs MOV](https://stackoverflow.com/a/1699778/7363348)
- [godbolt](https://godbolt.org/)

