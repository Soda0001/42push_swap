*This project has been created as part of the 42 curriculum by sedeniz.*

# Libft

## Description

Libft is a custom C library developed as part of the 42 curriculum. The goal of the project is to recreate a subset of the standard C library while implementing additional utility functions for string manipulation, memory management, linked lists, and file descriptor output.

The project focuses on understanding low-level programming concepts, dynamic memory allocation, pointers, and writing clean, reusable C code while following the 42 Norm.

## Instructions

### Build

Compile the library:

```bash
make
```

Build everything:

```bash
make all
```

Remove object files:

```bash
make clean
```

Remove object files and the library:

```bash
make fclean
```

Rebuild:

```bash
make re
```

### Usage

Include the header:

```c
#include "libft.h"
```

Compile your program with the library:

```bash
cc main.c libft.a
```

## Functions

### Character functions

* ft_isalpha
* ft_isdigit
* ft_isascii
* ft_isprint
* ft_toupper
* ft_tolower
* ft_isalnum

### Memory functions

* ft_memset
* ft_bzero
* ft_memcpy
* ft_memmove
* ft_memchr
* ft_memcmp

### String functions

* ft_strlen
* ft_strdup
* ft_strlcpy
* ft_strlcat
* ft_strchr
* ft_strrchr
* ft_strncmp
* ft_strnstr

### Standard library functions

* ft_atoi
* ft_calloc

### Additional functions

* ft_substr
* ft_strjoin
* ft_strtrim
* ft_itoa
* ft_split
* ft_strmapi
* ft_striteri
* ft_putchar_fd
* ft_putstr_fd
* ft_putendl_fd
* ft_putnbr_fd

### Linked list functions

* ft_lstnew
* ft_lstadd_front
* ft_lstsize
* ft_lstlast
* ft_lstadd_back
* ft_lstdelone
* ft_lstclear
* ft_lstiter
* ft_lstmap

## Resources

* C for Dummies Blog — https://c-for-dummies.com/blog/
* Stack Overflow — https://stackoverflow.com/questions
* GeeksforGeeks — https://www.geeksforgeeks.org/

### References

* The Linux Programmer's Manual (man pages)
* The ISO C Standard Library documentation
* 42 Libft subject
* Jacob Sorber — https://www.youtube.com/watch?v=VOpjAHCee7c
* Bro Code https://www.youtube.com/watch?v=N6dOwBde7-M&t=378s
* You Suck at Programming https://www.youtube.com/watch?v=o9iZucYSkQA&t=2892s
* https://stackoverflow.com/questions/3472311/what-is-a-portable-method-to-find-the-maximum-value-of-size-t

### AI Usage

ChatGPT was used as a supplementary learning, debugging, and writing assistant during this project. It was used to:

* Clarify concepts related to pointers, memory management, file descriptors, and linked lists.
* Assist with drafting and organizing this README.

The code was written, reviewed, tested, and understood by me. AI assistance was used as a learning, debugging, and writing aid rather than as a replacement for the project's learning objectives.
