The naive solution is to remove on paranthesis at a time, check if the remaining string is balanced and then recurse on the substring.
This is too slow.

```
()())()

backtrack on
X())()
(X())()
()X))()
...
```
