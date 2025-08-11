# push_swap

> 42 Project

## Table of Contents

- [Overview](#overview)
- [Project Requirements](#project-requirements)
- [Allowed Operations](#allowed-operations)
- [How it Works](#how-it-works)
- [Project Rules](#project-rules)
- [Author](#author)

## Overview

`push_swap` is a sorting algorithm challenge from the 42 curriculum. The goal is to sort a stack of integers using a limited set of operations, with a focus on efficiency and minimizing the total number of moves required.

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

To achieve high efficiency and minimize the number of operations, this project uses a **chunked sorting algorithm** combined with a **greedy strategy** for move selection:

- **Chunked Sorting:** The input stack is divided into smaller "chunks" (subsets of numbers). By processing each chunk separately, elements are pushed and sorted incrementally, which allows for better control over the movement of elements between stacks and simplifies the sorting process.
- **Greedy Approach:** For each operation, the algorithm selects the move that leads most directly toward the sorted state, always choosing the operation that reduces the total number of moves required for the chunk being processed.

This combination allows the program to achieve strong efficiency, typically sorting 100 numbers in fewer than 700 operations and 500 numbers in no more than 5500 operations, well within the requirements of the project.

## Project Rules

- No external libraries allowed except those authorized by 42.
- Memory leaks and invalid accesses are forbidden.
- Input errors must be managed gracefully.

## Author

- [Arthur-SCF](https://github.com/Arthur-SCF)

---
This project adheres to the 42 school standards and maximizes efficiency for the required stack sizes.
