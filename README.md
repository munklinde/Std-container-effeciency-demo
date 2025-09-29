# Demo

Purpose is to observe how containers from sdt library behaves when adding objects.
Type being allocated is instrumentd to output on creation, copying, destruction etc.
Test is spinning up a container, adding large data object. It easy to observe how the containers allocates, copy and move objects as number of elements grow.

Interesting to see how move semantics change the game.

