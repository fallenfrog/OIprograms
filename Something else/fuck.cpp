#include <random>
#include <iostream>

using namespace std;

int main()
{
//    random_device rd;   // non-deterministic generator
    mt19937 gen(random_device{}());  // to seed mersenne twister.
    uniform_int_distribution<> dist(1,20); // distribute results between 1 and 6 inclusive.

    for (int i = 0; i < 5; ++i) {
        cout << dist(gen) << " "; // pass the generator to the distribution.
    }
    cout << endl;
}

