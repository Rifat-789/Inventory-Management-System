# Inventory Management System (C)

A console-based Inventory Management System developed using the C programming language.  
This project allows users to manage inventory items efficiently with persistent storage using binary files.

The system is menu-driven and focuses on clean program structure, proper input validation, and real-world data handling.

---

## Features

- Add new inventory items
- View all inventory items
- Search item by ID
- Update item details
- Delete items from inventory
- Persistent data storage using binary files
- Input validation to prevent invalid data
- Clean, menu-driven interface

---

## Technologies Used

- C Programming Language
- File Handling (`fopen`, `fread`, `fwrite`)
- Structures (`struct`)
- Pointers
- Standard C Libraries

---

## Project Structure

```text
Inventory-Management-System/
│
├── main.c # Main source code
├── inventory.dat # Binary file for storing inventory data
└── README.md # Project documentation
```

---

## ▶️ How to Compile and Run

Follow these steps to compile and run the Student Management System on your machine.

### 1️⃣ Prerequisites
Make sure you have a C compiler installed.

- **Linux / macOS:** GCC is usually preinstalled  
- **Windows:** Install MinGW or use WSL

Check if GCC is installed:
```bash
gcc --version
```

### 2️⃣ Clone or Download the Project
If using git: 
```bash
git clone git@github.com:Rifat-789/Student-Management-System.git
```
```bash
cd Student-Management-System
```

### 3️⃣ Compile the Program
```bash
gcc main.c -o Student-Management-System
```

### 4️⃣ Run the Program
- **Linux / macOS:** 
```bash
./Student-Management-System
```

- **Windows(Command Prompt or PowerShell):** 
```bash
Student-Management-System.exe
```

- **Windows(Git Bash):**
```bash
./Student-Management-System.exe
```

---

## ▶️ Author:

**Md Rifat**

---

## ▶️ License:

**This project is created for learning and educational purposes.**
