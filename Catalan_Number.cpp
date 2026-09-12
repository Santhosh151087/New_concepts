// Catalan numbers are a sequence of natural numbers that appear in various counting problems, often related to recursive structures.
// They are named after the French-Belgian mathematician Eugène Charles Catalan.

//   Examples : 
// Catalan Number for n is equal to the number of expressions containing n pairs of parenthesis that are correctly matched, i.e., 
//   for each of the n(' there exist n ')' on there right and vice versa. 
//   The first few Catalan numbers for n = 0, 1, 2, 3, 4, 5… are: 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, ...  so on.
//   n= 3 (()()), (())(), ()(()), ()()() ans = 5

//   The number of distinct binary trees with n internal nodes.
// Application: In data structures like AVL trees, Red-Black trees, and splay trees.

// Mathematical Formula :  (2n)!
//                       ------------
//                       (n+1)! * n!

// here is the recursive code for catalan number
// C++ program to find nth catalan number

#include <iostream>
using namespace std;

int findCatalan(int n)
{

    // Base case
    if (n <= 1)
        return 1;

    // catalan(n) is sum of
    // catalan(i)*catalan(n-i-1)
    int res = 0;
    for (int i = 0; i < n; i++)
        res += findCatalan(i) * findCatalan(n - i - 1);

    return res;
}


int main()
{
    int n = 3;
    int res = findCatalan(n);
    cout << res;
    return 0;
}
