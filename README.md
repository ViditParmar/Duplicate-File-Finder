# 🗂️ Duplicate File Finder

A C++ command-line tool that scans a folder and its subdirectories to find files with identical content. It groups duplicate files together and allows the user to remove them.

---

## 📖 Overview
Duplicate files can take up unnecessary storage space. This project finds duplicate files by comparing their **actual content**, so files with different names can still be identified as duplicates.

To reduce unnecessary comparisons, the program first groups files by their size. Only files with the same size are then compared byte-by-byte in binary mode to check if their contents are exactly the same.


---

## ✨ Features

🔹 📁 Custom folder path input

🔹 🔍 Recursive scanning of folders and subdirectories

🔹 📊 Groups files by file size before comparison

🔹 🔄 Compares file contents byte-by-byte

🔹 📋 Displays duplicate files in groups

🔹 🗑️ Option to delete duplicates

🔹 ⚠️ Handles invalid paths and file-opening errors

🔹 💾 Shows when no duplicate files are found

---

## ⚙️ How It Works

The program follows these steps:

1. **Enter Folder Path**
   
   🔹 The user provides the path of the folder to scan.

2. **Validate Path**
   
   🔹 Checks whether the path exists.
   
   🔹 Checks whether the path is a valid directory.

3. **Scan Files**
   
   🔹 Recursively scans the selected folder and its subdirectories.
   
   🔹 Stores the file name, path, and size of each regular file.

4. **Group Files by Size**
   
   🔹 Files are first grouped according to their file size.
   
   🔹 Files with different sizes cannot be duplicates, so this reduces unnecessary comparisons.

5. **Compare File Contents**
    
   🔹 Files with the same size are opened in binary mode.
   
   🔹 Their contents are compared byte-by-byte to determine whether they are identical.

6. **Display Duplicate Groups**
    
   🔹 Identical files are grouped together and displayed.

7. **Delete Duplicates**
    
   🔹 The user can choose to delete all duplicate files while keeping one copy from each group.

---

## 🔄 Program Flow

SELECT FOLDER

　　　  ↓
    
SCAN FOLDER AND SUBDIRECTORIES

　　　　↓
    
COLLECT FILE INFORMATION

　　　　↓
    
GROUP FILES BY SIZE

　　　　↓
    
COMPARE CONTENTS OF SAME-SIZE FILES

　　　　↓
    
IDENTIFY & GROUP DUPLICATE FILES

　　　　↓
    
DISPLAY DUPLICATE FILES

　　　　↓
    
CONFIRM DELETION

　　　　↓
    
KEEP ONE FILE & DELETE OTHER DUPLICATE COPIES

---

## 🛠️ Tech Stack

| Component | Details                                                                               |
| --------- | ------------------------------------------------------------------------------------- |
| Language  | C++17                                                                                 |
| Libraries | `<filesystem>`, `<fstream>`, `<vector>`, `<map>`, `<algorithm>`                       |
| Concepts  | STL containers, file I/O, OOP, recursion over directories |

---

## ▶️ How to Run

### Prerequisites

🔹 A C++ compiler with C++17 support

### Clone the repository

```bash
git clone https://github.com/ViditParmar/Duplicate-File-Finder.git
```

### Open the project folder

```bash
cd Duplicate-File-Finder
```

### Compile

```bash
g++ -std=c++17 duplicate_file_finder.cpp -o duplicate_file_finder
```

### Run

```bash
./duplicate_file_finder        # Linux / macOS
duplicate_file_finder.exe      # Windows
```
---

## ⚠️ Important Note

👉 The delete option permanently removes the selected duplicate files after confirmation.

---

## 💡 Future Improvements

🔹 Use buffered or chunk-based file comparison to improve performance.

🔹 Show the storage space that can be recovered by removing duplicates.

🔹 Add an option to move duplicate files to the Recycle Bin instead of deleting them permanently.

🔹 Skip inaccessible directories instead of terminating the program.

🔹 Improve the user interface for a clearer and more convenient experience.

---

## 🤝 Contribute

Suggestions and pull requests are welcome. Feel free to open an issue to discuss improvements.

---

## 👤 Author

  **Vidit Parmar**

  GitHub: https://github.com/ViditParmar

---

⭐ If you found this project useful, consider giving it a star!

---
