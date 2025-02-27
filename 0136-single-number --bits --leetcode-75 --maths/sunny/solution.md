This question relies on knowing the properties of XOR.  
XOR is the only "tricky" operator of the bitwise operators, so as a hunch it is worth enumerating through its properties:
1. A ^ 0 = A
2. A ^ A = 0
3. A ^ B ^ C = A ^ C ^ B (can move around the elements)

So thus if it's known that all but one of the numbers are repeated, you can write them out like this:

```
A ^ B ^ C ^ D ^ C ^ B ^ A
A ^ A ^ B ^ B ^ C ^ C ^ D
0 ^ 0 ^ 0 ^ D
...
0 ^ D
D
```

so the final answer of the entire XOR'd array is the non-repeated number.
