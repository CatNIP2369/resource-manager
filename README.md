"C++ Resource Manager"
This was only a learning project with goal of becoming better at cpp design.
here is the progress i made through different implementations of a resource manager for a game engine:
My original design: manager owns everything and automatically unloads unused resources giving a care-free exprience to the user.

What I learned: automatic lifetime tracking requires refrence counters or garbage collections, and scanning every resource every frame is not an efficient choice.

What I would choose as of now: explicit lifetime domains (a whole section of assets being linked to a sepcific task like a scene or level in a game) and resource groups, with automatic RAII inside those boundaries or custom handles using generation trackers and liveness state checkers. 

What I still don't know: custom handles(i don't know enough), resource streaming, GPU resource lifetime and more...
