#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <sys/stat.h>

using namespace std;

int main() {
    string path;
    cout << "Add directory: "; getline(cin, path);
    
    vector<string> allEntry;
    // Loop through user-provided directory
    for (const auto& entry : filesystem::directory_iterator(path))
        // Store all files/directory found in that directory (user-provided directory)
        allEntry.insert(allEntry.end(), entry.path().string());

    // Loop through all files/folders (from user-provided directory)
    vector<string> finalPath;
    vector<string> allDir;
    int index = 0;
    if (allEntry.empty() == 0) {
        for (vector<string>::iterator i = allEntry.begin(); i < allEntry.end(); i++) {
            filesystem::path tmp = allEntry[index];
            error_code error_code;
            // Store all .mp3 to finalPath and all folders to allEntry (by updating it)
            if (filesystem::is_directory(tmp, error_code)) {
                allDir.insert(allDir.end(), allEntry[index]);
            }

            if (tmp.extension() == ".mp3") {
                finalPath.insert(finalPath.end(), allEntry[index]);
                allEntry.erase(i);
            }

            index++; // Index = vector iterator
        }
    }



    // Test
    cout << "allEntry: " << endl;
    int index2 = 0;
    for (vector<string>::iterator i = allEntry.begin(); i < allEntry.end(); i++) {
        cout << allEntry[index2] << endl;
        index2++;
    }

    cout << "allDir: " << endl;
    for (int i = 0; i < allDir.size(); i++) {
        cout << allDir[i] << endl;
    }

    cout << endl << "finalPath: " << endl;

    for (int i = 0; i < finalPath.size(); i++) {
        cout << finalPath[i] << endl;
    }
}