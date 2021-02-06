#include "RandomNumberGenerator.hpp"
#include <random>

using namespace std;

// function for generating random number
int generateRandomNumber(int range1, int range2)
{
    random_device randomDevice;
    mt19937 mt(randomDevice()); // seed the mt19937 generator using randomDevice
    uniform_int_distribution<int> randomID(range1, range2);
    return randomID(mt); // return random number from range1 to range 2
}