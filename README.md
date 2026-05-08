# Binary Trees

## Description

This project contains C implementations for working with binary trees and
related tree-based data structures. It starts with the fundamentals of binary
tree nodes, insertion, deletion, traversal, and measurement, then expands into
Binary Search Trees, AVL trees, and Max Binary Heaps.

The repository is part of the **Holberton School / Tuwaiq Academy** curriculum.
It focuses on building tree logic manually in C using structs, pointers,
recursion, dynamic memory allocation, and careful parent-child relationships.

The project includes implementations for:

- Basic binary tree node creation
- Left and right node insertion
- Tree deletion
- Leaf and root checks
- Pre-order, in-order, post-order, and level-order traversal
- Height, depth, size, leaves, nodes, and balance calculations
- Full, perfect, complete, BST, AVL, and heap validation
- Sibling, uncle, and ancestor lookup
- Left and right tree rotations
- Binary Search Tree insertion, search, array conversion, and removal
- AVL insertion, removal, array conversion, and sorted array conversion
- Max Binary Heap insertion, extraction, array conversion, and sorting
- Big O answer files for selected advanced tasks



---

## Table of Contents

- [Learning Objectives](#learning-objectives)
- [Project Requirements](#project-requirements)
- [Repository Structure](#repository-structure)
- [Header File Overview](#header-file-overview)
- [Data Structures](#data-structures)
- [Function Groups](#function-groups)
- [Complete Function Reference](#complete-function-reference)
- [Basic Binary Tree Tasks](#basic-binary-tree-tasks)
- [Traversal Functions](#traversal-functions)
- [Tree Measurement Functions](#tree-measurement-functions)
- [Tree Property Checks](#tree-property-checks)
- [Relationship Functions](#relationship-functions)
- [Rotation Functions](#rotation-functions)
- [Binary Search Tree Tasks](#binary-search-tree-tasks)
- [AVL Tree Tasks](#avl-tree-tasks)
- [Binary Heap Tasks](#binary-heap-tasks)
- [Big O Files](#big-o-files)
- [Compilation](#compilation)
- [Usage Examples](#usage-examples)
- [Project Notes](#project-notes)
- [Authors](#authors)
- [Acknowledgements](#acknowledgements)

---

## Learning Objectives

This project helps practice and understand:

- How binary trees are represented in C
- How to use structs to model tree nodes
- How parent, left child, and right child pointers work together
- How to allocate new nodes using dynamic memory
- How to free a tree safely using recursion
- How to insert nodes while preserving existing children
- How recursive tree traversal works
- How callback functions are used during traversal
- How to calculate height, depth, size, leaves, and balance
- How to identify full, perfect, complete, BST, AVL, and heap properties
- How Binary Search Trees organize values
- How AVL trees use rotations to stay balanced
- How Max Binary Heaps maintain complete-tree structure and heap order
- How to reason about the complexity of tree operations

---

## Project Requirements

| Requirement | Details |
| --- | --- |
| Language | C |
| Compiler | `gcc` |
| Recommended flags | `-Wall -Wextra -Werror -pedantic` |
| Header file | `binary_trees.h` |


---

## Repository Structure

The repository is organized as a flat C project. All implementation files are in
the project root, and each task is stored in its own `.c` file.

The naming pattern follows the Holberton task number:

```text
<task-number>-<function-or-topic>.c
```

Examples:

```text
0-binary_tree_node.c
6-binary_tree_preorder.c
111-bst_insert.c
121-avl_insert.c
133-heap_extract.c
```

The project also includes three Big O answer files:

```text
115-O
125-O
135-O
```

---

## Header File Overview

All public structures, typedefs, and function prototypes are declared in:

```text
binary_trees.h
```

The header includes:

- Standard includes: `<stddef.h>` and `<stdlib.h>`
- The main `struct binary_tree_s`
- Typedefs for binary trees, BSTs, AVL trees, and heaps
- Prototypes for basic binary tree functions
- Prototypes for traversal functions
- Prototypes for Binary Search Tree functions
- Prototypes for AVL tree functions
- Prototypes for Binary Heap functions

The header also declares two provided helper functions:

```c
void binary_tree_print(const binary_tree_t *);
void binary_tree_delete(binary_tree_t *tree);
```

`binary_tree_delete` is implemented in this repository. `binary_tree_print` is
declared as a provided helper prototype, but no implementation file for it is
included in this repository.

---

## Data Structures

The main structure used across the project is defined in `binary_trees.h`:

```c
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};
```

The same structure is reused through typedefs:

```c
typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;
```

This means all tree types in the project share the same physical node layout.
The difference between a normal binary tree, a BST, an AVL tree, and a heap is
the rule enforced by the functions that operate on the nodes.

---

## Function Groups

The repository can be understood in six main groups.

| Group | Task Range | Purpose |
| --- | --- | --- |
| Basic binary tree operations | `0` to `5` | Create, insert, delete, and inspect simple nodes |
| Traversal and measurements | `6` to `16` | Walk trees and calculate structural information |
| Relationships and advanced tree checks | `17`, `18`, `100` to `104` | Work with relatives, complete trees, and rotations |
| Binary Search Trees | `110` to `114` | Validate, insert, build, search, and remove BST values |
| AVL trees | `120` to `124` | Validate, insert, remove, and build balanced AVL trees |
| Binary heaps | `130` to `134` | Validate, insert, extract, build, and sort heaps |

---

## Complete Function Reference

This table lists every implemented task file in the repository.

| Task | File | Function | Category |
| --- | --- | --- | --- |
| 0 | `0-binary_tree_node.c` | `binary_tree_node` | Node creation |
| 1 | `1-binary_tree_insert_left.c` | `binary_tree_insert_left` | Node insertion |
| 2 | `2-binary_tree_insert_right.c` | `binary_tree_insert_right` | Node insertion |
| 3 | `3-binary_tree_delete.c` | `binary_tree_delete` | Tree deletion |
| 4 | `4-binary_tree_is_leaf.c` | `binary_tree_is_leaf` | Node check |
| 5 | `5-binary_tree_is_root.c` | `binary_tree_is_root` | Node check |
| 6 | `6-binary_tree_preorder.c` | `binary_tree_preorder` | Traversal |
| 7 | `7-binary_tree_inorder.c` | `binary_tree_inorder` | Traversal |
| 8 | `8-binary_tree_postorder.c` | `binary_tree_postorder` | Traversal |
| 9 | `9-binary_tree_height.c` | `binary_tree_height` | Measurement |
| 10 | `10-binary_tree_depth.c` | `binary_tree_depth` | Measurement |
| 11 | `11-binary_tree_size.c` | `binary_tree_size` | Measurement |
| 12 | `12-binary_tree_leaves.c` | `binary_tree_leaves` | Measurement |
| 13 | `13-binary_tree_nodes.c` | `binary_tree_nodes` | Measurement |
| 14 | `14-binary_tree_balance.c` | `binary_tree_balance` | Measurement |
| 15 | `15-binary_tree_is_full.c` | `binary_tree_is_full` | Property check |
| 16 | `16-binary_tree_is_perfect.c` | `binary_tree_is_perfect` | Property check |
| 17 | `17-binary_tree_sibling.c` | `binary_tree_sibling` | Relationship |
| 18 | `18-binary_tree_uncle.c` | `binary_tree_uncle` | Relationship |
| 100 | `100-binary_trees_ancestor.c` | `binary_trees_ancestor` | Relationship |
| 101 | `101-binary_tree_levelorder.c` | `binary_tree_levelorder` | Traversal |
| 102 | `102-binary_tree_is_complete.c` | `binary_tree_is_complete` | Property check |
| 103 | `103-binary_tree_rotate_left.c` | `binary_tree_rotate_left` | Rotation |
| 104 | `104-binary_tree_rotate_right.c` | `binary_tree_rotate_right` | Rotation |
| 110 | `110-binary_tree_is_bst.c` | `binary_tree_is_bst` | BST validation |
| 111 | `111-bst_insert.c` | `bst_insert` | BST insertion |
| 112 | `112-array_to_bst.c` | `array_to_bst` | BST construction |
| 113 | `113-bst_search.c` | `bst_search` | BST search |
| 114 | `114-bst_remove.c` | `bst_remove` | BST removal |
| 120 | `120-binary_tree_is_avl.c` | `binary_tree_is_avl` | AVL validation |
| 121 | `121-avl_insert.c` | `avl_insert` | AVL insertion |
| 122 | `122-array_to_avl.c` | `array_to_avl` | AVL construction |
| 123 | `123-avl_remove.c` | `avl_remove` | AVL removal |
| 124 | `124-sorted_array_to_avl.c` | `sorted_array_to_avl` | AVL construction |
| 130 | `130-binary_tree_is_heap.c` | `binary_tree_is_heap` | Heap validation |
| 131 | `131-heap_insert.c` | `heap_insert` | Heap insertion |
| 132 | `132-array_to_heap.c` | `array_to_heap` | Heap construction |
| 133 | `133-heap_extract.c` | `heap_extract` | Heap extraction |
| 134 | `134-heap_to_sorted_array.c` | `heap_to_sorted_array` | Heap sorting |

---

## Basic Binary Tree Tasks

### `binary_tree_node`

Creates a new node and initializes its stored value, parent pointer, and child
pointers.

| File | Prototype |
| --- | --- |
| `0-binary_tree_node.c` | `binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);` |

The node starts with no left or right children.

### `binary_tree_insert_left`

Inserts a new node as the left child of a given parent.

| File | Prototype |
| --- | --- |
| `1-binary_tree_insert_left.c` | `binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);` |

If the parent already has a left child, the new node is inserted between the
parent and the previous left child.

### `binary_tree_insert_right`

Inserts a new node as the right child of a given parent.

| File | Prototype |
| --- | --- |
| `2-binary_tree_insert_right.c` | `binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);` |

If the parent already has a right child, the new node is inserted between the
parent and the previous right child.

### `binary_tree_delete`

Deletes an entire binary tree.

| File | Prototype |
| --- | --- |
| `3-binary_tree_delete.c` | `void binary_tree_delete(binary_tree_t *tree);` |

The function recursively frees child nodes before freeing the current node.

### `binary_tree_is_leaf`

Checks whether a node is a leaf.

| File | Prototype |
| --- | --- |
| `4-binary_tree_is_leaf.c` | `int binary_tree_is_leaf(const binary_tree_t *node);` |

A leaf node has no left child and no right child.

### `binary_tree_is_root`

Checks whether a node is the root of a tree.

| File | Prototype |
| --- | --- |
| `5-binary_tree_is_root.c` | `int binary_tree_is_root(const binary_tree_t *node);` |

A root node has no parent.

---

## Traversal Functions

Traversal functions visit nodes in a specific order and call a callback
function on each visited node value.

The callback type used by traversal functions is:

```c
void (*func)(int)
```

### Traversal Summary

| Task | File | Function | Order |
| --- | --- | --- | --- |
| 6 | `6-binary_tree_preorder.c` | `binary_tree_preorder` | Root, left, right |
| 7 | `7-binary_tree_inorder.c` | `binary_tree_inorder` | Left, root, right |
| 8 | `8-binary_tree_postorder.c` | `binary_tree_postorder` | Left, right, root |
| 101 | `101-binary_tree_levelorder.c` | `binary_tree_levelorder` | Level by level |

### `binary_tree_preorder`

```c
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
```

Visits the current node first, then the left subtree, then the right subtree.

### `binary_tree_inorder`

```c
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
```

Visits the left subtree first, then the current node, then the right subtree.

For Binary Search Trees, in-order traversal usually visits values in ascending
order when the BST property is valid.

### `binary_tree_postorder`

```c
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
```

Visits the left subtree first, then the right subtree, then the current node.

### `binary_tree_levelorder`

```c
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
```

Visits nodes by tree level, starting from the root and moving downward.

The implementation uses helper logic to measure height and visit each level.

---

## Tree Measurement Functions

Measurement functions return information about the shape and size of a tree.

| Task | File | Function | Return Type |
| --- | --- | --- | --- |
| 9 | `9-binary_tree_height.c` | `binary_tree_height` | `size_t` |
| 10 | `10-binary_tree_depth.c` | `binary_tree_depth` | `size_t` |
| 11 | `11-binary_tree_size.c` | `binary_tree_size` | `size_t` |
| 12 | `12-binary_tree_leaves.c` | `binary_tree_leaves` | `size_t` |
| 13 | `13-binary_tree_nodes.c` | `binary_tree_nodes` | `size_t` |
| 14 | `14-binary_tree_balance.c` | `binary_tree_balance` | `int` |

### `binary_tree_height`

Measures the height of a binary tree.

```c
size_t binary_tree_height(const binary_tree_t *tree);
```

Height is based on the longest path from a node down to a leaf.

### `binary_tree_depth`

Measures the depth of a node.

```c
size_t binary_tree_depth(const binary_tree_t *tree);
```

Depth is based on how far a node is from the root.

### `binary_tree_size`

Counts all nodes in a tree.

```c
size_t binary_tree_size(const binary_tree_t *tree);
```

### `binary_tree_leaves`

Counts nodes that do not have children.

```c
size_t binary_tree_leaves(const binary_tree_t *tree);
```

### `binary_tree_nodes`

Counts nodes that have at least one child.

```c
size_t binary_tree_nodes(const binary_tree_t *tree);
```

### `binary_tree_balance`

Computes the balance factor of a tree.

```c
int binary_tree_balance(const binary_tree_t *tree);
```

The balance factor is based on the difference between the height of the left
subtree and the height of the right subtree.

---

## Tree Property Checks

These functions validate tree shape or ordering rules.

| Task | File | Function | Checks |
| --- | --- | --- | --- |
| 15 | `15-binary_tree_is_full.c` | `binary_tree_is_full` | Whether every node has either zero or two children |
| 16 | `16-binary_tree_is_perfect.c` | `binary_tree_is_perfect` | Whether all internal nodes have two children and leaves are at the same level |
| 102 | `102-binary_tree_is_complete.c` | `binary_tree_is_complete` | Whether all levels are filled from left to right |
| 110 | `110-binary_tree_is_bst.c` | `binary_tree_is_bst` | Whether a tree follows BST ordering rules |
| 120 | `120-binary_tree_is_avl.c` | `binary_tree_is_avl` | Whether a tree follows BST ordering and AVL balance rules |
| 130 | `130-binary_tree_is_heap.c` | `binary_tree_is_heap` | Whether a tree is complete and follows Max Heap order |

### Full Tree

Implemented by:

```c
int binary_tree_is_full(const binary_tree_t *tree);
```

A full binary tree has nodes with either no children or exactly two children.

### Perfect Tree

Implemented by:

```c
int binary_tree_is_perfect(const binary_tree_t *tree);
```

A perfect tree has all internal nodes with two children, and all leaves appear at
the same depth.

### Complete Tree

Implemented by:

```c
int binary_tree_is_complete(const binary_tree_t *tree);
```

A complete tree fills each level from left to right before moving to the next
level.

### BST Validation

Implemented by:

```c
int binary_tree_is_bst(const binary_tree_t *tree);
```

The implementation validates ordering rules across the tree using helper logic.

### AVL Validation

Implemented by:

```c
int binary_tree_is_avl(const binary_tree_t *tree);
```

The implementation validates both BST ordering and AVL balance conditions.

### Heap Validation

Implemented by:

```c
int binary_tree_is_heap(const binary_tree_t *tree);
```

The implementation checks complete-tree structure and heap order.

---

## Relationship Functions

These functions inspect relationships between existing nodes.

| Task | File | Function | Purpose |
| --- | --- | --- | --- |
| 17 | `17-binary_tree_sibling.c` | `binary_tree_sibling` | Finds a node with the same parent |
| 18 | `18-binary_tree_uncle.c` | `binary_tree_uncle` | Finds the sibling of a node's parent |
| 100 | `100-binary_trees_ancestor.c` | `binary_trees_ancestor` | Finds the lowest common ancestor of two nodes |

### `binary_tree_sibling`

```c
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
```

Returns the sibling of a node when one exists.

### `binary_tree_uncle`

```c
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
```

Returns the uncle of a node when one exists.

### `binary_trees_ancestor`

```c
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second);
```

Finds the lowest common ancestor between two nodes.

---

## Rotation Functions

Rotations are used by balanced tree structures such as AVL trees.

| Task | File | Function | Rotation |
| --- | --- | --- | --- |
| 103 | `103-binary_tree_rotate_left.c` | `binary_tree_rotate_left` | Left rotation |
| 104 | `104-binary_tree_rotate_right.c` | `binary_tree_rotate_right` | Right rotation |

### Left Rotation

```c
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
```

Performs a left rotation and returns the new root of the rotated subtree.

### Right Rotation

```c
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
```

Performs a right rotation and returns the new root of the rotated subtree.

Both rotation functions update parent and child pointers.

---

## Binary Search Tree Tasks

Binary Search Tree functions use the same `struct binary_tree_s` node layout but
apply BST ordering rules.

| Task | File | Function | Purpose |
| --- | --- | --- | --- |
| 110 | `110-binary_tree_is_bst.c` | `binary_tree_is_bst` | Checks if a tree is a valid BST |
| 111 | `111-bst_insert.c` | `bst_insert` | Inserts a value into a BST |
| 112 | `112-array_to_bst.c` | `array_to_bst` | Builds a BST from an array |
| 113 | `113-bst_search.c` | `bst_search` | Searches for a value in a BST |
| 114 | `114-bst_remove.c` | `bst_remove` | Removes a value from a BST |

### BST Typedef

```c
typedef struct binary_tree_s bst_t;
```

### `bst_insert`

```c
bst_t *bst_insert(bst_t **tree, int value);
```

Inserts a value into a Binary Search Tree and returns the new node.

### `array_to_bst`

```c
bst_t *array_to_bst(int *array, size_t size);
```

Builds a BST by inserting values from an array.

### `bst_search`

```c
bst_t *bst_search(const bst_t *tree, int value);
```

Searches for a value in a BST and returns the matching node when found.

### `bst_remove`

```c
bst_t *bst_remove(bst_t *root, int value);
```

Removes a value from a BST and returns the root of the updated tree.

---

## AVL Tree Tasks

AVL trees are self-balancing Binary Search Trees. This repository includes AVL
validation, insertion, removal, and construction functions.

| Task | File | Function | Purpose |
| --- | --- | --- | --- |
| 120 | `120-binary_tree_is_avl.c` | `binary_tree_is_avl` | Checks if a tree is a valid AVL tree |
| 121 | `121-avl_insert.c` | `avl_insert` | Inserts a value and balances the AVL tree |
| 122 | `122-array_to_avl.c` | `array_to_avl` | Builds an AVL tree from an array |
| 123 | `123-avl_remove.c` | `avl_remove` | Removes a value and rebalances the AVL tree |
| 124 | `124-sorted_array_to_avl.c` | `sorted_array_to_avl` | Builds an AVL tree from a sorted array |

### AVL Typedef

```c
typedef struct binary_tree_s avl_t;
```

### `binary_tree_is_avl`

```c
int binary_tree_is_avl(const binary_tree_t *tree);
```

Checks whether a tree satisfies both BST and AVL balance requirements.

### `avl_insert`

```c
avl_t *avl_insert(avl_t **tree, int value);
```

Inserts a value into an AVL tree and balances the tree when needed.

### `array_to_avl`

```c
avl_t *array_to_avl(int *array, size_t size);
```

Builds an AVL tree by inserting values from an array.

### `avl_remove`

```c
avl_t *avl_remove(avl_t *root, int value);
```

Removes a value from an AVL tree and rebalances the tree.

### `sorted_array_to_avl`

```c
avl_t *sorted_array_to_avl(int *array, size_t size);
```

Builds an AVL tree from a sorted array.

---

## Binary Heap Tasks

Binary Heap functions use the `heap_t` typedef and work with Max Binary Heap
rules.

| Task | File | Function | Purpose |
| --- | --- | --- | --- |
| 130 | `130-binary_tree_is_heap.c` | `binary_tree_is_heap` | Checks if a tree is a valid Max Binary Heap |
| 131 | `131-heap_insert.c` | `heap_insert` | Inserts a value into a Max Binary Heap |
| 132 | `132-array_to_heap.c` | `array_to_heap` | Builds a heap from an array |
| 133 | `133-heap_extract.c` | `heap_extract` | Extracts the root value from a heap |
| 134 | `134-heap_to_sorted_array.c` | `heap_to_sorted_array` | Converts a heap to a sorted array |

### Heap Typedef

```c
typedef struct binary_tree_s heap_t;
```

### `binary_tree_is_heap`

```c
int binary_tree_is_heap(const binary_tree_t *tree);
```

Checks whether a tree is complete and follows Max Binary Heap ordering.

### `heap_insert`

```c
heap_t *heap_insert(heap_t **root, int value);
```

Inserts a value into a Max Binary Heap.

### `array_to_heap`

```c
heap_t *array_to_heap(int *array, size_t size);
```

Builds a heap by inserting values from an array.

### `heap_extract`

```c
int heap_extract(heap_t **root);
```

Extracts the root value from a heap.

### `heap_to_sorted_array`

```c
int *heap_to_sorted_array(heap_t *heap, size_t *size);
```

Converts a heap into a sorted array.

---

## Big O Files

The repository includes three Big O answer files. Their values are listed here
exactly as they appear in the files.

| File | Line 1 | Line 2 | Line 3 |
| --- | --- | --- | --- |
| `115-O` | `O(log(n))` | `O(log(n))` | `O(log(n))` |
| `125-O` | `O(log(n))` | `O(log(n))` | `O(log(n))` |
| `135-O` | `O(n)` | `O(n)` | `O(n)` |

---

## Compilation

The repository does not include standalone `main` test files. To compile a task,
use the checker or test file provided by the curriculum and include the required
source files.

General pattern:

```bash
gcc -Wall -Wextra -Werror -pedantic <test_file.c> <task_file.c> -o test
```

Example for testing node creation with an external test file:

```bash
gcc -Wall -Wextra -Werror -pedantic test.c 0-binary_tree_node.c -o node_test
```

Example for testing insertion with an external test file:

```bash
gcc -Wall -Wextra -Werror -pedantic test.c 0-binary_tree_node.c 1-binary_tree_insert_left.c -o insert_left_test
```

Example for testing traversal with an external test file:

```bash
gcc -Wall -Wextra -Werror -pedantic test.c 0-binary_tree_node.c 6-binary_tree_preorder.c -o preorder_test
```

For functions that depend on helpers from other tasks, include those helper
files in the same compilation command.

---

## Usage Examples

The repository does not include its own `main` files, but a simple local test can
be written to create and inspect a tree.

### Creating Nodes

```c
#include "binary_trees.h"

int main(void)
{
	binary_tree_t *root;

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);

	binary_tree_delete(root);
	return (0);
}
```

### Traversing a Tree

Traversal functions require a callback function:

```c
#include <stdio.h>
#include "binary_trees.h"

void print_num(int n)
{
	printf("%d\n", n);
}
```

The callback can then be passed to a traversal function:

```c
binary_tree_inorder(root, print_num);
```

### Measuring a Tree

After creating a tree, measurement functions can be used:

```c
size_t height;
size_t size;
int balance;

height = binary_tree_height(root);
size = binary_tree_size(root);
balance = binary_tree_balance(root);
```

### Building a BST From an Array

```c
int array[] = {79, 47, 98, 12, 68};
bst_t *tree;

tree = array_to_bst(array, 5);
```

### Searching a BST

```c
bst_t *node;

node = bst_search(tree, 68);
```

### Building an AVL Tree

```c
int array[] = {79, 47, 98, 12, 68};
avl_t *tree;

tree = array_to_avl(array, 5);
```

### Building a Heap

```c
int array[] = {98, 47, 79, 12, 68};
heap_t *heap;

heap = array_to_heap(array, 5);
```

---

## Project Notes

- All tree node types use the same `struct binary_tree_s` layout.
- Parent pointers are part of the node structure.
- Insertion and rotation functions update parent-child relationships.
- Several functions return `NULL` when passed invalid input or when allocation
  fails.
- Traversal functions use callbacks and do not print directly by themselves.
- Several functions use recursion to walk through the tree.
- BST, AVL, and heap files reuse the same base binary tree structure.
- Some advanced files include local helper functions in the same source file.
- Big O files are included only for tasks `115`, `125`, and `135`.
- `binary_tree_print` is declared in the header as a provided helper prototype,
  but its implementation is not included in this repository.

---

## File List by Category

### Basic Tree Files

```text
0-binary_tree_node.c
1-binary_tree_insert_left.c
2-binary_tree_insert_right.c
3-binary_tree_delete.c
4-binary_tree_is_leaf.c
5-binary_tree_is_root.c
```

### Traversal Files

```text
6-binary_tree_preorder.c
7-binary_tree_inorder.c
8-binary_tree_postorder.c
101-binary_tree_levelorder.c
```

### Measurement and Property Files

```text
9-binary_tree_height.c
10-binary_tree_depth.c
11-binary_tree_size.c
12-binary_tree_leaves.c
13-binary_tree_nodes.c
14-binary_tree_balance.c
15-binary_tree_is_full.c
16-binary_tree_is_perfect.c
102-binary_tree_is_complete.c
```

### Relationship and Rotation Files

```text
17-binary_tree_sibling.c
18-binary_tree_uncle.c
100-binary_trees_ancestor.c
103-binary_tree_rotate_left.c
104-binary_tree_rotate_right.c
```

### BST Files

```text
110-binary_tree_is_bst.c
111-bst_insert.c
112-array_to_bst.c
113-bst_search.c
114-bst_remove.c
```

### AVL Files

```text
120-binary_tree_is_avl.c
121-avl_insert.c
122-array_to_avl.c
123-avl_remove.c
124-sorted_array_to_avl.c
```

### Heap Files

```text
130-binary_tree_is_heap.c
131-heap_insert.c
132-array_to_heap.c
133-heap_extract.c
134-heap_to_sorted_array.c
```

### Big O Files

```text
115-O
125-O
135-O
```

---

## Authors

- Fahad Almidaj
- Shouq Alqarni

---

## Acknowledgements

This project was completed as part of the **Holberton School / Tuwaiq Academy**
curriculum.
