#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> documents = {
    "Kunal Parkar is an Engineering Student.",
    "This search engine model is developed by kunal.",
    "Birth date of kunal is 03 may 2003.",
    "Kunal has knowledge of HTML, CSS, javascript, c++.",
    "This is the link to Kunal's Github account: https://github.com/Kun0311al",
    "Ananya Shetty is an Engineering Student.",
    "This search engine model is developed by ananya.",
    "Birth date of ananya is 10 april 2003.",
    "Ananya have the experience of digital marketing.",
    "Vijay is an Engineering Student.",
    "Vijay have knowledge about c++.",
    "Birth date of vijay is 16 april 2010."
};

vector<string> search(string query) {
    vector<string> results;
    transform(query.begin(),query.end(),query.begin(),::toupper);
    for (string document : documents) {
        string document2 = document;
        transform(document2.begin(), document2.end(), document2.begin(), ::toupper);
        if (document2.find(query) != string::npos) {
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