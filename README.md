*This project has been created as part of the 42 curriculum by mibaboul.*

# ft_printf

## Description

`ft_printf` is a C implementation of a subset of the standard `printf` function.
The project introduces variadic functions, argument handling, and conversion of
numbers into decimal and hexadecimal representations.

It builds a static library, `libftprintf.a`, with the following public function:

```c
int ft_printf(const char *format, ...);
```

The function writes to standard output and counts the characters it prints.
It supports the mandatory conversions from subject version 12.1:

| Conversion | Argument | Output |
| --- | --- | --- |
| `%c` | `int` | A single character |
| `%s` | `char *` | A null-terminated string |
| `%p` | `void *` | A hexadecimal address prefixed with `0x` |
| `%d`, `%i` | `int` | A signed decimal integer |
| `%u` | `unsigned int` | An unsigned decimal integer |
| `%x` | `unsigned int` | A lowercase hexadecimal integer |
| `%X` | `unsigned int` | An uppercase hexadecimal integer |
| `%%` | None | A percent sign |

Bonus flags, field widths, and precision are not implemented.
The implementation does not reproduce the buffering of the original `printf`.

## Instructions

### Requirements

- A Unix-like environment with `write` available through `<unistd.h>`.
- A C compiler available as `cc`, `make`, and `ar`.

### Compilation

Run the following command from the repository root:

```sh
make
```

This creates `libftprintf.a` using `cc` with `-Wall -Wextra -Werror` and
archives the object files with `ar rcs`.

| Command | Effect |
| --- | --- |
| `make` or `make all` | Build the static library |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and the library |
| `make re` | Remove build artifacts and rebuild the library |

### Usage

Create a `main.c` file:

```c
#include "ft_printf.h"

int main(void)
{
    int count;

    count = ft_printf("Hello %s! Number: %d, hex: %x, progress: 100%%\n",
            "42", -42, 255U);
    ft_printf("Printed %d characters.\n", count);
    return (0);
}
```

Compile and run it from the repository root:

```sh
cc -Wall -Wextra -Werror -I . main.c libftprintf.a -o example
./example
```

Expected output:

```text
Hello 42! Number: -42, hex: ff, progress: 100%
Printed 47 characters.
```

### Implementation behavior

A null format pointer returns `-1`. A null string argument prints `(null)`,
and a null pointer argument prints `(nil)`. The latter differs from macOS
`printf`, which prints `0x0` for a null pointer.

Use the supported conversions with arguments of the appropriate types.
Invalid format strings and unsupported conversions are outside the supported
interface. Write failures are not consistently propagated by the current helpers.

## Algorithm and Data Structures

### Format parsing and variadic arguments

`ft_printf` scans the format string from left to right using an integer index.
Ordinary characters are written directly. When the parser encounters `%`, it
passes the next character to `handle_conversion`, which selects the appropriate
output helper.

The variadic arguments are accessed through a `va_list`, initialized with
`va_start` and released with `va_end`. The conversion handler receives a pointer
to this list so that each `va_arg` advances the same argument sequence.
For `%c`, the argument is read as an `int` because of the default argument
promotions in variadic calls.

Each output helper returns its character count. The parser adds these counts
to the number of literal characters to compute the final return value.

This direct scan is sufficient for the mandatory conversions and keeps parsing
separate from number and string output. No token array, linked list, or dynamic
allocation is needed: the implementation uses the input strings, scalar
counters, a `va_list`, and hexadecimal digit lookup strings.

### Number conversion

Numbers are printed recursively. Dividing by the output base processes the
leading digits first, and the remainder selects the final digit. Decimal output
uses base 10; hexadecimal output uses base 16 and a digit lookup string.
This avoids building an intermediate output buffer.

For signed integers, the value is first stored in a `long` before its sign is
handled. On the targeted 64-bit Unix platforms, this allows `INT_MIN` to be
negated without overflowing an `int`.

Pointer output uses a dedicated recursive helper that accepts an
`unsigned long`, preserving the full address on the targeted LP64 platforms
instead of narrowing it to an `unsigned int`. Non-null addresses are preceded
by `0x`.

### Complexity

For a format string of length `n` producing `m` output characters, processing
takes O(n + m) time. Recursive number conversion uses O(log_b(v)) stack space
for a positive value `v` in base `b`; zero uses constant space. There are no
heap allocations.

## Resources

- [Project subject](ft_printf.pdf), version 12.1: mandatory conversions,
  submission requirements, and README requirements.
- `man 3 printf`: formatted output and return-value conventions.
- `man 3 stdarg`: variadic argument handling with `va_list` and its macros.
- `man 2 write`: writing bytes to a file descriptor.
- `man 1 ar` and `man 1 make`: static archives and build rules.
- The 42 Norm and `norminette`: C formatting and style requirements.

### AI Usage

- Artificial intelligence: used to draft and organize this README. It was used for the documentation task only, specifically to summarize the project, explain the build instructions, and the source file names. AI was not used to write or modify the library source code.