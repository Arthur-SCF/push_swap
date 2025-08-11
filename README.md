# push_swap

> 42 Project

## Overview

`push_swap` is a sorting algorithm challenge from the 42 curriculum. The goal is to sort a stack of integers using a limited set of operations, with a focus on efficiency and minimizing the total number of moves. The project is split into two parts:
- **push_swap**: Outputs the sequence of operations needed to sort the stack.
- **checker**: Verifies that a given sequence of operations sorts the stack correctly.

## Project Requirements

This project respects the requirements for maximum project validation (100%).
- **Sort 100 random numbers in fewer than 700 operations.**
- **Sort 500 random numbers in no more than 5500 operations.**

## Allowed Operations

- `sa` / `sb` / `ss`: swap the top two elements of stack A, B, or both.
- `pa` / `pb`: push the top element to stack A or B.
- `ra` / `rb` / `rr`: rotate stack A, B, or both (shift up all elements by 1).
- `rra` / `rrb` / `rrr`: reverse rotate stack A, B, or both (shift down all elements by 1).

## How it Works

1. **Parsing**: The program parses input numbers and validates them.
2. **Sorting**: An efficient algorithm (commonly using variations of quicksort, radix sort, or other techniques) determines the optimal moves.
3. **Output**: The minimal sequence of operations is printed to standard output.

## Project Rules

- No external libraries allowed except those authorized by 42.
- Memory leaks and invalid accesses are forbidden.
- Input errors must be managed gracefully.

## Author

- [Arthur-SCF](https://github.com/Arthur-SCF)

---
This project adheres to the 42 school standards and maximizes efficiency for the required stack sizes.
