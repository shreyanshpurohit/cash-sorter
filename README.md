# Cash Sorter

Cash Sorter is a simple C program that solves the **coin change problem** using a greedy algorithm.

It takes an amount in cents and calculates the minimum number of:
- Quarters (25¢)
- Dimes (10¢)
- Nickels (5¢)
- Cents (1¢)

---

## Project Structure

```text
cash-sorter/
├── cash_sorter.c
├── Makefile
├── README.md
```

---

## Requirements

Make sure you have a C compiler installed, such as GCC.

You can check if it is installed by running:

```bash
gcc --version
```

---

## How to Compile

1. Open a terminal in the project folder.

2. Run:

```bash
make cash_sorter
```

This will compile `cash_sorter.c` and create an executable file called `cash_sorter`.

---

## How to Run

After compiling, run:

Linux/macOS:

```bash
./cash_sorter
```

Windows:

```bash
cash_sorter.exe
```

---

## Example

Input:

```text
Change owed: 41
```

Output:

```text
Quarters: 1
Dimes: 1
Nickels: 1
Cents: 1
Total coins: 4
```
