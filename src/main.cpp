#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
using namespace std;

int main() {
    string line, repo;
    const char* env_var = "GIT_COMMITTER_DATE";
    
    cin >> repo;
    repo += ".txt";

    cout << "REPO NAME: " << repo << endl;

    ofstream file(repo, ios::app);
    
    if (file.is_open()) {
        while (cin >> line) {
            string weekday, month, day, time, year, zone, tmp;
            string commit_time;

            if (line == "Date:") {
                cin >> weekday >> month >> day >> time >> year >> zone;

                commit_time = weekday + " " + month + " " + day + " " + time + " " + year + " " + zone;

                if (setenv(env_var, commit_time.c_str(), 1) != 0) {
                    std::cerr << "Error setting environment variable.\n";
                    return 1;
                }

                file << repo << " - " << commit_time << endl;
                string gitAdd = "git add " + repo; 
                string commit = "git commit -m \"" + repo + " " + commit_time + "\" --date \"" + commit_time + "\"";
                
                system(gitAdd.c_str());
                system(commit.c_str());
            }
        }
    }

    return 0;
}