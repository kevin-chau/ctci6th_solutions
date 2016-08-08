// rxc matrix m[r][c]

/* Base cases (no blocks):
	@ m[n][n-1] ---> move one step right
	@ m[n-1][n] ---> move one step down

	@ m[n-1][n-1] ----> down+right OR right+down   (2) ways

	@ m[x][c] -----> move down r-x times  (1) way
	@ m[r][x] -----> move right c-x times (1) way
/*

/*
No solution
[ 0 1 0 ]
[ 0 1 0 ]
[ 0 1 0 ]

2 solutions
[ 0 0 0 ]
[ 0 1 0 ]
[ 0 0 0 ]

6 solutions
[ 0 0 0 ]
[ 0 0 0 ]
[ 0 0 0 ]
*/


