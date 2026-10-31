_This project has been created as part of the 42 curriculum by psaudell._

# get_next_line

## Description

`get_next_line` is a C function that returns one line at a time from a file descriptor.
Each call returns the next line (including the `\n` if there is one), or `NULL` when there is
nothing left to read or when an error occurs.
The goal of the project is to learn how **static variables** work in C.

```c
char	*get_next_line(int fd);
```

The bonus version handles several file descriptors at the same time, using only one static variable.

## Instructions

Compile with your own `main.c`:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

Bonus:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c
```

`BUFFER_SIZE` is optional (default: `50`). Each returned line must be freed by the caller.

Example `main.c`:

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
```

## Algorithm

A static string `stock` keeps the characters read but not yet returned between two calls.

1. **Read**: while `stock` contains no `\n` and `read()` returns more than 0,
   read `BUFFER_SIZE` bytes and append them to `stock`.
2. **Extract**: copy `stock` up to and including the first `\n` (or to the end) into a new `line`.
3. **Keep the rest**: replace `stock` with what comes after `line`, so the next call starts there.
4. **Return** `line`. If `stock` is empty or an error happens, free it and return `NULL`.

**Why this approach:** it reads only what is needed to find the next line (not the whole file),
it works with any `BUFFER_SIZE` (1 or 10000000), and the static variable keeps the remaining
text between calls without using global variables.

**Bonus:** `stock` becomes an array `stock[MAX_FD]` (one string per file descriptor),
so each fd keeps its own reading state. It is still one single static variable.

## Resources

- `man 2 read`, `man 3 malloc`, `man 3 free`
- [Static variables in C – GeeksforGeeks](https://www.geeksforgeeks.org/static-variables-in-c/)
- [File descriptors – Wikipedia](https://en.wikipedia.org/wiki/File_descriptor)

**AI usage:** AI was used only to write this README from the existing code.
All the C code was written by me.
