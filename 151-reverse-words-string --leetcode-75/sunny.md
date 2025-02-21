Doing this problem in constant memory and quadratic time is doeable, but extremely finicky with a lot of room for error.  

You can follow a basic algorithm like so:

```
input:
i _ _ _ a m _ _ n e d _ s t a r k

answer:
s t a r k _ n e d _ a m _ i

1) reverse all letters

k r a t s _ d e n _ _ m a _ _ _ i

2) remove consecutive spaces
k r a t s _ d e n _ m a _ i

3) iteratively reverse all words
s t a r k _ d e n _ m a _ i
s t a r k _ n e d _ m a _ i
s t a r k _ n e d _ a m _ i
```

.  

This one just comes down to pain since it's quite hard to compress the whitespaces together - without dynamic memory you need to iteratively shift the array down, as you handle a whitespace group:

```

this:
h e y _ _ _ _ s o u l _ _ s i s t e r

becomes:
h e y _ s o u l _ _ s i s t e r

```

.
