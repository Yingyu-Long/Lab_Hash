/**
 * @file word_counter.cpp
 * Implementation of the WordFreq class.
 *
 * @author Chase Geigle
 * @date Spring 2011
 * @date Spring 2012
 */
#include "word_counter.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::pair;
using std::string;
using std::vector;

template <template <class K, class V> class Dict>
WordFreq<Dict>::WordFreq(const string& filename) : dict(256) {
    ifstream input(filename);
    string line;
    while (getline(input, line)) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
            dict[word] = dict.find(word) + 1;
        }
    }
}

template <template <class K, class V> class Dict>
vector<pair<string, int>> WordFreq<Dict>::getWords(int threshold) {
    vector<pair<string, int>> ret;
        for (const auto& kv : dict) {
            if (kv.second >= threshold) {
                ret.push_back(kv);
            }
        }


    (void)threshold;  // prevent warnings... When you implement this function, remove this line.

    return ret;
}
