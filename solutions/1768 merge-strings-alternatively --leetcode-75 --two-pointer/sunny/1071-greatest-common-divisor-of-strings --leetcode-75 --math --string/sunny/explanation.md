Observations:
1. a divisor must be a prefix of the string;
2. a divisor's length must divide the length of the string eg: a string with len 6 can only have divisors of len 1, 2, 3 and 6.

Hence for a given string, you can find all prefixes with the lengths of each factor for both strings and the answer will be the longest string they have in common eg:

```
AAAAAA -> [A, AA, AAA, AAAAAA]
AAAA   -> [A, AA, AAAA]
              --
              answer
```

.

There is no shortcut to check whether a prefix is a factor, you have to just cop a linear time to check because of things like this:

```
check AA is factor:

AAAAAA ... AB
```

and the editorial also does this.

