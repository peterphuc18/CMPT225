# CMPT225
In this assignment you are to analyze the running times of seven functions. 

Please read the requirements carefully, paying attention to the names and input and output requirements of the class and its methods. We will be testing your class in our test program, so if you do not follow the requirements the test program will not compile, and will not be marked. As usual refer to the General Requirements page.

Requirements
For each of the functions described in questions 1 to 7 you are to:

Modify the function to count the number of operations performed when the function executes in the worst case. See the section on counting operations below for more detail.
Determine a detailed cost function for the function. This function should be written in the form wnx + yn + z where w, x, y and z are real numbers and n is a variable referring to the size of the function's input. If necessary, you should adapt this format to include other terms such as log2(n).
Identify all of the barometer operations for the function.
Write the O notation running time.
There is a detailed example after the last question.

Counting Operations
Augment each function with an integer reference parameter to maintain a count of the number of operations. This reference parameter should always be the last parameter in the function's parameter list. When counting operations follow these rules - make sure you read them carefully (and follow them).
An executable statement (a line of code that ends in a semi-colon) or a condition (that controls an if statement or while loop) or a loop increment statement (like i++ in the third field of many for loops) counts as one (1) operation regardless of its complexity.  This includes input or output instructions.  Statements that include one or more function calls will count as more than one operation, as detailed by rule 2.
Examples: x = 4; cout << "Hello world!\n"; int w = x + y + z; (x < a && x < b || x < c) all count as single operations.
If a statement includes one or more function calls their operation count should be totaled.  The operation counts for library functions will be provided to you. Operations to function call arguments should not be counted.
Example:  If the statement was x = foo(y) + bar(z); and foo() cost 10 operations while bar() cost 5 operations, the total for this line is 1 + 10 + 5 = 16.  The 1 is base cost for any line of code (as per rule 1).
Example:  If the line was foo(bar(x)); it would not cost the extra 1. 
Example: If the statement was x = foo(y+1), and foo() cost 10 operations the total cost is 1 + 10 = 11. Do not include an additional operation for adding 1 to y in the call to foo. 
One execution of an if statement or while/for loop condition counts as one operation. Make sure that you count conditions that result in false as well as true – so don't forget to include the terminating comparison for while/for loops.
Return statements should not be included in the operation count, unless the return statement includes other operations, in which case those operations are counted as describe above.
Example: return x. The cost is 0.
Example: return x + y + z. The cost is 1.
Question 1
This function prints the Cartesian product of its input array with itself.

