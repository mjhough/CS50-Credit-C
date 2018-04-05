# CS50-Credit-C
A credit card checker in C for Harvard's CS50 course.

This was done with pure maths to check the positioning of numbers. Instead, square brackets could have been used on the string to find the position.

The program uses Luhn's Algorithm to validate card numbers.

### Instructions to run:
1. Compile the code by running the following command: `clang -fsanitize=signed-integer-overflow -fsanitize=undefined -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wshadow credit.c -lcrypt -lcs50 -lm -o credit.

2. Run the compiled code by typing ./credit, asssuming you are in the same directory as the compiled file.
