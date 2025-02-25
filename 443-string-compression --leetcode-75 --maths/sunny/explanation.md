This is a tedious problem due to memory constraints.  
Its main difficulty comes from:
1. needing to overwrite an existing buffer
2. the complexity of writing out numbers digit by digit
3. a linked-list like algorithm that requires thought about code after a loop runs.

To solve this problem perform a linear sweep and write to the left-hand side of the buffer after you finish processing a group:

```
start:
    a a a b c
    ^ (next spot to write at)

first group:
    a a a b c
          | ('a' * 3)

now write to buffer:
    a 3 a b c
        ^ (this is now the next number to write at)
```

.  

To manually deconstruct a number into its bases perform:

```
number:
    2468 

thousands:
    2468 / 1000
    2

hundreds:
    2468 % 100
     468 / 100
     4

tens:
    2468 % 100
      68 / 10
      6

ones:
    2468 % 10
       8
```

.
