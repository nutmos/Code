#include <iostream>
#include <cstdlib>

using namespace std;

int n;

struct fileConsistOf {
    int numberOfIncludeFile;
    int *includeFile;
};

int checkInclude(int markFile[], int fileN, struct fileConsistOf file[]) {
    //cout << "In Function" << endl;
    //cout << "fileN = " << fileN << endl;
    //cout << "numberOfIncludeFile = " << file[fileN-1].numberOfIncludeFile << endl;
    int checkReturn = 0;
    markFile[fileN-1] = 1;
    if (file[fileN-1].numberOfIncludeFile == 0) {
        return 0;
    }
    else {
        for (register int i = 0; i < file[fileN-1].numberOfIncludeFile; i++) {
            //cout << "In Loop" << endl;
            if (checkReturn == 1) break;
            if (markFile[(file[fileN-1].includeFile[i])-1] == 1) {
                //cout << "In If Return 1" << endl;
                return 1;
            }
            else {
                //cout << "In Else Recursion" << endl;
                checkReturn = checkInclude(markFile, file[fileN-1].includeFile[i], file);
                //cout << "checkReturn " << checkReturn << endl;
            }
        }
    }
    //cout << endl;
    if (checkReturn == 1) return 1;
    else return 0;
}

int main() {
    cin >> n;
    struct fileConsistOf file[n];
    for (register int i = 0; i < n; i++) {
        cin >> file[i].numberOfIncludeFile;
        file[i].includeFile = (int*)malloc(file[i].numberOfIncludeFile * sizeof(int));
        for (register int j = 0; j < file[i].numberOfIncludeFile; j++) {
            cin >> file[i].includeFile[j];
        }
        //cout << file[i].numberOfIncludeFile << endl;
    }
    for (register int i = 0; i < n; i++) {
        //cout << "file " << i+1 << endl;
        int markFile[n];
        for (register int j = 0; j < n; j++) {
            markFile[j] = 0;
        }
        int checkReturn = checkInclude(markFile, i+1, file);
        if (checkReturn == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
        //cout << endl << endl;
    }
}