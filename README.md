# Cash Sorter

Cash Sorter is a simple desktop application written in C using GTK4. It solves the **coin change problem** using a greedy algorithm.

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

- GCC or another C compiler
- GTK4 development libraries

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

```bash
./cash_sorter
```

---

## Run without compiling

You can check the releases to find bin file but I would recommend to compile it yourself for better compatibility.

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
