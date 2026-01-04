# Get Next Line

*This project has been created as part of the 42 curriculum by [student].*

## Description

Get Next Line is a C programming project that implements a function capable of reading a line from a file descriptor. The main challenge is to manage a static variable to preserve the reading state between function calls, enabling line-by-line reading of files or standard input without losing data.

**Goal:** Create a function `get_next_line()` that returns one line at a time from a file descriptor, handling various buffer sizes and edge cases.

**Key Features:**

- Reads and returns one line at a time (including the `\n` character)
- Works with files, standard input, and any valid file descriptor
- Handles variable buffer sizes (defined at compilation)
- Memory-efficient implementation using static variables
- **Bonus:** Manages multiple file descriptors simultaneously with a single static variable array

## Instructions

### Compilation

The project includes a Makefile with the following rules:

```bash
make        # Compiles mandatory part
make bonus  # Compiles bonus part (multiple FD support)
make clean  # Removes object files
make fclean # Removes object files and libraries
make re     # Recompiles everything
```

### Manual Compilation

**Mandatory part:**

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

**Bonus part:**

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c test_bonus.c -o gnl_bonus
```

You can change the `BUFFER_SIZE` value to test different scenarios:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 ...      # Very small buffer
cc -Wall -Wextra -Werror -D BUFFER_SIZE=9999 ...   # Large buffer
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1000000 ... # Very large buffer
```

### Usage Example

```c
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("file.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

### Testing

Run the provided test programs:

```bash
./gnl              # Test mandatory part
./gnl_bonus        # Test bonus part with multiple FDs
```

## Algorithm Explanation

### Strategy: Static Buffer Management

The implementation uses a **static variable** to preserve data between function calls. This is the core concept that makes line-by-line reading possible.

### Algorithm Steps

1. **Read from File Descriptor:**
   - Use `read()` to fetch `BUFFER_SIZE` bytes from the file descriptor
   - Store the read content in a temporary buffer

2. **Accumulate Data:**
   - Concatenate the newly read data to the static variable
   - The static variable accumulates all unprocessed data across function calls

3. **Search for Newline:**
   - Use `ft_strchr()` to locate the first `\n` character in the accumulated data
   - If found, extract everything up to and including the `\n` as the line to return

4. **Extract and Update:**
   - Extract the line (from start to `\n`)
   - Update the static variable to keep only the remaining data (after `\n`)
   - Return the extracted line

5. **End of File Handling:**
   - When `read()` returns 0 (EOF) and data remains in the static variable, return that data
   - Free the static variable and return NULL on subsequent calls

### Why This Algorithm?

**Advantages:**

- **Memory Efficient:** Only reads `BUFFER_SIZE` bytes at a time
- **Stateful:** Preserves reading position between calls without re-reading
- **Flexible:** Works with any buffer size (1 to 10,000,000+)
- **Simple:** Uses minimal helper functions and straightforward logic

**Trade-offs:**

- Static variables persist throughout program execution
- Cannot handle concurrent reads from different threads on the same FD (not required)

### Bonus: Multiple File Descriptors

For the bonus part, instead of a single static variable, we use an **array of static variables** indexed by file descriptor:

```c
static char *tmp[MAX_FD];  // One buffer per FD
```

This allows independent reading state for each file descriptor. When `get_next_line(fd)` is called:

- The function accesses `tmp[fd]` for that specific file descriptor
- Each FD maintains its own reading position
- You can alternate between FDs without losing state

**Example:**

```c
get_next_line(3);  // Reads from FD 3
get_next_line(4);  // Reads from FD 4
get_next_line(3);  // Continues reading FD 3 from where it left off
```

## Resources

### Official Documentation

- [Linux man page: read(2)](https://man7.org/linux/man-pages/man2/read.2.html)
- [Linux man page: open(2)](https://man7.org/linux/man-pages/man2/open.2.html)
- [Linux man page: close(2)](https://man7.org/linux/man-pages/man2/close.2.html)
- [Static Variables in C](https://www.geeksforgeeks.org/static-variables-in-c/)

### Tutorials & Articles

- [Understanding File Descriptors](https://www.computerhope.com/jargon/f/file-descriptor.htm)
- [C Programming: Memory Management](https://www.learn-c.org/en/Dynamic_allocation)
- [Buffer Management in C](https://stackoverflow.com/questions/1658476/what-is-a-buffer-in-c)

### AI Usage Disclosure

**How AI was used in this project:**

❌ **NOT used for:**

- Writing the core algorithm or logic
- Solving the fundamental challenges
- Generating the main function implementation

✅ **Used for:**

- Reviewing code for compilation errors and edge cases
- Suggesting improvements to memory management
- Helping debug specific error messages
- Formatting and organizing documentation
- Explaining complex concepts (static variables, file descriptors)

**Justification:**
AI was used as a **code review tool** and **debugging assistant**, not as a solution provider. The core logic, algorithm design, and implementation were developed through:

- Manual testing with various buffer sizes
- Peer discussions about edge cases
- Trial and error to handle EOF and newline scenarios
- Personal understanding of static variables and memory management

The AI helped identify issues like:

- Type mismatches (e.g., `char` vs `char*`)
- Memory leaks in error paths
- Missing null-termination after `read()`
- Compilation warnings with strict flags

This approach allowed me to build strong foundations while using AI responsibly as a learning aid, not a shortcut.

## Project Files

### Mandatory Part

- `get_next_line.c` - Main function implementation
- `get_next_line_utils.c` - Helper functions (ft_strchr, ft_strlen, ft_substr, etc.)
- `get_next_line.h` - Header file with function prototypes
- `main.c` - Test program for single file descriptor

### Bonus Part

- `get_next_line_bonus.c` - Implementation with multiple FD support
- `get_next_line_utils_bonus.c` - Helper functions (bonus)
- `get_next_line_bonus.h` - Header file (bonus)
- `test_bonus.c` - Test program for multiple file descriptors

### Build Files

- `Makefile` - Compilation automation

## Testing Strategy

### Basic Tests

1. Normal files with newlines
2. Files without final newline
3. Empty files
4. Very long lines
5. Single character lines

### Buffer Size Tests

- BUFFER_SIZE = 1 (read one byte at a time)
- BUFFER_SIZE = 42 (standard)
- BUFFER_SIZE = 9999 (large buffer)
- BUFFER_SIZE = 10000000 (very large buffer)

### Edge Cases

- Invalid file descriptor (-1, closed FD)
- Reading from stdin (fd = 0)
- Multiple consecutive newlines
- Lines exactly BUFFER_SIZE long
- Binary files (undefined behavior, but shouldn't crash)

### Bonus Tests

- Alternating reads between 3+ file descriptors
- Reading different amounts from each FD
- Closing one FD while others remain open

## Author Notes

This project taught me valuable lessons about:

- Static variables and their persistence
- Memory management and avoiding leaks
- File I/O operations at a low level
- Buffer management strategies
- Edge case handling
