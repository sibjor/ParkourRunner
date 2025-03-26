#Notes of Parkour Runner

## Citations of Chandler Carruth
- Efficency prioritized over performance - as efficency structures the traffic of signals, already flowing (alike performace) - in the speed of light. 
- Algorithms have been argued by many professionals, stating promising results - if implemented by one who
can reflect, visualize and generally understands the mathematic pattern. Remember to study algorithms, buy a book recommended?
- Implementing multithreading... (lacking reference for now)
- Implementing of SIMD... (lacking reference for now)
- Reject "linked lists" data structures - if 36 billion instructions executed by a CPU - 
- Modern CPU:s have a lot of cache registrys - which are pretty small in relation of ... falling back to RAM, multiplying the time of a cycle by as much as 200. 
- Mainstream data structures such as "linked lists", each node separately allocated, who could be placed at any slot in RAM.
- Only use "linked lists" when you rarely traverse the lists - but frequently updating them.
- in C++, use ""std::vector" instead of "std::list"
- "std::map" - a linked list oriented as a binary tree - commented being terrible by some. Use a vector instead. 
- Adjacent space occupied by data in cache
- Chasing a pointer starts to make sense - having a large piece of data
- You cant pick algorithms in isolating - you should change both algorithms and data structures - having them work together
- A final mention - there a going to be cases almost proving the opposite of the (some not included) above an example citing that "Bubble Sort" is the fastest algorithm - but that's for small pieces of data.
- C++ does not give you performance - but gives the oppurtunity to control it.

## Citations of Mike Acton
- Mike Acton - in the time of his speech - were occupied, employed by "Insomniac Game"
- The organization stated above explained they were authors of almost every tool and utility of their games/software/engine - such as post fx, animation, visual effects etc...
- Game performance is discussed in micro-seconds
- Performance in general stated as critical importance
- In order to solve new problems, make space for them.
- Don't forget the "debugability" of your software!
- Main usage being C++ approximately 70%, complemented by C and - the language of preference - Assembly
- Defenently not using SDL - as its not solving the problem they face
- Software produces are run in a sandbox environment
- Not understanding the hardware, you can't reason about the cost of solving a problem
- Latency and throughput are only the same in sequental systems
- Reason must prevail
- Different hardware - different solution - differing entirely between architectures
- 