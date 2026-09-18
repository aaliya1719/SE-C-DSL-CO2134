# Student Marks C Program

This repository contains `pract1.c`, a menu-driven C program for inserting, deleting, displaying, sorting, and searching student marks.

## Requirements

You need a C compiler installed on the device. The repository does not store a compiler or a device-specific path.

### Windows

Install GCC through one of these options:

- **MSYS2:** install MSYS2, then in the MSYS2 UCRT64 terminal run `pacman -S --needed mingw-w64-ucrt-x86_64-gcc`.
- **MinGW-w64:** install a MinGW-w64 distribution and add its `bin` folder to the Windows `PATH`.

After installation, open a new terminal and confirm:

```powershell
gcc --version
```

### Ubuntu/Debian Linux

```bash
sudo apt update
sudo apt install build-essential
gcc --version
```

### macOS

Install Apple's command-line tools, then confirm that `clang` is available:

```bash
xcode-select --install
clang --version
```

## Compile and run

Open a terminal in the repository folder. The source file is compiled using a relative filename, so no path from another computer is required.

With GCC:

```text
gcc -std=c11 -Wall -Wextra -pedantic pract1.c -o pract1
```

Run it on Windows:

```powershell
.\pract1.exe
```

Run it on Linux or macOS:

```bash
./pract1
```

On macOS, use `clang` instead of `gcc` in the compile command if GCC is not installed.

## VS Code

1. Open the repository folder itself in VS Code, not only `pract1.c`.
2. Install the **C/C++** extension from Microsoft.
3. Make sure `gcc` is available in the terminal with `gcc --version`.
4. Run **Terminal > Run Build Task** and choose **Build pract1.c**.

The included task calls `gcc` from `PATH`; it does not contain a user-specific compiler path. Run the generated executable using the command for your operating system above.

## Common fix when it does not run

If VS Code says that `gcc` is not recognized, the compiler is either not installed or its `bin` directory is not in `PATH`. Install GCC using the instructions above, add the compiler's `bin` directory to `PATH`, close and reopen VS Code, and run `gcc --version` again.
