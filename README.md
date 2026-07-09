# Huffman Satellite Encoder

A C implementation of a Huffman-style binary tree built over a set of
satellites (name + frequency), supporting level-order printing, binary-code
decoding, binary-code lookup, and lowest common ancestor (LCA) queries.

University assignment for the *Data Structures and Algorithms* course,
POLITEHNICA University of Bucharest.

## Table of Contents
- [Overview](#overview)
- [How it works](#how-it-works)
- [Tasks](#tasks)
  - [Task 1 - Level-order tree printing](#task-1---level-order-tree-printing)
  - [Task 2 - Decoding binary strings](#task-2---decoding-binary-strings)
  - [Task 3 - Binary code lookup](#task-3---binary-code-lookup)
  - [Task 4 - Lowest common ancestor](#task-4---lowest-common-ancestor)
- [Project structure](#project-structure)
- [Build & Run](#build--run)
- [Input format](#input-format)

## Overview

Each satellite has a name (`label`) and a frequency (`freq`). The program
builds a binary tree the same way Huffman coding builds a prefix-code tree:
repeatedly take the two nodes with the smallest frequency out of a min-heap,
merge them into a new internal node (frequency = sum, label = concatenation
of the two labels), and reinsert the merge node until a single root remains.

Once the tree is built, the merged internal-node labels double as a "path
signature," and the root-to-leaf path (`0` = left, `1` = right) doubles as a
binary code for every satellite - similar to how Huffman codes are derived
from the tree shape, except here the codes are used to identify satellites
rather than to compress data.

## How it works

1. Read `n` satellites (frequency + name) from the input file.
2. Insert them all into a min-heap, ordered by frequency (ties broken
   alphabetically by name).
3. Repeatedly extract the two smallest nodes, merge them into a new node,
   and reinsert it, until only the root remains.
4. Depending on the flag passed on the command line, run one of four tasks
   on the resulting tree.

## Tasks

### Task 1 - Level-order tree printing
Flag: `-c1`

Prints the tree breadth-first (level by level), one line per level, in the
format `frequency-label`. Implemented with an array-backed queue in
`printTreeBFS` (`src/tree.c`).

### Task 2 - Decoding binary strings
Flag: `-c2`

Reads a list of binary strings from the input file. For each one, walks the
tree from the root following `0` (left) / `1` (right), printing the label of
every leaf it reaches and restarting from the root - since a single string
can encode several concatenated satellite names. See `binary_to_tree`
(`src/binary.c`).

### Task 3 - Binary code lookup
Flag: `-c3`

Builds a flat array that maps every node's label to its binary code (the
root-to-node path), then looks up and prints the code for each requested
label. See `create_node_array` / `build_codes` (`src/binary.c`).

### Task 4 - Lowest common ancestor
Flag: `-c4`

Reads a sequence of labels and folds them left-to-right through
`findLCA`, so the final result is the common ancestor of *all* the given
satellites (analogous to computing the GCD of a list of numbers, one pair
at a time). See `task4` (`src/task.c`) and `findLCA` (`src/tree.c`).

## Project structure

```
Huffman-Satellite-Encoder/
├── include/            # Header files
│   ├── structures.h    # Node, MinHeap, binary_node_t
│   ├── auxiliary.h      # strdup / compare / swap helpers
│   ├── heap.h          # min-heap interface
│   ├── tree.h          # tree building, traversal, LCA
│   ├── binary.h        # binary-code encode/decode
│   └── task.h          # task 2 / 3 / 4 entry points
├── src/                # Implementation files
│   ├── auxiliary.c
│   ├── heap.c
│   ├── tree.c
│   ├── binary.c
│   ├── task.c
│   └── main.c          # argument parsing and program flow
├── Makefile
└── README.md
```

## Build & Run

```bash
make            # builds the "huffman-satellite-encoder" binary
./huffman-satellite-encoder -c1 input.txt output.txt
```

Available flags: `-c1`, `-c2`, `-c3`, `-c4` (one task per run).

```bash
make clean      # removes the compiled binary
```

## Input format

The first line contains `n`, the number of satellites, followed by `n`
lines of `frequency name` pairs:

```
5
7 sat1
2 sat2
6 sat3
9 sat4
1 sat5
```

Depending on the task, additional lines follow with binary strings
(task 2) or satellite names (tasks 3 and 4) to query.
