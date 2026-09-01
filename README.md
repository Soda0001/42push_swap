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

* **42 Push_swap Subject**: Official 42 school curriculum project specification.

### Time Complexity & Algorithm Analysis

* [Understanding Time Complexity – GeeksforGeeks](https://www.geeksforgeeks.org/dsa/understanding-time-complexity-simple-examples/)
* [Big-O Cheat Sheet – freeCodeCamp](https://www.freecodecamp.org/news/big-o-cheat-sheet-time-complexity-chart/)
* [Time and Space Complexity: A Beginner's Guide – Medium](https://medium.com/@pnandhiniofficial/time-and-space-complexity-a-beginners-guide-88d617d29d01)

### Sorting Algorithms

* [VisuAlgo – Sorting Algorithms Visualization](https://visualgo.net/en/sorting?slide=1)

### Bitwise Operations & Radix Sort

* [What Are Bitwise Shift Operators and How Do They Work? – Stack Overflow](https://stackoverflow.com/questions/141525/what-are-bitwise-shift-bit-shift-operators-and-how-do-they-work)
* [Left Shift and Right Shift Operators in C/C++ – GeeksforGeeks](https://www.geeksforgeeks.org/cpp/left-shift-right-shift-operators-c-cpp/)
* [Radix Sort Video Explanation](https://www.youtube.com/watch?v=rRYwmEG3wJI)
* [Bitwise Operations / Radix Sort Video](https://www.youtube.com/watch?v=fZZ3oUakA0o)

### Concepts Used in This Project

The following resources were used to better understand and research:

* **Time and space complexity analysis**
* **Big-O notation**
* **Sorting algorithm behavior**
* **Binary representation and bitwise operations**
* **Bit shifting operators in C**
* **Least Significant Digit (LSD) Radix Sort**
* **Algorithm visualization and performance analysis**

### AI Usage Disclosure

Artificial Intelligence tools were used during the development of this project as supplementary resources for learning, testing, and code review.

AI assistance was used to:

* **Support algorithm analysis and testing** by helping explore different approaches, test edge cases, and validate expected behavior.
* **Assist with debugging** by helping identify potential issues and explain unexpected program behavior during development.
* **Provide code review and best-practice suggestions** related to code structure, readability, and maintainability.
* **Support technical learning** by providing explanations of relevant concepts, including algorithms, complexity analysis, and bitwise operations.
* **README.md** Assisting on writing this README file.

All implementation, integration, testing, and final technical decisions were made by the project authors. AI-generated suggestions were reviewed, adapted where appropriate, and validated by the developers before being incorporated into the project.
