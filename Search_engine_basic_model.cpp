#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> documents = {
    "kunal Parkar is an Engineering Student.",
    "This search engine model is developed by kunal.",
    "Birth date of kunal is 03 may 2003.",
    "ananya Shetty is an Engineering Student.",
    "This search engine model is developed by ananya.",
    "Birth date of ananya is 10 april 2003.",
    "vijay is an Engineering Student.",
    "vijay have knowledge about c++.",
    "Birth date of vijay is 16 april 2010."
};

vector<string> search(string query) {
    vector<string> results;
    for (string document : documents) {
        if (document.find(query) != string::npos) {
            results.push_back(document);
        }
    }
    return results;
}

int main() {
    string query;
    while (true)
    {
        cout << "Enter a search query: ";
        getline(cin, query);
        vector<string> results = search(query);
        if (results.empty()) {
            cout << "No results found." << endl;
        } else {
            cout << "Results:" << endl;
            for (string result : results) {
                cout << "- " << result << endl;
            }
        }
    }
    
    return 0;
}