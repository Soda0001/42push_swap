*This project has been created as part of the 42 curriculum by alterzi, sedeniz.*

# Push_Swap

An optimized data sorting algorithm project written in C, adhering to 42 Norminette coding standards.

## Description

The **Push_swap** project is a key 42 algorithm challenge. The objective is to sort a stack of integer values in ascending order using a limited set of instructions and a secondary auxiliary stack, minimizing the total number of operations performed.

The project implements two stacks:
- **Stack A**: Contains the initial list of unique positive and negative integers.
- **Stack B**: Initially empty, used as a temporary holding area for manipulation.

### Available Operations

| Operation | Description |
| :--- | :--- |
| **`sa`** | Swap the top 2 elements of Stack A. |
| **`sb`** | Swap the top 2 elements of Stack B. |
| **`ss`** | Perform `sa` and `sb` simultaneously. |
| **`pa`** | Push the top element of Stack B onto Stack A. |
| **`pb`** | Push the top element of Stack A onto Stack B. |
| **`ra`** | Rotate Stack A up by 1 position (first element becomes last). |
| **`rb`** | Rotate Stack B up by 1 position (first element becomes last). |
| **`rr`** | Perform `ra` and `rb` simultaneously. |
| **`rra`** | Reverse rotate Stack A down by 1 position (last element becomes first). |
| **`rrb`** | Reverse rotate Stack B down by 1 position (last element becomes first). |
| **`rrr`** | Perform `rra` and `rrb` simultaneously. |

---

## Instructions

### Compilation

Build the executable binary `push_swap` using `make`:

```bash
make
```

Additional compilation targets:
- `make clean` : Remove object files (`.o`).
- `make fclean`: Remove object files and the generated `push_swap` binary and `libft.a`.
- `make re`    : Recompile the entire project from scratch.

### Execution & Usage

Run `push_swap` with a space-separated list of integers:

```bash
./push_swap 4 2 1 5 3
```

Or pass all numbers as a single quoted string:

```bash
./push_swap "4 2 1 5 3"
```

#### CLI Options & Modes

- **Benchmark Mode (`--bench`)**: Displays sorting performance statistics, including disorder percentage, strategy used, total operation counts, and a breakdown of each operation type.
  ```bash
  ./push_swap --bench 4 2 1 5 3
  ```

- **Forced Strategy Modes**: Override adaptive selection to evaluate specific algorithms:
  * `--simple`  : Forces selection / min-push sort.
  * `--medium`  : Forces chunk-based sorting (`sqrt(N)` chunks).
  * `--complex` : Forces Bitwise LSD Radix sort.
  * `--adaptive`: Default mode using disorder-based dynamic strategy selection.

  ```bash
  ./push_swap --bench --medium 4 2 1 5 3
  ```

#### Count Operations

To count the total number of operations generated:

```bash
./push_swap 4 2 1 5 3 | wc -l
```

#### Testing with Random Numbers (Bash / Python)

```bash
ARG=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(-1000, 1000), 100))))")
./push_swap --bench $ARG
```

---

## Algorithms & Technical Justification

To achieve optimal performance across different dataset sizes and initial arrangements, the project implements an **Adaptive Multi-Strategy Algorithm System**.

### 1. Simple Sort (N ≤ 5)
- **Concept**: Hardcoded optimal branch sorting for 2 and 3 elements, combined with greedy minimum-element pushing for sets up to 5 elements.
- **Justification**: Eliminates algorithmic overhead for tiny inputs, guaranteeing standard-compliant step counts (e.g. ≤ 3 steps for 3 elements, ≤ 12 steps for 5 elements).

### 2. Medium Sort (Chunk-Based Sort, N ≤ 100)
- **Concept**: Numbers are pre-ranked ($0 \dots N-1$). The stack is partitioned into $K = \lfloor\sqrt{N}\rfloor$ chunks based on rank ranges. Chunks are pushed sequentially from Stack A to Stack B, and then pushed back from Stack B to Stack A in descending order of max-rank.
- **Justification**: Dividing elements into $\sqrt{N}$ chunks drastically reduces rotation cost when pulling the maximum elements back to Stack A. Highly effective for medium-sized lists ($N \approx 100$), yielding operation counts well below standard limits.

### 3. Complex Sort (Bitwise LSD Radix Sort, N > 100)
- **Concept**: Indexes values to non-negative ranks ($0 \dots N-1$). Processes each bit of the binary representation of ranks from least significant bit (LSB) to most significant bit (MSB). For each bit position, elements with bit `0` are pushed to Stack B, while elements with bit `1` are rotated in Stack A. Stack B is then pushed back to Stack A.
- **Justification**: Radix Sort achieves consistent $O(N \log N)$ complexity without requiring complex distance calculations. For $N = 500$, it reliably completes sorting within acceptable step counts without worst-case degradation.

### 4. Adaptive Strategy & Disorder Metric
- **Disorder Formula**:
  $$\text{Disorder} = \frac{\text{Number of Inversions}}{\text{Total Pairs}} = \frac{|\{(i, j) \mid i < j \text{ and } A[i] > A[j]\}|}{\frac{N(N - 1)}{2}}$$
- **Justification**: Real-world data is often partially sorted. Computing the exact disorder percentage allows `push_swap` to pick:
  - **Simple Sort** when disorder is low ($< 20\%$).
  - **Medium Sort** when disorder is moderate ($< 50\%$).
  - **Complex Radix Sort** when disorder is high ($\ge 50\%$).

---

## Resources

### Documentation & References
- **42 Push_swap Subject**: Official 42 school curriculum project specification.
- **Radix Sort Algorithm**: Explanation of Least Significant Digit (LSD) Radix Sort on binary keys.
- **Inversion Count & Disorder Metrics**: Academic literature on measuring array disorder and inversion ratios.


In accordance with 42 curriculum guidelines, Artificial Intelligence (AI) assistance was utilized in this project for the following specific tasks:
1. **Refactoring & Code Modularization**: Reorganizing monolithic utility scripts into clean, single-responsibility files (`op_push.c`, `op_swap.c`, `op_rotate.c`, `op_reverse_rotate.c`, `stack_utils.c`, `sort_utils.c`).
2. **Norminette v3 Compliance**: Formatting function signatures, tab alignments, header headers, and resolving line-length / variable-count constraint violations.
3. **Build System & Edge-Case Auditing**: Constructing the root `Makefile` and auditing memory cleanup routines (`free_stack`) to ensure zero memory leaks.
4. **Documentation**: Structuring and drafting this `README.md` to fulfill Chapter VII specifications.

### AI Usage Disclosure
In accordance with 42 curriculum guidelines, Artificial Intelligence (AI) assistance was used in this project only as a supporting tool for testing and code review.

1. **Algorithm Testing & Validation:** AI assistance was used to help test the sorting algorithms with different inputs and edge cases, and to verify whether the implemented algorithms behaved as expected.
2. **Code Testing & Debugging:** AI was used as a support tool during testing to help identify potential issues, understand unexpected behavior, and validate the results of the implemented code.
3. **Best Practices & Code Review:** AI was used to review the code and suggest general best practices, improvements in readability, maintainability, and code structure. The implementation and final decisions remained the developer's responsibility.