# Strategy

For this question you need a data structure that gives you better-than-linear lookup of the minimum in a suffix of an array.  
You need to support:

1. lookup of min(i) to n
2. removal of this min

For just 1. you can use a prefix minimum array.  
However to support 2. you need to use a range tree, or use a new technique called [square root decomposition](https://cp-algorithms.com/data_structures/sqrt_decomposition.html).

Break up the array into `sqrt(n)` buckets and record the minimum in each bucket.  
Now you can achieve 1. and 2. in `sqrt(n)` time.

# Implementation

It is a bit of a pain to work with the buckets.  
You need `ceil(n/sqrt(n))` buckets and this is annoying to compute because `ceil` in C++ requires a floating-point type.  
If you can update the original values in-place then you don't need a copy of the original array, but it is safest to make a copy.
