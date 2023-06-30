#include "Single_Linked_List.h"
#include "Single_Linked_List.cpp"
#include "menu.h"
using namespace std;

int main() {
    // Creates an instance of the linked list
    Single_Linked_List<int> my_list;

    // Do while loop with switch statement to allow the user to call the functions until they quit
    char choice;
    do {
        printMenu();
        cin >> choice;
        cout << endl;

        switch (choice) {
            // Takes in the users value and pushes it to the front
            case 'a': {
                int item;
                cout << "Enter the item to push front: ";
                cin >> item;
                my_list.push_front(item);
                cout << "Item pushed to the front." << endl;
                break;
            }
            // Takes in the users value and pushes it to the back
            case 'b': {
                int item;
                cout << "Enter the item to push back: ";
                cin >> item;
                my_list.push_back(item);
                cout << "Item pushed to the back." << endl;
                break;
            }
            // pops the item in the front
            case 'c':
                my_list.pop_front();
                cout << "Front item popped." << endl;
                break;
            // pops the item in the back
            case 'd':
                my_list.pop_back();
                cout << "Back item popped." << endl;
                break;
            // returns the item at the front of the list or couts list is empty
            case 'e':
                if (!my_list.empty())
                    cout << "Front item: " << my_list.front() << endl;
                else
                    cout << "List is empty." << endl;
                break;
            // returns the item at the end of the list or couts list is empty
            case 'f':
                if (!my_list.empty())
                    cout << "Back item: " << my_list.back() << endl;
                else
                    cout << "List is empty." << endl;
                break;
            // returns bool if list is empty of not
            case 'g':
                cout << (my_list.empty() ? "List is empty." : "List is not empty.") << endl;
                break;
            // inserts an item at the user specified index
            case 'h': {
                int item, index;
                cout << "Enter the item to insert: ";
                cin >> item;
                cout << "Enter the index to insert at: ";
                cin >> index;
                my_list.insert(index, item);
                cout << "Item inserted at index " << index << endl;
                break;
            }
            // removes an item at the user specified index
            case 'i': {
                size_t index;
                cout << "Enter the index to remove: ";
                cin >> index;
                if (my_list.remove(index))
                    cout << "Item removed from index " << index << endl;
                else
                    cout << "Invalid index." << endl;
                break;
            }
            // finds the index of a user specified item in the list or couts not found
            case 'j': {
                int item;
                cout << "Enter the item to find: ";
                cin >> item;
                size_t position = my_list.find(item);
                if (position != my_list.size())
                    cout << "Item " << item << " found at position " << position << endl;
                else
                    cout << "Item " << item << " not found in the list." << endl;
                break;
            }
            // prints the contents of the list
            case 'k': {
                my_list.printList();
                break;
            }
            // quits the do while loop and ends the program
            case 'q':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    } while (choice != 'q');

    return 0;

}
