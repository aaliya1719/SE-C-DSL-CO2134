# Data Structures Lab Practicals

This folder contains the C practical programs for the Data Structures Lab submission. Additional practical files can be added to this folder as they are completed.

## Running on Windows

Install a C compiler such as GCC through MSYS2 or MinGW-w64. Confirm that GCC is available in PowerShell:

```powershell
gcc --version
```

Open PowerShell in this folder, then compile a practical with GCC. Replace `<filename>` with the C source file you want to run:

```powershell
gcc <filename>.c -o <filename>.exe
```

For example:

```powershell
gcc practical1.c -o practical1.exe
.\practical1.exe
```

Use the same commands for any additional `.c` practical file. The executable file is created in this folder and can be removed after testing.
