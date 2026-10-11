# Lesson 1: Setting Up Your Environment

## Goals

By the end of this lesson you will be able to:

1. Open a terminal on Debian and run basic commands.
2. Install the C++ compiler (`g++`) and related tools.
3. Install and configure the VSCodium code editor.
4. Write, compile, and run your first C++ program: "Hello, World!"
5. Explain the difference between **source code** and an **executable**.

---

## Part 1 - Meet the terminal

The terminal is a text-based way to control your computer. Programmers use it
constantly, so we'll start getting comfortable with it right away.

Open it with **Activities -> Terminal** (or press `Ctrl` + `Alt` + `T` on most
desktops). You'll see a *prompt* that looks something like:

```
student@debian:~$
```

That means: user `student`, on computer `debian`, currently in folder `~`
(your home folder), ready for a command.

Try these, one at a time:

```
$ whoami          # prints your username
$ pwd             # "print working directory" - where am I?
$ ls              # list files in this folder
$ mkdir cpp       # make a new folder called cpp
$ cd cpp          # change directory into it
$ pwd             # confirm you moved
$ cd ..           # go back up one level
$ clear           # clear the screen
```

> **Tip:** Press `Tab` to auto-complete file and folder names, and use the
> up-arrow key to recall previous commands. These two habits will save you
> hours.

### Checkpoint 1

- [ ] You can open a terminal.
- [ ] You created a `cpp` folder in your home directory.

---

## Part 2 - Install the compiler and tools

A computer can't run C++ source code directly. A **compiler** translates the
human-readable code you write (`hello.cpp`) into a machine-runnable
**executable** (`hello`). We'll use `g++`, the GNU C++ compiler.

Update the list of available software, then install the tools:

```
$ sudo apt update
$ sudo apt install build-essential gdb git clangd wget gpg
```

What you just installed:

| Package | What it does |
|---------|--------------|
| `build-essential` | `g++`, `make`, and the standard C++ library |
| `gdb` | A debugger - lets you pause a program and inspect it |
| `git` | Version control (used in Lesson 2) |
| `clangd` | Powers code completion and error highlighting in the editor |
| `wget`, `gpg` | Needed to securely add the VSCodium download source |

Verify the compiler is installed:

```
$ g++ --version
```

You should see something like `g++ (Debian 12.2.0-14) 12.2.0` (Debian 12) or
`g++ (Debian 14.2.0-...)` (Debian 13). Any version 12 or newer is fine.

> **"sudo: user is not in the sudoers file"?** Your account doesn't have
> administrator rights. Ask your instructor, or log in as root with `su -`
> and run `usermod -aG sudo <your-username>`, then log out and back in.

### Checkpoint 2

- [ ] `g++ --version` prints a version number.

---

## Part 3 - Install VSCodium

VSCodium is a free, open-source build of Visual Studio Code without Microsoft's
telemetry. It's the editor we'll use all semester.

**Step 1 - Add the signing key** (so Debian can verify the downloads are
genuine):

```
$ wget -qO - https://gitlab.com/paulcarroty/vscodium-deb-rpm-repo/raw/master/pub.gpg \
    | gpg --dearmor \
    | sudo dd of=/usr/share/keyrings/vscodium-archive-keyring.gpg
```

**Step 2 - Add the VSCodium repository.** First check which Debian you have:

```
$ cat /etc/debian_version
```

If it starts with **13** (or higher):

```
$ echo -e 'Types: deb\nURIs: https://download.vscodium.com/debs\nSuites: vscodium\nComponents: main\nArchitectures: amd64 arm64\nSigned-by: /usr/share/keyrings/vscodium-archive-keyring.gpg' \
    | sudo tee /etc/apt/sources.list.d/vscodium.sources
```

If it starts with **12**:

```
$ echo 'deb [arch=amd64,arm64 signed-by=/usr/share/keyrings/vscodium-archive-keyring.gpg] https://download.vscodium.com/debs vscodium main' \
    | sudo tee /etc/apt/sources.list.d/vscodium.list
```

**Step 3 - Install:**

```
$ sudo apt update
$ sudo apt install codium
```

Launch it from **Activities -> VSCodium**, or from the terminal with
`codium`.

> These commands come from the official instructions at
> <https://vscodium.com/>. If something fails, check there for updates.

### Install extensions

