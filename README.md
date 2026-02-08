
# Linux Utilities and System Programming

This repository contains implementations of basic **Linux command-line utilities** and **system programming concepts** written in **C**, using **Linux system calls**.  
The goal of this repository is to strengthen understanding of **Linux internals**, **process management**, and **multithreading**, rather than relying on library abstractions.

---

## 📌 Contents

### 🧾 Linux Commands (Custom Implementations)
- **cp** – File copy utility using low-level file operations  
- **ls** – Directory listing using directory-related system calls  
- **cat** – Display file contents using `open`, `read`, and `write`  
- **grep** – Pattern searching in files using string handling and system calls  

### ⚙️ System Programming Concepts
- **fork system call**
  - Process creation
  - Parent–child execution behavior
- **Thread handling**
  - Thread creation and execution
  - Basic multithreading concepts
- **Mutex**
  - Mutual exclusion
  - Synchronization between threads

---

## 🛠️ Technologies Used
- Programming Language: **C**
- Platform: **Linux**
- Concepts:
  - System calls (`open`, `read`, `write`, `fork`, etc.)
  - Process management
  - Multithreading
  - Synchronization (mutex)

---

## 🎯 Purpose of This Repository
- To understand how common Linux utilities work internally  
- To practice **system-level programming**  
- To build a strong foundation for **Embedded Linux / Linux Kernel-related roles**  

---

## ▶️ How to Compile and Run
Use `gcc` to compile the programs.

Example:
```bash
gcc cat.c
./a.out filename
