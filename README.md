# Push Swap

## Overview

Push Swap is a project developed as part of the 42 curriculum. The objective is to implement an efficient sorting algorithm using two stacks, `a` and `b`, with a limited set of operations. The goal is to sort a list of integers using the smallest number of operations possible, demonstrating the ability to work with algorithms and data structures.

## Requirements

- **C programming language**
- **42 school coding style** (no use of standard library functions like `qsort`)
- Use of stacks to store and manipulate the integers
- Limitations on the allowed operations (see below)

## Allowed Operations

The program must be able to perform the following operations:

1. **sa** - Swap the first two elements of stack `a`.
2. **sb** - Swap the first two elements of stack `b`.
3. **ss** - Perform `sa` and `sb` simultaneously.
4. **pa** - Push the top element of stack `b` onto stack `a`.
5. **pb** - Push the top element of stack `a` onto stack `b`.
6. **ra** - Rotate stack `a` upwards (first element becomes the last).
7. **rb** - Rotate stack `b` upwards (first element becomes the last).
8. **rr** - Perform `ra` and `rb` simultaneously.
9. **rra** - Reverse rotate stack `a` downwards (last element becomes the first).
10. **rrb** - Reverse rotate stack `b` downwards (last element becomes the first).
11. **rrr** - Perform `rra` and `rrb` simultaneously.

## How to Use

1. **Compilation**
   To compile the project, run:
   ```
   make
   ```

2. **Usage**
   To run the program:
   ```
   ./push_swap <list_of_numbers>
   ```
   Example:
   ```
   ./push_swap 5 2 3 8 1
   ```

   The program will output the sequence of operations to sort the list of numbers.
   
## Example

For input:

```
./push_swap 5 2 3 8 1
```

The output could be a sequence like:

```
pb
pb
ra
sa
pa
pa
```

The output will vary depending on the sorting strategy implemented.

## License

This project is part of the 42 curriculum and is provided under the terms of the [42 License](https://42.fr/en/terms-of-use/).
