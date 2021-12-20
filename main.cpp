#include "person.h"
#include "Binary_tree.h"

int main() {
    int s1 = 0;
    cout << endl << "Select an action:" << endl << "1 - random person " << endl << "2 - person from keybord" << endl;
    cin >> s1;
    switch (s1) {
        case 1: {
            person *data = rand_person();
            int s2 = 0;
            while (s2 != 4) {
                cout << endl << "1 - ravnomernoe razbienie" << endl << "2 - neravnomernoe razb" << endl << "3 - Print person" << endl
                     << "4 - exit" << endl;
                cin >> s2;
                switch (s2) {
                    case 1: {
                        razb *a = ravnrazb(data);
                        Binary_tree<Key> b(a);
                        gist(&b);
                        break;
                    }
                    case 2: {
                        razb *a = neravnrazb(data);
                        Binary_tree<Key> b(a);
                        gist(&b);
                        break;
                    }
                    case 3: {
                        print_person(data);
                        break;
                    }
                    case 4: {
                        break;
                    }

                }
            }
            break;
        }
            case 2 : {
                person *data = console_person();
                int s2 = 0;
                while (s2 != 3) {
                    cout << endl << "1 - ravnomernoe razbienie" << endl << "2 - neravnomernoe razb" << endl << "3 - Print person" << endl
                         << "4 - exit" << endl;
                    cin >> s2;
                    switch (s2) {
                        case 1: {
                            razb *a = ravnrazb(data);
                            Binary_tree<Key> b(a);
                            gist(&b);
                            break;
                        }
                        case 2: {
                            razb *a = neravnrazb(data);
                            Binary_tree<Key> b(a);
                            gist(&b);
                            break;
                        }
                        case 3: {
                            break;
                        }

                    }
                    break;
                }
                break;
            }
    }
    return 0;
}