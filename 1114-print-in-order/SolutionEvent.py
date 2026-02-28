from threading import Event

class Foo:
    def __init__(self):
        self.events = (Event(), Event())

    def first(self, printFirst: 'Callable[[], None]') -> None:

        # printFirst() outputs "first". Do not change or remove this line.
        printFirst()
        self.events[0].set()


    def second(self, printSecond: 'Callable[[], None]') -> None:

        # printSecond() outputs "second". Do not change or remove this line.
        self.events[0].wait()
        printSecond()
        self.events[1].set()


    def third(self, printThird: 'Callable[[], None]') -> None:

        # printThird() outputs "third". Do not change or remove this line.
        self.events[1].wait()
        printThird()
