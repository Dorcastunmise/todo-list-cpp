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
};

// TodoItem::TodoItem(/* args */)
// {
// }

// TodoItem::~TodoItem()
// {
// }
int main() {
    string version = "v0.2.0";
    list<TodoItem> todoItems;   //creating the list "TodoItem"
    list<TodoItem>::iterator it; //In order to loop through existing items athe list object has an iterator. Naming it "it"
    
    
    srand(time(NULL)); //NEW SEED FOR EACH ITEM
    
    todoItems.clear();          //to start with fresh list
    
    TodoItem test;
    test.create("this is a test"); //new_description = "this is a test"
    todoItems.push_back(test);      //adding it to the todoItems list

    while (1)                   //to create an infinite loop
    {
        system("cls");  //to get a fresh view, it clears the screen between each loop
        cout << "Todo List Maker - " << version << endl;

        //to start from first item and continue till it gets to the end
        for(it = todoItems.begin(); it != todoItems.end(); it++) {
            // to print out each todoItem
            cout << it -> getId() << " | " << it -> getDescription() << " | " << it -> isCompleted() << endl;
        }
        break;
    }

    return 0;
}