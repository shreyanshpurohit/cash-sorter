# Cash Sorter

A simple C program that solves the **coin change problem** by finding the minimum number of coins needed for a given amount of change.

It uses a greedy algorithm to break the amount into:
- Quarters (25¢)
- Dimes (10¢)
- Nickels (5¢)
- Pennies (1¢)

## Compile

```bash
gcc cash.c -o cash_sorter
```

## Run

Linux/macOS:

```bash
./cash_sorter
```

Windows:

```bash
cash_sorter.exe
```

## Example

Input:

```text
41
```

Output:

```text
Quarters: 1
Dimes: 1
Nickels: 1
Pennies: 1
Total coins: 4
```
