# Stack_safe — safer singly-linked Stack implementation

What changed compared to the original `Stack` in the parent folder:

- Uses the list head as the top of the stack so `push`/`pop` are O(1).
- Proper null checks and throws `std::runtime_error` on underflow instead of undefined behavior.
- Destructor safely deletes all nodes and leaves no dangling pointers.
- Keeps the data structure as a singly linked list (no doubly-linked changes).

Files:
- `Node.hh`, `Node.cpp` — node definition.
- `Stack.hh`, `Stack.cpp` — safe stack implementation (head-based).
- `main.cpp` — example runner that prints popped elements.

Build (MSVC):

cl /EHsc main.cpp Stack.cpp Node.cpp

Or with a make/CMake setup — compile the three source files together.