VSCodium gets extensions from the [Open VSX](https://open-vsx.org/) registry.
Microsoft's own C/C++ extension is *not* licensed for VSCodium, so we use the
open-source **clangd** extension instead - it's excellent.

Open the Extensions panel (`Ctrl` + `Shift` + `X`) and install:

1. **clangd** (publisher: `llvm-vs-code-extensions`) - code completion,
   error squiggles, go-to-definition.
2. **CodeLLDB** (publisher: `vadimcn`) - debugging support. *(Optional for
   today; we'll use it later.)*

Or install them from the terminal:

```
$ codium --install-extension llvm-vs-code-extensions.vscode-clangd
$ codium --install-extension vadimcn.vscode-lldb
```

### Checkpoint 3

- [ ] VSCodium opens.
- [ ] The clangd extension shows as installed.

---

## Part 4 - Hello, World!

### Create the project folder

In VSCodium choose **File -> Open Folder...** and open the `cpp` folder you
made in Part 1. Inside it, create a folder named `hello` and open that instead
(or in the terminal: `mkdir ~/cpp/hello && codium ~/cpp/hello`).

If VSCodium asks *"Do you trust the authors of the files in this folder?"*,
choose **Yes** - you're the author.

### Write the program

Create a new file called `hello.cpp` and type this in **by hand** (don't copy
and paste - typing it builds muscle memory and you'll learn from the typos):

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

Save with `Ctrl` + `S`.

### What each line means

| Line | Meaning |
|------|---------|
| `#include <iostream>` | Bring in the library for **i**nput/**o**utput **stream**s - lets us print text. |
| `int main() {` | Every C++ program starts running at the function named `main`. |
| `std::cout << "Hello, World!"` | Send the text to `cout` - the **c**haracter **out**put, i.e. the screen. |
| `<< std::endl;` | End the line (move to the next line). The `;` ends the statement. |
| `return 0;` | Tell the operating system the program finished successfully. |
| `}` | End of `main`. |

### Compile and run (the terminal way)

Open VSCodium's built-in terminal with `` Ctrl + ` `` (the backtick key, left
of `1`). Then:

```
$ g++ -std=c++20 -Wall -Wextra -g hello.cpp -o hello
$ ./hello
Hello, World!
```

Breaking down the compile command:

| Part | Meaning |
|------|---------|
| `g++` | Run the C++ compiler |
| `-std=c++20` | Use the C++20 version of the language |
| `-Wall -Wextra` | Turn on warnings - the compiler will point out likely mistakes |
| `-g` | Include debugging information |
| `hello.cpp` | The source file to compile |
| `-o hello` | Name the **o**utput executable `hello` |

And `./hello` means "run the program named `hello` in this folder (`.`)".

Run `ls` and notice there are now two files: `hello.cpp` (source code you can
read) and `hello` (the executable the computer runs). Try opening `hello` in
the editor - it's unreadable machine code.

### Compile and run (the one-key way)

Copy the `.vscode` folder from this lesson into your `hello` folder (it
contains [`tasks.json`](.vscode/tasks.json)). Now, with any `.cpp` file open,
press `Ctrl` + `Shift` + `B` to compile and run it in one step.

### Checkpoint 4

- [ ] Your terminal prints `Hello, World!`.

---

## Part 5 - Break it on purpose

Learning to read compiler errors is a core skill. Make each change below,
recompile, read the error, then fix it before trying the next one.

1. Delete the `;` after `std::endl`.
2. Misspell `cout` as `cuot`.
3. Remove the closing `"` after `World!`.
4. Delete the `#include <iostream>` line.
5. Change `main` to `Main`.

For each one, write down (a) the line number the compiler reported and
(b) the first few words of the error message. Notice how the error is often
reported on the line *after* the real mistake.

---

## Exercises

1. **Introduce yourself.** Change the program to print three lines: your name,
   your favorite food, and why you're taking this class.
2. **No `endl`.** Print the same three lines using a *single* `std::cout`
   statement and the newline escape `\n` inside the text, e.g.
   `"line one\nline two\n"`.
3. **Escape sequences.** Print this exactly, including the quotes and
   backslash:

   ```
   She said "C++ is fun!"
   The path is C:\Users\student
   ```

   *Hint:* look up `\"` and `\\`.
4. **Tabs.** Use `\t` to print a small table that lines up:

   ```
   Name    Age
   Ada     36
   Alan    41
   ```

## Vocabulary

- **Source code** - the text instructions you write (`.cpp` files).
- **Compiler** - a program that translates source code into an executable.
- **Executable** - a file the computer can run directly.
- **Statement** - a single instruction, ending with `;`.
- **Function** - a named block of code; `main` is the entry point.
- **Terminal / shell** - a text interface for running commands.
