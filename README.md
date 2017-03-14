FILLIT
========

Fillit is a recursive backtracking that fits a set of Tetriminos in the smallest possible square without rotatiting the Tetriminos. 

Here is an example of valid map of Tetriminos (maximum of 26 blocks) which the code fits in the following square:

```
....
.##.
.##.
....

...#
...#
...#
...#

....
..##
.##.
....

....
..#.
.##.
.#..

.###
...#
....
....

##..
.#..
.#..
....

....
..##
.##.
....

.#..
.##.
..#.
....

....
###.
.#..
....
```

Solution (each individual tetriminos renamed starting from A):
```
AAB.CCD
AABCCDD
FFB..D.
.FBEEE.
HF.GGE.
HHGGIII
.H...I.
```
How to use:

    git clone https://github.com/JibranKalia/fillit.git
    choose a map from examples folder
    ./fillit examples/ok_09_block

Features
--------

- Implements error checking to detect invalid tetriminons. 

Official Team
--------
This project was developed jointly by Jibran Kalia https://github.com/JibranKalia and Giacomo Guiulfo @giacomoguiulfo.

