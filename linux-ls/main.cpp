#include <iostream>
#include <dirent.h>
#include <stdlib.h>

#define GREEN  "\x1B[32m"
#define BLUE  "\x1B[34m"

using namespace std;

int main(int argc, char *argv[]) {
    try{
        DIR * pDir;

        if(argc > 1) {
            pDir = opendir(argv[1]);
        } else {
            pDir = opendir(".");
        }
        
        if(pDir == nullptr ) exit(EXIT_FAILURE);
        
        struct dirent * dir;
        while((dir = readdir(pDir)) != nullptr ) {
            cout << ((dir-> d_type == DT_DIR) ? GREEN : BLUE) << dir->d_name << endl;
        }
        closedir(pDir);
    } catch (int e) {
        cout << "error\n";
    }

    return 0;
}