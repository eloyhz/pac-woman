# Building Games with SFML

## Section 3. Shaping the game

### The game loop

#### The main loop

#### Handling events

### The game states

1. Diverting the game flow

States
- No coin (N)
- Get ready (R)
- Playing (P)
- Won (W)
- Lost (L)

Transitions
(N) -> insert coin -> (R)
(R) -> press start -> (P)
(P) -> all dots eaten -> (W)
(P) -> run out of life -> (L)
(W) -> a few seconds later -> (R)
(L) -> insert coin -> (R)
(L) -> no coin inserted after 10 sec (N)

2. The FSM pattern

### Modeling entities

### Animating characters