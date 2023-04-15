#define phi 1.6180339887498948

typedef struct _Euclid {
    int n;
    /**
     * @brief Quotients generated during a single run
     * of Euclid's algorithm.
     */
    int* quot;
    /**
     * @brief Remainders generated during a single run
     * of Euclid's algorithm.
     */
    int* rem;
} Euclid;

void swap(int*, int*);
/**
 * @brief Squares the argument of the function.
 * @return int - the square of the argument.
 */
int sq(int);
/**
 * @brief Checks if the argument is a perfect square and returns its natural root.
 * @return int - the square root of the argument, or -1 if it is not a perfect square.
 */
int natRoot(int);
/**
 * @brief Checks if the argument is a prime number.
 * @return int - 1 if the argument is prime, else 0.
 */
int isPrime(int);
/**
 * @brief Runs Euclid's algorithm on the given inputs.
 * @return Euclid* - contains the quotients and remainders.
 */
Euclid* euclid(int, int);
/**
 * @brief Finds the greatest common divisor of the two arguments.
 */
int gcd(int, int);