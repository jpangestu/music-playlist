#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> allEntry;
    vector<string> allMp3;
    string dir;
    cout << "Insert directory: "; getline(cin, dir);
    for (const auto& dirEntry : filesystem::recursive_directory_iterator(dir)) {
        allEntry.insert(allEntry.end(), dirEntry.path().string());
    }

    // for (int i = 0; i < allEntry.size(); i++) {
    //     cout << allEntry[i] << endl;
    // }

    // cout << endl <<endl;

    int index = 0;
    for (vector<string>::iterator i = allEntry.begin(); i != allEntry.end(); ++i) {
            filesystem::path tmp = allEntry[index];
            error_code error_code;
            // Store all .mp3 to allMp3
            if (tmp.extension() == ".mp3") {
                allMp3.insert(allMp3.end(), allEntry[index]);
            }

            index++; // Index = vector iterator
        }
    
    // cout << "allMp3 size: " << allMp3.size() << endl;
    for (int i = 0; i < allMp3.size(); i++) {
        cout << allMp3[i] << endl;
    }
}