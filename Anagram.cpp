#include <iostream>
#include <fstream>
#include <istream>
#include <string>
using namespace std;

const int MAXRESULTS = 20;    // Max matches that can be found
const int MAXDICTWORDS = 30000; // Max words that can be read in


// Function Prototypes (Forward Declarations)
void findPermutationsR(const string& word, string perm, bool* used, const string dict[], int size, string results[], int& numMatches);
void generateNextChar(const string& word, string perm, bool* used, const string dict[], int size, string results[], int& numMatches, int index);


int helperLoadR(istream& dictfile, string dict[], int index) {
    if (index == MAXDICTWORDS)  // Reached max dictionary size
        return 0;
    if (getline(dictfile, dict[index]))
        return 1 + helperLoadR(dictfile, dict, index + 1);  // Recursively load next word
    else
        return 0;  // End of file reached
}


// Load dictionary words from file into dict array
int loadR(istream& dictfile, string dict[]) {
    return helperLoadR(dictfile, dict, 0);
}


// Recursive helper function to check if a permutation matches any dictionary word
int helperCheckDictR(const string& perm, const string dict[], int size, int index) {
    if (index == size)  // End of dictionary reached
        return 0;
    if (dict[index] == perm)  // Match found
        return 1;
    return helperCheckDictR(perm, dict, size, index + 1);  // Check next dictionary word
}


// Recursive function to check if a permutation is already in results to avoid duplicates
bool isDuplicateR(const string results[], int numMatches, const string& perm, int index) {
    if (index == numMatches)  // Reached end of current results
        return false;
    if (results[index] == perm)  // Duplicate found
        return true;
    return isDuplicateR(results, numMatches, perm, index + 1);  // Check next result
}


// Helper function to handle picking each character recursively
void generateNextChar(const string& word, string perm, bool used[], const string dict[], int size, string results[], int& numMatches, int index) {
    if (index == word.size())  // Reached end of word without adding character
        return;

    if (!used[index]) {  // Character not yet used in current perm
        used[index] = true;
        findPermutationsR(word, perm + word[index], used, dict, size, results, numMatches);
        used[index] = false;
    }
    generateNextChar(word, perm, used, dict, size, results, numMatches, index + 1);  // Recur for next character
}


// Recursive function to generate all permutations and check them against dict
void findPermutationsR(const string& word, string perm, bool used[], const string dict[], int size, string results[], int& numMatches) {
    if (perm.size() == word.size()) {
        // Check if perm is in dict and if it's not a duplicate in results
        if (helperCheckDictR(perm, dict, size, 0) && !isDuplicateR(results, numMatches, perm, 0)) {
            // Add perm to results if it's a match and not already there, up to MAXRESULTS
            if (numMatches < MAXRESULTS) {
                results[numMatches++] = perm;
            }
        }
    }
    else {
        // Recursively add each unused character in word to the permutation
        generateNextChar(word, perm, used, dict, size, results, numMatches, 0);
    }
}


// Find anagrams of word in dict and store them in results array
int anagramR(const string& word, const string dict[], int size, string results[]) {
    int numMatches = 0;
    bool* used = new bool[word.size()]();  // Dynamically allocate used array, initialized to false
    findPermutationsR(word, "", used, dict, size, results, numMatches);
    delete[] used;  // Clean up dynamic memory
    return numMatches;
}


// Recursive function to print the results array
void printR(const string results[], int size, int index = 0) {
    if (index == size)
        return;
    cout << "Matching word " << results[index] << endl;
    printR(results, size, index + 1);
}


int main()
{
    
    string results[MAXRESULTS];
    string dict[MAXDICTWORDS];
    ifstream dictfile;         // file containing the list of words
    int nwords;                // number of words read from dictionary
    string word;

    dictfile.open("words.txt");
    if (!dictfile) {
        cout << "File not found!" << endl;
        return (1);
    }

    nwords = loadR(dictfile, dict);

    cout << "Please enter a string for an anagram: ";
    cin >> word;

    int numMatches = anagramR(word, dict, nwords, results);
    if (!numMatches)
        cout << "No matches found" << endl;
    else
        printR(results, numMatches);

    //cout << nwords;
}

