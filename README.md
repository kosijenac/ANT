# ANT
Implementations of some number theory algorithms, primarily related to continued fractions.

## Quad SCF
The program `quad_scf.c` takes three command line arguments: $s_0$, $d$ and $t_0$. They represent a
quadratic irrational of the form $$\frac{s_0+\sqrt{d}}{t_0}.$$ The program then outputs a continued
fraction (either finite or periodic) equal to this quadratic irrational. The case when $d$ is a perfect
square is also handled. The period of a continued fraction is represented using simple parentheses.
E.g. `[2; 3, (4, 5, 6)]` is the same continued fraction as $[2; 3, \overline{4, 5, 6}]$.

## Square PSCF
The program `square_pscf.c` takes one command line argument, which is the length of a period that a
continued fraction may have (any positive integer). The program then checks every non-perfect square 
number $d$ to check if the period of $\sqrt{d}$ as a continued fraction matches the input, until it 
finds the smallest such number, at which point it halts the output.

### PERIOD_LIMIT
This number determines the maximum length of a continued fraction and may be set as needed. If this 
number is too high, more memory will have to be allocated for the program to run.