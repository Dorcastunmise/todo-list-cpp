#include <iostream>
#include <list>
#include <ctime>
using namespace std;

class TodoItem
{
private:
    /* data */
    int id;
    string description;
    bool completed;

public:
    TodoItem(): id(0), description(""), completed(false) {};
    ~TodoItem() = default;

    bool create(string new_description) {
        //Generating a random integer between 1 and 100 to generate id
        id = rand() % 100 + 1;
        description = new_description;
        return true;
    }


    int getId() { return id;}
    string getDescription() { return description;}
    bool isCompleted() { return completed; }
    void setCompleted(bool val) { completed = val;}
};

// TodoItem::TodoItem(/* args */)
// {
// }

// TodoItem::~TodoItem()
// {
// }
int main() {
    char input_option;
    int input_id;
    string input_description;
    string version = "v0.2.0";
    list<TodoItem> todoItems;   //creating the list "TodoItem"
    list<TodoItem>::iterator it; //In order to loop through existing items athe list object has an iterator. Naming it "it"
    
    
    srand(time(NULL)); //NEW SEED FOR EACH ITEM
    
    todoItems.clear();          //to start with fresh list
    
    // TodoItem test;
    // test.create("this is a test"); //new_description = "this is a test"
    // todoItems.push_back(test);      //adding it to the todoItems list

    while (1)                   //to create an infinite loop
    {
        system("cls");  //to get a fresh view, it clears the screen between each loop
        cout << "Todo List Maker - " << version << endl;

        //to start from first item and continue till it gets to the end
        for(it = todoItems.begin(); it != todoItems.end(); it++) {
            //to indicate the end of the list is reached
            string completed = it -> isCompleted() ? "done" : "not done";
            // to print out each todoItem
            cout << it -> getId() << " | " << it -> getDescription() << " | " << completed << endl;
        }

        //if todoItems is Empty
        if(todoItems.empty()) {
            cout << "Dear user, kindly type in your first todo" << endl;
        }
        // options for a user to choose from
        cout << "(a)dd a new Todo" << endl;
        cout << "(C)complete a Todo" << endl;
        cout << "(q)uit" << endl << endl;
        cout << "choice: " << endl;
        //input from user
        cin >> input_option;
        //output after user selects an option
        if(input_option == 'q') {
            cout << "Have a wonderful day...best regards";
                    break;
        } 
        else if(input_option == 'a') {
            cout << "Add a new description" << endl;
            cin.clear();    //clears input buffer inorder to start with a fresh buffer
            cin.ignore();   //to ignore 1st return
            getline(cin, input_description);    //to capture description
            cin >> input_description;

            TodoItem newItem;
            newItem.create(input_description);
            todoItems.push_back(newItem);
        }
        else if(input_option == 'c') {
            cout << "Indicate the id number of the completed todo item" << endl;
            cin >> input_id;

            //To iterate and find an item in the standard list
            for(it = todoItems.begin(); it != todoItems.end(); it++) {
                if (input_id == it -> getId()) {
                    it -> setCompleted(true);
                    break;
                }
            }
        }

    }

    return 0;
}