// PARAM: arr is array to print the Cartesian product of, n is size of arr
void cartesianProduct(int arr[], int n)
{
       int i = 0;
       while (i < n) {
              int j = 0;
              while (j < n) {
                     cout << "{" << arr[i] << "," << arr[j] << "}";
                     j++;  
                     cout << " ";
              }

              cout << endl;
              i++;
       }
}
Question 2
This function prints a triangle of numbers (which doesn't look very pretty if the numbers have more than one digit).

void triangle(int x)
{
       int i = 0;
       while (i < x) {
              int j = 0;
              while (j <= i) {
                     cout << j << " ";
                     j++;
              }

              cout << endl;
              i++;
       }

       while (i > 0) {
              i--;
              int j = 0;
              while (j <= i) {
                     cout << j << " ";
                     j++;
              }
              cout << endl;
       }
}
Question 3
This function returns an array in dynamic memory that represents the matrix that is the result of multiplying the matrix (array) parameter by itself.

// PRE: m represents a square matrix of size rows * rows
// PARAM: rows represents the number of both rows and columns
// POST: Returns a pointer to an array (matrix) of the same size as m
// NOTE: values are indexed r0c0,r0c1,…,r0cn-1,r1c0,…
int* matrixSelfMultiply(int* m, int rows)
{
       // Create result array
       int columns = rows;
       int* result = new int[rows * columns];
       int r = 0;

       while (r < rows) {
              int c = 0;
              while (c < columns) { //columns = rows
                     int next = 0;
                     int iNext = 0;

                     while (iNext < rows) {
                           next += m[rcIndex(r, iNext, columns)] * m[rcIndex(iNext, c, columns)];
                           iNext++;
                     }

                     result[rcIndex(r, c, columns)] = next;
                     c++;
              }
              r++;
       }
       return result;
}
// Returns the index of a 1d array representing a matrix
// given row (r) and column (c) values
int rcIndex(int r, int c, int columns)
{
       return r * columns + c;
}
Notes
The input size is the number of rows of the matrix
Note that the rcIndex function only contains a return statement
Question 4
This function is a recursive version of selection sort.

// PARAM: arr is array to be sorted, n is size of array, i should initially = 0
void ssort(int arr[], int n, int i)
{
       if (i < n-1) {
              // Find and swap smallest remaining
              int next = i + 1;
              int smallest = i;

              while (next < n) {
                     if (arr[next] < arr[smallest]) {
                          smallest = next;
                     }
                     next++;
              }

              // Swap i with smallest
              int temp = arr[i];
              arr[i] = arr[smallest];
              arr[smallest] = temp;
              ssort(arr, n, i + 1);
       }
}
Question 5
This function prints a pattern.

// PRE: n is a power of 2 greater than zero.
// PRE: Initial call should be to i = 0
// e.g. pattern(8, 0)
void pattern(int n, int i)
{
       if (n > 0) {
              pattern(n/2, i);
              // Print i spaces
              cout << string(i, ' ');

              // A loop to print n asterisks, each one followed by a space
              int ast = 0;
              while (ast < n) {
                     cout << "* ";
                     ast++;
              }

              cout << endl;
              i += n;
              pattern(n / 2, i);
       }
}
Notes
Assume that the string constructor (string(i, ' ')) has an operation count of 3.
Question 6
This function is a less than optimal implementation of linear search.

// Desc: Linear search.  Reports position if found, else -1
// Post:  Elements unchanged
int lsearch(int arr[], unsigned int len, int target) {
    if (len == 0) return -1;
    if (arr[0] == target) return 0;
    if (lsearch(arr+1, len-1, target) == -1) {
        return -1;
    } else {
        return 1 + lsearch(arr+1, len-1, target);
    }
} // lsearch
Notes
If you are unable to find a precise, closed form, cost function then give a good upper bound.
Question 7
This function performs exponentiation.

unsigned pow(unsigned int base, unsigned int exp) {
    unsigned int ret = 1;
    while (exp > 0) {
        if (exp & 1) {
            ret *= base;
        }
        exp >>= 1;
        base = base * base;
    }
    return ret;
} // pow
Notes
The operation count is related to the binary representation of the exponent. If you are unable to find a precise, closed form, cost function then give a good upper bound.
The & (bitwise AND) and >>= (right shift assignment) are bitwise operators. If you are unfamiliar with these please look them up (Google).
Example
This function computes the sum of squares of its array parameter.

int sumSquares(int arr[], int n)
{
       int i = 0;
       int sum = 0;
       while (i < n) {
              sum += arr[i] * arr[i];
              i++;
       }

       return sum;
}
The function returns an integer (the sum of the squares of its integer array parameter) so an integer reference parameter will be used to access the operations count. The amended function is shown below and would be the answer to part A.

int sumSquares(int arr[], int n, int & ops)
{
       int i = 0;
       int sum = 0;
       ops = 2; //initializes cost for the first two statements
       while (i < n) {
              sum += arr[i] * arr[i]; //counts as one operation
              i++;
              ops += 3; //while comparison and above two lines
       }
       ops++; //terminating while comparison
       return sum; //not included in count
}
Note that the while comparison is executed once for each time the loop body is executed (so its count is inside the loop) and once when the comparison is false and the loop ends (the count for which is outside the loop).

The cost function for this function is t(sumSquares) = 3n + 3, which would be the answer to part B. The loop runs n times, performing 3 operations in each iteration. The function performs three operations outside the loop. Note that your cost function should match the number of operations counted – and that this is quite simple to test.

void sumSquareTest()
{
       cout << "SUM OF SQUARES TEST" << endl;
       int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
       int n = 10;
       int cost = 0;
       cout << "sum of squares = " << sumSquares(arr, n, cost);
       cout << endl << "cost = " << cost;
       cout << endl << "t(sumSquares): 3n+3 = " << 3 * n + 3;
       cout << endl << "--------------" << endl << endl;
}
I would strongly recommend writing similar tests to the above, but they should not be included in your submission.

The function's barometer operations are the while loop comparison, the assignment to sum and the increment of the loop control variable (i). That is, one of the two operations inside the loop or the loop control statement. 

The function's O notation running time is O(n).
