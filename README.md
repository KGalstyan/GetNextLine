<h1 align="center">📄 get_next_line</h1>

<p align="center">
  <i>A function to read the next line from a file descriptor, efficiently handling multiple inputs and dynamic memory allocation.</i>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue.svg" />
  <img src="https://img.shields.io/badge/Project-get_next_line-yellowgreen.svg" />
  <img src="https://img.shields.io/badge/Status-Completed-brightgreen.svg" />
</p>

---

## 📌 Project Overview

**get_next_line** is a C project aimed at creating a function that can read the next line from a given file descriptor. The function efficiently manages memory, handles input from various files or standard input, and ensures correct handling of partial lines between multiple reads.

This project strengthens skills in **dynamic memory allocation**, **buffer management**, and **file handling** using the low-level C language.

---

## 🔧 Features

- **Efficient Line Reading:**
  - Reads a single line from the file descriptor at a time.
  - Supports handling large files or multiple lines without excessive memory usage.
  
- **Dynamic Memory Allocation:**
  - Allocates memory dynamically to store each line.
  - Ensures no memory leaks by properly freeing memory after use.
  
- **Works with Multiple File Descriptors:**
  - Handles input from files or standard input (`STDIN`), maintaining the state across multiple reads.

---


