#include <iostream>
/*******************************************************************
* getInfo *
* Gets and validates lottery info from the user and places it in   *
* reference parameters referencing variables in the main function. *
*******************************************************************/
void getInfo(int & pickFrom, int & numPicks) {
    std::cout << "How many balls (1-12) are in the pool to pick from? ";
    std::cin >> pickFrom;
    if (pickFrom > 12 || pickFrom < 1) {
        std::cout << "Input Error! There must be between 1 and 12 balls.\n";
        std::cin.clear();
        std::cout << "How many balls (1-12) are in the pool to pick from? ";
        std::cin >> pickFrom;
    }
    if (std::cin.fail()) {
        std::cout << "Input Error!\n";
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "How many balls (1-7) will be drawn? ";
        std::cin >> pickFrom;
    }
    std::cout << "How many balls (1-7) will be drawn? ";
    std::cin >> numPicks;

    if (std::cin.fail()) {
        std::cout << "Input Error!\n";
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "How many balls (1-7) will be drawn? ";
        std::cin >> numPicks;
    }
    if (numPicks > 7 || numPicks < 1) {
        std::cout << "Input Error!\n";
        std::cin.clear();
        std::cout << "How many balls (1-7) will be drawn? ";
        std::cin >> numPicks;
    }
}

/******************************************************************
* computeWays                                                     *
* Computes and returns the number of different possible sets      *
* of k numbers that can be chosen from a set of n numbers.        *
* The formula for this is     k!(n- k)!                           *
*                             --------                            *
*                                 n!                              *
*******************************************************************/
// Note that the computation is done in a way that does not require
// multiplying two factorials together. This is done to prevent any
// intermediate result becoming so large that it causes overflow.
double factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial((n - 1));
    }
}
double computeWays(int n, int k) {
    double ways = (factorial(k) * factorial((n - k))) / factorial(n);
    return ways;
}