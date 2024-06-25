#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

using namespace std;

// Find all .mp3 files in a directory (and all of it's subdirectory)
vector<string> findMp3(string directory) {
    vector<string> allEntry;
    vector<string> allMp3;
    for (const auto& dirEntry : filesystem::recursive_directory_iterator(directory)) {
        allEntry.insert(allEntry.end(), dirEntry.path().string());
    }

    int index = 0;
    for (vector<string>::iterator i = allEntry.begin(); i < allEntry.end(); i++) {
            filesystem::path tmp = allEntry[index];
            error_code error_code;
            // Store all .mp3 to allMp3
            if (tmp.extension() == ".mp3") {
                allMp3.insert(allMp3.end(), allEntry[index]);
            }

            index++; // Index = vector iterator
        }
    return allMp3;
}

int main() {
    string dir;
    getline(cin, dir);

    vector<string> allMp3 = findMp3(dir);

    for (int i = 0; i < allMp3.size(); i++) {
        cout << allMp3[i] << endl;
    }
}