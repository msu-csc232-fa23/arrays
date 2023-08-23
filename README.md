# ICE01: Arrays

This repo contains code similar to that found in our textbook, Appendix A.6-A.7.

## Background

Before proceeding with this lab, the student should take the time to read

* Appendix A.6.1 One-Dimensional Arrays
* Appendix A.6.2 Multidimensional Arrays
* Appendix A.7 Strings

## Objective

Upon successful completion of this lab, the student has learned how to declare and process

* one-dimensional arrays
* multidimensional arrays
* strings

in C++.

## Getting Started

After accepting this assignment with the provided [GitHub Classroom Assignment link](https://classroom.github.com/a/WsVfQ0KM), open the repository in Codespaces. Once the Codespace has opened, open the [CMakeLists.txt](CMakeLists.txt) file. It's been my experience that when this file is opened, Visual Studio Code will suggest installing a CMake plugin. I highly recommend doing so, as this will greatly simplify your efforts to build different executables (aka, "targets") that correspond to different tasks in this ICE (In-Class Exercise).

_Regardless of whether you install this plugin or not, command-line instructions (cli) will also be provided that will show you how to compile and link your sources into an executable._

Next, create a branch named `develop`. Open a terminal window and type

```shell
git checkout -b develop
```

This is actually two commands in one; it combines a `git branch` command with a `git checkout` command to both create a new branch and check it out.

Make sure you are on the `develop` branch before you get started. Make all your commits on the `develop` branch.

```bash
git status
```

_You may have to type the `q` character to get back to the command line prompt after viewing the status._

## Tasks

This ICE (In Class Exercise) consists of three tasks:

- Task 1: Declare and process a one-dimensional array
- Task 2: Declare and process a multidimensional array
- Task 3: Declare and process strings

### Task 1: Declare and process a one-dimensional array

1. Let's begin by examining the declarations in [task01.h](include/task01.h).
2. Next, let's examine the code in [task01.cpp](src/main/cpp/task01.cpp).

Noteworthy observations:

- Declaration of a one-dimensional array
- The use of `typedef`
- The use of a `const` parameter when declaring array parameters
- The need to provide additional details, e.g., `n`, the size of the array, as another parameter for functions that process arrays.

### Task 2: Declare and process a multidimensional array

1. Let us again begin by examining the declarations in [task02.h](include/task02.h).
2. And now, let's examine the code in [task02.cpp](src/main/cpp/task02.cpp).

Noteworthy observations:

- Declaration of a two-dimensional array
- Again, the use of `typedef` to help simplify multidimensional array declaration.
- We take advantage of the default parameter passing mechanism of array parameters, namely, pass by reference
- Processing a two-dimensional array is facilitated by a nested loop.

### Task 3: Declare and process strings

1. Finally, let's examine the code in [task03.cpp](src/main/cpp/task02.cpp).

Noteworthy observations:

- There are myriad string operations
- String positions begin at position 0
