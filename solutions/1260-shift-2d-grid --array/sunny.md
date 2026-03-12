Need to be good at converting 2D coordinates into 1D:

```
if there are r rows and c cols:

(i, j) in 1D becomes: i * c + j

for t in 2D:

row = t // cols (ie. what's the nearest number of whole columns)
col = t %  cols (ie. after traversing those whole rows, what is the column offset?)
```

.

