#include <iostream>
#include <string>
#include <cstdlib>
#include <filesystem>
using namespace std;

string get_home() {
    const char* home_ptr = getenv("HOME");
    if (home_ptr == nullptr ) {
        cerr << "Error: HOME environment variable not set." << endl;
        exit(1);
    }
    else {
        string home = home_ptr;
        return home;
    }
}

int main() {
    string home = get_home();
    string var_local = home + "/.local/share/applications/";
    string var_system = "/usr/share/applications/";
    for (const auto& entry : filesystem::directory_iterator(var_local)) {
        cout << entry.path() << endl;
    }
    for (const auto& entry : filesystem::directory_iterator(var_system)) {
        cout << entry.path() << " (" << entry.path().extension() << ")" << endl;
    }

    return 0;
}
