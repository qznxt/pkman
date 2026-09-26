#include <iostream>
#include <string>
#include <cstdlib>
#include <filesystem>

bool snap ;
bool flatpak ;
bool wine ;

using namespace std;
string pm;

void pmquery(){
    snap = system("which snap > /dev/null 2>&1") == 0;
    flatpak = system("which flatpak > /dev/null 2>&1") == 0;
    wine = system("which wine > /dev/null 2>&1") == 0;

}


string get_home() {
    const char* home_ptr = getenv("HOME");
    if (home_ptr == nullptr ) {
        cerr << "Error: HOME environment variable not set." << endl;
       return "0";
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
    pmquery();
    cout << "hi :> !" << " following packmans are installed "<< endl;
    if (snap) {
        cout << "Snap is installed." << endl;
    } else {
        cout << "Snap is not installed." << endl;
    }
    if (flatpak) {
        cout << "Flatpak is installed." << endl;
    } else {
        cout << "Flatpak is not installed." << endl;
    }
    if (wine) {
        cout << "Wine is installed." << endl;
    } else {
        cout << "Wine is not installed." << endl;}
    return 0;
}
