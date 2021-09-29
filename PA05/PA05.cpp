#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>

/**
 * Iterative binary search. Searches an array for a specified key, and returns
 * the number of comparisons required to either find the key, or to determine
 * that the key is not in the array.
 * 
 * @param pArr Pointer to the first element of the array to search. The array
 * is assumed to be sorted.
 * 
 * @param n Size of the array to search.
 * 
 * @param key Key value to search for.
 * 
 * @return The number of comparisons required to find key in the array, or to
 * determine that key is not in the array.
 */
int iterativeBinarySearch(int *pArr, int n, int key) {
    // stub; modify to implement an iterative binary search and return the 
    // number of comparisons made
    return 0;
}

/**
 * Recursive binary search. Searches an array for a specified key, and returns
 * the number of comparisons required to either find the key, or to determine
 * that the key is not in the array.
 * 
 * @param pArr Pointer to the first element of the array to search. The array
 * is assumed to be sorted.
 * 
 * @param n Size of the array to search.
 * 
 * @param key Key value to search for.
 * 
 * @param lo Leftmost index of the portion of the array to search.
 * 
 * @param hi Rightmost index of the portion of the array to search. 
 * 
 * @return The number of comparisons required to find key in the array, or to
 * determine that key is not in the array.
 */
int recursiveBinarySearch(int *pArr, int n, int key, int lo, int hi) {
    // stub; modify to implement an recursive binary search and return the 
    // number of comparisons made
    return 0;
}

int main() {
    using namespace std;

    // Mersenne Twister high-quality PRNG
    mt19937 prng(time(0));
    uniform_int_distribution<int> dist(0, RAND_MAX);

    // file output
    ofstream outFile("results.dat");

    int size = 64;
    int power = 6;

    while(power < 27) {
        // allocate random array to search
        int* pArr = new int[size];

        for(int i = 0; i < size; i++) {
            pArr[i] = dist(prng);
        }

        // sort the array
        sort(pArr, pArr + size);

        // pick a key to search for
        int key = dist(prng);

        // search and count
        long numISearches = 0u;
        long numRSearches = 0u;
        for(int i = 0; i < 100; i++) {
            numISearches += iterativeBinarySearch(pArr, size, key);
            numRSearches += recursiveBinarySearch(pArr, size, key, 0, size - 1);
        }

        // calculate averages
        double avgISearches = numISearches / 100.0;
        double avgRSearches = numRSearches / 100.0;

        // output results to console and file
        cout << size << "\t" << avgISearches << "\t" << avgRSearches << 
            "\t" << log2(size) << endl;
        outFile << size << "\t" << avgISearches << "\t" << avgRSearches << 
            "\t" << log2(size) << endl;

        delete [] pArr;
        size *= 2;
        power++;
    } // while

    // close output file
    outFile.close();

    return EXIT_SUCCESS;
}