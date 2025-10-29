# C Programs Collection — How to compile & run

Hi — this folder contains ten small C programs (numbered `1.c` through `10.c`). Each file implements a classic algorithm (e.g., insertion sort, merge sort, Dijkstra, Rabin-Karp, etc.). Below you'll find simple, human-friendly instructions for compiling and running them on macOS (zsh).

If anything below is unclear or you'd like me to add a Makefile or build script, tell me and I'll add it.

---

What you need

- A C compiler: macOS ships with clang; calling `gcc` usually works as an alias to clang. If you prefer GNU GCC, install it (Homebrew: `brew install gcc`).
- Terminal (you're using `zsh`) and basic familiarity with running commands.

Quick map (file → algorithm)

- `1.c` — Insertion Sort (Time: Best O(n), Avg/Worst O(n^2))
- `2.c` — Merge Sort (Time: O(n log n))
- `3.c` — Binary Search (Time: O(log n))
- `4.c` — Naive String Matching (Time: O(n\*m))
- `5.c` — Fractional Knapsack (Greedy, Time: O(n log n))
- `6.c` — Dijkstra's Algorithm (array-based, Time: O(V^2))
- `7.c` — N-Queens (Backtracking, exponential)
- `8.c` — TSP (Backtracking, brute-force, factorial)
- `9.c` — Floyd–Warshall (Time: O(n^3))
- `10.c` — Rabin-Karp (rolling hash; Avg O(n+m), worst O(n\*m))

How to compile & run one program

1. Open Terminal in this folder (or `cd` to it):

```zsh
cd /Users/raajpatkar/Desktop/untitled\ folder\ 9
```

2. Compile a single file (example: `1.c` → output binary `1`):

```zsh
gcc -Wall -Wextra -o 1 1.c
```

If `gcc` is not found, try `cc` or install a compiler. On macOS `gcc` is typically a front to clang and works fine.

3. Run the compiled program:

```zsh
./1
```

Each program expects input in a simple interactive way (they prompt you). For example, `1.c` asks for `n` and then the numbers. Follow prompts.

Compile & run with one command (compile then run):

```zsh
gcc -Wall -Wextra -o 1 1.c && ./1
```

Compile all programs (quick loop)
This will attempt to compile every `N.c` into a binary named `N` (1..10). If compilation fails for a file, the loop stops and shows the error.

```zsh
for i in {1..10}; do
  gcc -Wall -Wextra -o "$i" "$i.c" || break
done
```

Run them by name (examples):

```zsh
./1    # insertion sort
./2    # merge sort
./3    # binary search
# ... and so on
```

Tips & examples

- Many programs read integers or strings from stdin. When a program prompts for several numbers you can paste them or provide them inline. Example for insertion sort (`1.c`):

```zsh
# compile
gcc -Wall -Wextra -o 1 1.c
# run and provide input interactively
./1
# sample interactive input
# Enter n: 5
# Enter 5 numbers: 5 2 4 1 3

# alternatively provide input via a here-string:
echo -e "5\n5 2 4 1 3" | ./1
```

- Programs that need a matrix (TSP, Floyd–Warshall, Dijkstra example) will expect you to type the matrix row-by-row. If you want, I can add sample input files and tests.

Troubleshooting

- Permission denied when running `./1`: make the file executable (usually not needed for compiled binaries) with `chmod +x ./1`.
- Linker/compile errors: paste the error here and I'll fix the specific source or suggest compile flags.
- Using Xcode command line tools: if `gcc` is missing, run `xcode-select --install` to install the command-line tools.

Next steps I can do for you

- Add a `Makefile` so you can `make` or `make all`.
- Add example input files and a small `run_examples.sh` that shows sample runs for each program.
- Compile all files now and report any compile-time errors/warnings.

If you want me to compile them now, say "compile now" and I'll run the compiler for all 10 files and give a concise report of any failures or warnings.

Enjoy — tell me which next step you'd like.
