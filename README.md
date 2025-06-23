# Paranoid Password Manager

**Author: Naksh Rathore**<br />
**Date: June 18th, 2025**

## Overview
This is a simple password manager CLI. It is made in [C](https://en.wikipedia.org/wiki/C_programming_language), a fast and low-level programming language used mainly for **embedded systems**, 
**OSes** (operating systems) like Linux, **CLIs** (command-line applications) like Git, and **performance-critical** software.
It is very fragile due to **no garbage collection** and **manual memory work** with things like **pointers** and **memory addresses**, so C code must be carefully written.

Paranoid has features like viewpasswords, createpassword, deletepassword, editpassword and master key checking. This project also covers all of the basic C concepts such as **variables**,
**input/output** operations, **loops**, **pointers**, **memory addresses**, and more. If you are starting to learn C, I highly recommend doing this project as it will help you to learn the basics of C very well.

**Example workflow**:

```bash
$ ./paranoid viewpasswords
Enter master password: 123
No passwords saved!

$ ./paranoid createpassword
Enter master password: 123

Enter site for password: Github
Enter password: qwerty

Password created successfully!

$ ./paranoid viewpasswords
Enter master password: 123

Passwords
Github: qwerty
```

## Build and Use

### 1: Build
To build the application on **Windows**, go into the **root** of the project (eg. `C:\Users\Bob\paranoid`). Then type `./build.bat` inside of the **terminal**. When the terminal says `Build complete`,
you can move onto step 2.

### 2. Use
Once you have built the application, you can run `./paranoid` to **display all commands**. That will show you what **everything** does (it's *not* a lot).

## Warning
Please **do not** use this as your **personal password manager**. It is **not secure**, it is not *meant* to be secure, and the owner of the repository is **not responsible for anything security-wise**. 
Please **take caution** and never use **your own passwords** from anything, as hackers can steal it anytime. 
Treat this repository as a **learning** project, not a **production-ready** application. 
