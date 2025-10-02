Don't be afraid to duplicate data.  
Here, the packet is duplicated across the queue and the lookup set.  
Don't copy and paste lines of code - or if you do, go through every letter e.g.

```cpp
auto lo = lower_bound(tss.begin(), tss.end(), startTime);
// this has been wrongly copy and pasted as startTime when it should be endTime.
auto hi = upper_bound(tss.begin(), tss.end(), startTime);
```
