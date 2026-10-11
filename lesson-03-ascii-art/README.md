# Lesson 3: ASCII Art

## Goals

By the end of this lesson you will be able to:

1. Store numbers in **variables** and read them from the keyboard with `cin`.
2. Repeat code with a `for` loop.
3. Use **nested loops** to work in rows and columns.
4. Use `if` / `else` to decide what character to print.
5. Plan a drawing by finding the pattern *before* writing code.

ASCII art is pictures made from text characters. Drawing shapes is a great
way to learn loops because you can *see* when your logic is wrong.

---

## Part 1 - New tools

### Variables and input

```cpp
#include <iostream>

int main() {
    int size;                          // make a box named size that holds a whole number
    std::cout << "Enter a size: ";
    std::cin >> size;                  // read a number from the keyboard into size
    std::cout << "You typed " << size << "\n";
    return 0;
}
```

### Typing less: `using namespace std`

Writing `std::` everywhere gets tiring. In small programs you can add this line
after the `#include`s:

```cpp
using namespace std;
```

Then `std::cout` can be written as just `cout`. The starter files in this
lesson do this.

### The `for` loop

```cpp
for (int i = 0; i < 5; i++) {
    cout << "*";
}
cout << "\n";
```

Output: `*****`

Read it as: *"Start `i` at 0. While `i` is less than 5, run the body, then add
1 to `i`."* The body runs for `i` = 0, 1, 2, 3, 4 - that's 5 times.

### Nested loops: rows and columns

A loop inside a loop. The **outer** loop picks the row; the **inner** loop
prints each character in that row.

```cpp
for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 4; col++) {
        cout << "#";
    }
    cout << "\n";       // end of the row - move down a line
}
```

Output:

```
####
####
####
```

### Making decisions with `if`

```cpp
if (col == 0) {
    cout << "|";
} else {
    cout << " ";
}
```

Comparison operators: `==` equal, `!=` not equal, `<`, `<=`, `>`, `>=`.
Combine with `&&` (and) and `||` (or). The `%` operator gives the remainder of
a division - `n % 2 == 0` means *n is even*.

> **Watch out:** `=` *assigns* a value; `==` *compares*. Writing
> `if (col = 0)` is a classic bug - and your `-Wall` flag will warn you.

---

## Part 2 - How to solve a pattern problem

Don't start by typing code. Start with a table. For example, a right-aligned
triangle of size 4:

```
   *
  **
 ***
****
```

| row | spaces | stars |
|-----|--------|-------|
| 0   | 3      | 1     |
| 1   | 2      | 2     |
| 2   | 1      | 3     |
| 3   | 0      | 4     |

Now find the formula in terms of `row` and `size` (here 4):
**spaces = size - 1 - row**, **stars = row + 1**. Once you have the formulas,
the code is just two inner loops - one for spaces, one for stars.

> **Tip:** Hard to see trailing spaces? Temporarily print `.` instead of
> `' '` while debugging.

---

## Part 3 - Problems

Each problem has a starter file in [`starter/`](starter/). Compile and run
them the same way as Lesson 1:

```
$ g++ -std=c++20 -Wall -Wextra -g 01_picture.cpp -o 01_picture
$ ./01_picture
```

Commit each problem to your `intro-cpp` repo as you finish it (see Lesson 2).
In all examples below the user typed the number after the prompt.

### Problem 1 - Your own picture *(no loops)*

Using only `cout`, print a picture of your choice - an animal, a house, your
initials. It must be at least 5 lines tall. Example:

```
 /\_/\
( o.o )
 > ^ <
/|   |\
(_|_|_)
```

Remember: `\\` prints a backslash and `\"` prints a double quote.

### Problem 2 - A line

Read a number `n` and print `n` stars on one line.

```
Length: 7
*******
```

### Problem 3 - Filled rectangle

Read a width and a height and print a filled rectangle.

```
Width: 6
Height: 3
######
######
######
```

### Problem 4 - Right triangle

Read a size and print a left-aligned right triangle.

```
Size: 4
*
**
***
****
```

**Variation:** print it upside down.

### Problem 5 - Hollow box

Read a width and height and print just the border.

```
Width: 6
Height: 4
+----+
|    |
|    |
+----+
```

*Hint:* for each position, ask "am I on the top or bottom row? the left or
right column? a corner?" and print the matching character.

### Problem 6 - Right-aligned triangle

```
Size: 4
   *
  **
 ***
****
```

Use the table from Part 2.

### Problem 7 - Pyramid

```
Size: 4
   *
  ***
 *****
*******
```

Make your own row / spaces / stars table first. How many stars on row `r`?

### Problem 8 - Checkerboard

Read a size and print a checkerboard of `#` and space characters.

```
Size: 5
# # #
 # #
# # #
 # #
# # #
```

*Hint:* the character depends on whether `row + col` is even or odd.

### Problem 9 - Diamond

Read an **odd** size (the width of the middle row). If the user enters an even
number, print an error message and stop.

```
Size: 7
   *
  ***
 *****
*******
 *****
  ***
   *
```

*Hint:* it's a pyramid followed by an upside-down pyramid that's one row
shorter.

### Problem 10 - Challenge: Holiday tree

Read a height and print a tree: a pyramid of `*` with a `|` trunk centered
below it, and a `^` star on top.

```
Height: 5
    ^
    *
   ***
  *****
 *******
*********
    |
    |
```

**Extra challenge ideas** (pick any):

- Make the trunk height scale with the tree height.
- Randomly replace some `*` with `o` ornaments (look up `rand()`).
- Draw a big letter `X` of any size.
- Print an arrow pointing right: `>` made of stars.

---

## Checklist before you submit

- [ ] Every program compiles with **no warnings** using `-Wall -Wextra`.
- [ ] You tested each program with at least three sizes, including `1`.
- [ ] Each problem is committed separately with a clear message.
- [ ] You pushed to GitHub and can see your files there.

## Vocabulary

- **Variable** - a named storage location that holds a value.
- **`int`** - a whole-number type.
- **Loop** - code that repeats.
- **Nested loop** - a loop inside another loop.
- **Condition** - an expression that is `true` or `false`, used by `if`.
- **Off-by-one error** - looping one time too many or too few. You *will* make
  these; the fix is to check your table.
