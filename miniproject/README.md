# SmartFile
### File & Directory Management System

**A General Tree-based simulation of a hierarchical file system.**

---

## 1. Quick Start

### Prerequisites
- GCC compiler
- Terminal or command-line environment

### Compilation

```bash
gcc SmartFile.c -o SmartFile
```

### Execution

**Windows (PowerShell):**
```powershell
.\SmartFile.exe
```

**Linux / macOS:**
```bash
./SmartFile
```

---

## 2. Project Overview

SmartFile is a menu-driven C application that simulates the organization and management of files and directories through a hierarchical structure.

The project uses a **General Tree with First Child–Next Sibling (FCNS) representation** to maintain relationships between directories, subdirectories and files.

Through a console-based interface, users can create and manage directory contents, navigate through folders, search for items and view the complete directory hierarchy.

## 3. Problem Statement

Design a program to simulate a file directory system using a tree data structure. 
a. Create directories and subdirectories. 
b. Insert files into a directory. 
c. Search for a file or folder. 
d. Display the directory structure in hierarchical form

To design and implement a program that simulates a file directory system using a tree data structure. The system should support the creation of directories and subdirectories, insertion of files, searching for files or folders, and displaying the directory structure in hierarchical form.

## 4. Objectives

- To understand and implement a General Tree using C.
- To represent files and directories in a hierarchical structure.
- To create directories, subdirectories and files dynamically.
- To perform searching, navigation, renaming and deletion operations.
- To display the directory hierarchy in an organized format.
- To count the total number of files and directories.
- To apply concepts such as structures, pointers, dynamic memory allocation and recursion.

## 5. Features

SmartFile provides the following eight operations:

| Feature | Description |
|---|---|
| **Create Directory** | Creates a new directory inside the current directory. |
| **Create File** | Adds a file to the current directory. |
| **Search File/Directory** | Searches the directory hierarchy by name and displays the item's location. |
| **Display Directory Structure** | Displays the complete hierarchy in an indented tree format. |
| **Navigate Directory** | Moves into a selected directory or returns to its parent directory. |
| **Rename File/Directory** | Changes the name of an existing file or directory. |
| **Delete File/Directory** | Deletes files and empty directories. Non-empty directories cannot be deleted. |
| **Count Files & Directories** | Calculates and displays the total number of files, directories and items. |

## 6. Data Structure and Working

SmartFile uses a **General Tree** to represent the hierarchical organization of files and directories.

It follows the **First Child–Next Sibling (FCNS)** representation, where each node maintains pointers to its first child and next sibling. A parent pointer is also maintained to support navigation and location tracking.

### Node Structure

Each node contains the following fields:

| Field | Purpose |
|---|---|
| `name` | Stores the name of the file or directory. |
| `isDirectory` | Identifies whether the node represents a directory or file. |
| `firstChild` | Points to the first child of a directory. |
| `nextSibling` | Points to the next item under the same parent. |
| `parent` | Points to the parent directory. |

### Example Directory Hierarchy

```text
ROOT
├── Documents (Directory)
│   ├── Notes (File)
│   └── Assignment (File)
├── Pictures (Directory)
│   └── Photo (File)
└── Projects (Directory)
    └── CPrograms (Directory)
        └── Main (File)
```

Each directory can contain multiple files and subdirectories, while files act as individual items within the hierarchy.

## 7. Project Structure

```text
SmartFile/
│
├── SmartFile.c
├── README.md
│
├── docs/
│   └── SmartFile_Project_Report.docx
│
└── Output_Screenshots/
    ├── Directory_Creation.PNG
    ├── Directory_Deletion.PNG
    ├── Directory_Navigation.PNG
    ├── File_creation.PNG
    ├── Files_Folder_Count.PNG
    ├── Rename_Directory.PNG
    └── System_Structure.PNG
```

## 8. Limitations

- The directory hierarchy is maintained in memory and is not preserved after program termination.
- The program simulates file and directory operations; it does not create actual files or folders on the operating system.
- File and directory names must be entered as single words. Names containing spaces are not supported. Names with snake_case conventions are accepted.
- Only empty directories can be deleted.
- The application uses a console-based interface.

## 9. Future Enhancements

The project can be extended with the following improvements:

- Implement file handling to save and restore directory structures between executions.
- Support file and directory names containing spaces.
- Introduce a graphical user interface for easier interaction.
- Include file metadata such as size and creation date.
- Extend directory management with additional operations.

## 10. Academic Relevance – Concepts Used

This project demonstrates the practical application of the following Data Structures and Algorithms concepts:

- **General Tree:** Represents hierarchical relationships between files and directories.
- **First Child–Next Sibling Representation:** Stores multiple children using linked pointers.
- **Structures and Pointers:** Defines and connects individual tree nodes.
- **Dynamic Memory Allocation:** Uses `malloc()` and `free()` to allocate and release memory.
- **Recursion:** Used for tree traversal, searching, displaying and counting items.
- **Tree Operations:** Demonstrates insertion, searching, deletion and modification.
- **Hierarchical Representation:** Organizes data into parent-child relationships.

## 11. Conclusion

SmartFile is a Data Structures and Algorithms mini-project that demonstrates the practical application of General Trees in representing hierarchical file and directory structures. It combines concepts such as pointers, dynamic memory allocation, recursion and tree traversal through a simple interactive C application.

The project provides a practical understanding of how tree-based data structures can be used to organize and manage hierarchical information.

---

**SmartFile — Organize Your Files, Simplify Your Structure.**