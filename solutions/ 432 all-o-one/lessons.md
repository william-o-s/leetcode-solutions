Try to write out algorithms in terms of APIs rather than diving in.  
For linked lists you have to cop it and do edge cases and then main logic.

- empty
- singleton
- head
- tail
- middle

Make sure to plan in code expected behaviour - this should be in the form of a comment.  
I got stuck because it is the expected behaviour to delete a node with frequency zero after decrementation and I forgot to do this.

For linked list insertions it's really good to make little diagrams.

```
insertRight(spot, node) when we are doing a middle insertion

(spot)-> <-(node)-> <-(spot.next)
```
