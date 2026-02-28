# Overview

The basic solution stands; you can identify a "longest sequence" by finding
either its:

- start;
- or end

The start is the element without a left; 4, 5, 6 - there is no 3. The end is
the element without a right; 4, 5, 6 - there is no 7.

So long as you only visit each streak once by finding its start or end, the
algorithm should be linear. But that's not the case right now. The Neetcode
solution runs by finding the start and it's much faster.
