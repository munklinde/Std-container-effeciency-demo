# move semantics demo

Purpose is to observe how containers from std library behaves when adding objects.
Type being allocated is instrumentd to output on creation, copying, destruction etc.
Test is spinning up a container, adding large data object. It easy to observe how the containers allocates, copies and moves objects as number of elements in the container grows.

Interesting to see how move semantics change the game.

