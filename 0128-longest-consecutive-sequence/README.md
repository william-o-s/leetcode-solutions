# Overview

The basic solution stands; you can identify a "longest sequence" by finding
either its:

- start;
- or end

The start is the element without a left; 4, 5, 6 - there is no 3. The end is
the element without a right; 4, 5, 6 - there is no 7.

So long as you only visit each streak once by finding its start or end, the
algorithm should be linear. But that's not the case right now. The Neetcode
solution runs by finding the start and it's much faster. At the moment, I
tested each on an input with 50,000 elements and the Python is much faster

```
> time python3 sol.py
python3 sol.py  0.02s user 0.01s system 74% cpu 0.043 total
> time ./sol
./sol  0.03s user 0.00s system 93% cpu 0.032 total
```

## The `continue`

It might have been the `continue`.

```
> time ./sol
./sol  0.04s user 0.00s system 10% cpu 0.366 total
```

Originally it was:

```cpp
for (int n : nums) {
    if (!seen.contains(n + 1)) {
```

, but now it is

```cpp
for (int n : nums) {
    // n is not the end of a streak
    if (seen.contains(n + 1)) {
        continue;
    }
    // ...
```

## The Final Problem

There are test cases where there are many duplicated ends

```
1, 2, 3, ... 500, 500, 500
```

I think the Neetcode solution got lucky because there aren't duplicated starts.
This is easy enough to fix; just remember which ending points you saw before.
