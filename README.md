

<h1 align="center">libasm</h1>
<p align="center">Re-writing libc C-functions in Intel x86-64 Assembly, compiled with nasm</p>
<p align="center">
		<a href="https://github.com/JopjeKnopje/libasm/actions/workflows/ci.yaml">
	<img alt="GitHub Actions Workflow Status" src="https://img.shields.io/github/actions/workflow/status/JopjeKnopje/libasm/ci.yaml?branch=main&style=flat-square">
	</a>

</p>

<hr />

</p>

I've mainly used this project to dive deeper into unit-testing, since these isolated functions are perfect for that.
This is a pretty dense README file, since it contains the Codam subject. And some my notes of my freshly aquired knowledge while learning about assembly and the ELF format.



> [!NOTE]
> Use the `--recurse-submodules` when cloning or run `git submodule update --init --recursive` after cloning.


## Toolchain
- [nasm](https://www.nasm.us/)
```
apt install nasm
```
- [prek](https://github.com/j178/prek?tab=readme-ov-file#installation)
```bash
# install prek into `~/.local/bin
curl --proto '=https' --tlsv1.2 -LsSf https://github.com/j178/prek/releases/download/v0.2.27/prek-installer.sh | sh
# install it into the repo
prek install
```

- [clang-format](https://clang.llvm.org/docs/ClangFormat.html) which is part of clang-tools, this is mainly run by the pre-commit hook.
```bash
apt install clang-tools
```

- A gdb [frontend](https://github.com/nakst/gf), more user friendly than the cli


## Handy commands
List the symbols in the lib
```bash
nm lib/libasm/libasm.a
```

### Generate assembly
To generate asm from c code you can use the following command
```
gcc <FILE.C> -S -masm=intel -Og -fverbose-asm
```
- `-masm` sets the dialect, options are: [`att`, `intel`].
- `-Og` suppresses any code optimization passes, giving us a pretty clear view to how the code relates to the assembly.
- `fverbose-asm` adds extra comments to make the assembly more readable.

List out the asm using objdump
```bash
objdump -M intel -d
```
<br>

## Learnings

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


> [!NOTE]
> I've only seen `.bss` when declaring a global variable, not when declaring a static one inside a function.



## Resources
- [Intel vs AT&T ASM](https://stackoverflow.com/a/8550917)
- [UNIX Syscalls table](https://www.chromium.org/chromium-os/developer-library/reference/linux-constants/syscalls/)
- [CPU Registers x86](https://wiki.osdev.org/CPU_Registers_x86)
- [NASM Docs](https://www.nasm.us/docs/3.01/)
- [NASM instructions](http://www.posix.nl/linuxassembly/nasmdochtml/nasmdoca.html)
- [x86 assembly guide](https://www.cs.virginia.edu/~evans/cs216/guides/x86.html)
- [ELF Sections](https://refspecs.linuxbase.org/elf/gabi4+/ch4.sheader.html) (Scroll to "Special Sections")
- [GCC Inline Assembly](https://www.ibiblio.org/gferg/ldp/GCC-Inline-Assembly-HOWTO.html)
- [Demystifing .rodata](https://iifx.dev/en/articles/460023732/demystifying-rodata-viewing-string-literals-in-godbolt-assembly)
- [linux kernel - memory mapping](https://linux-kernel-labs.github.io/refs/heads/master/labs/memory_mapping.html)
- [Bracket operator in ASM](https://stackoverflow.com/a/48608575/7363348)
https://www.delorie.com/djgpp/doc/ug/asm/calling.html
- [LEA vs MOV](https://stackoverflow.com/a/1699778/7363348)
- [godbolt](https://godbolt.org/)
- [stack buffer overflow attack](https://en.wikipedia.org/wiki/Stack_buffer_overflow)
- [big ass x86 and amd64 instruction list](https://www.felixcloutier.com/x86/)
- [jmp vs call](https://stackoverflow.com/a/32793293/7363348)
- [x86-64 Calling convention (mentions stack allignment)](https://wiki.osdev.org/System_V_ABI#x86-64)
- [PCMPISTRI](https://www.felixcloutier.com/x86/pcmpistri)
