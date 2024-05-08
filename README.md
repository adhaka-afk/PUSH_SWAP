# PUSH_SWAP


## Description:

Push_swap is a sorting algorithm implemented in C for sorting stacks of integers. It utilizes a combination of stack manipulation operations such as swapping, pushing, rotating, and reverse rotating to efficiently sort the elements in ascending order.
## Project Structure

. push_swap.c: Main program file containing the entry point and high-level sorting logic.

. operations.c: Implementation of stack manipulation operations (e.g., swap, push, rotate).

. sort.c: Contains sorting routines for small stack sizes and main sorting logic for larger stacks.

. utils.c: Utility functions for error handling and array manipulation.

. push_swap.h: Header file containing function prototypes and data structures.

## Implementation Details

The algorithm operates on two stacks named a and b. It follows the rules specified below:

. The stack a contains a random amount of negative and/or positive numbers, initially unsorted.

. The stack b is initially empty.

. The goal is to sort the numbers in stack a in ascending order.

. Available operations:
. sa (swap a)

. sb (swap b)

. ss (sa and sb simultaneously)

. pa (push a)

. pb (push b)

. ra (rotate a)

. rb (rotate b)

. rr (ra and rb simultaneously)

. rra (reverse rotate a)

. rrb (reverse rotate b)

. rrr (rra and rrb simultaneously)

The algorithm employs specific sorting routines for small stack sizes (3 or less) and divides the sorting process into smaller chunks for larger stacks, optimizing the number of operations required.

## Compilation

To compile the project, simply run 'make':

```bash
make
```
## Usage 
. Execute the program with a list of integers as arguments. The program will output the sorted sequence of operations to sort the stack. Example:

```bash
./push_swap 4 2 7 1
```
## Features
. Sorts a stack of integers in ascending order using the fewest number of operations.

. Supports sorting stacks of various sizes efficiently.

. Handles error cases such as invalid input arguments, duplicates, and integer overflow.

## Limitations

. Designed for sorting stacks of integers only.

. Larger stack sizes may require a higher number of operations to sort, impacting performance.
## 🚀 Next Project

[push_swap](https://github.com/adhaka-afk/PUSH_SWAP)

## ⏳ Previous Project

[minitalk](https://github.com/adhaka-afk/MINI_TALK)

