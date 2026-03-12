The hint was necessary: "try spot the pattern after n >= 7".  
The pattern is not obvious, nor does it seem like it would naturally extend.  
```
7 : 3 * 2 * 2 = 12
8 : 3 * 3 * 2 = 18
9 : 4 * 3 * 3 = 36
```

The pattern is though after n >= 7, that the numbers are always:

```
answer(i) = 3 * answer(i - 3)
```

.
