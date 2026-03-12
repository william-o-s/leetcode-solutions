Can do this in linear time with a large constant factor.  
Essentially you can iterate through all digits of the number and check if they are one using shifting:

```
3=011

   ^ to check digit 2 (ie. the binary "tens")
3>>2
 =001
 &001
 ----
    1

    therefore, add 1 to the total number of ones
```

. This is apparently Kernighan's algorithm.
