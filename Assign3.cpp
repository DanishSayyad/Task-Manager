#include<iostream>
#include<string>
using namespace std;


struct node {
    int time,Priority;
    string Task_name;
    node *next;
};


class to_do_list{
    node *head ,*tail;
    public:
    to_do_list(){
        head = NULL;
        tail = NULL;
    }
   
    void display();
    void add_task(int Priority, int time, string Task_name);
    void remove_task();
    void task_measure();
    void taskmeasure_priority();
    void update_task(string key);
    void search_task(string key);  
};
   
   
int main() {
to_do_list mylist;
 int choice;
 do{
     cout << "\n--- To-Do List Menu ---\n";
        cout << "1. Add Task\n";
        cout << "2. Remove Task\n";
        cout << "3. Display Tasks\n";
        cout << "4. Task Measure (Total Tasks and Time)\n";
        cout << "5. Task Measure on Priority\n";
     cout << "6. Update task\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;


     switch(choice){
         case 1:{
             int prio, time;
                string name;
                cout << "Enter task name: ";
                cin >> name;
                cout << "Enter priority: ";
                cin >> prio;
                cout << "Enter time (in mins): ";
                cin >> time;
                mylist.add_task(prio, time, name);
                break;
          }
            case 2: {
                mylist.remove_task();
                break;
            }
            case 3:
                mylist.display();
                break;
            case 4:
                mylist.task_measure();
                break;


            case 5: {
                mylist.taskmeasure_priority();
                break;
            }


         case 6: {
             string key;
             cout << "Enter the task name to change";
             cin >> key;
             mylist.update_task(key);
         }
            case 0:
                cout << "Exiting...\n";
                break;


            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);
}                                                


    mylist.add_task(4, 25, "Playingchess");
    mylist.add_task(5, 30, "Playingcricket");
    mylist.add_task(3, 70, "CompleteAssignment");
    mylist.add_task(5, 70, "Playingkabbadi");
    mylist.add_task(5, 60, "Playingkabbadi");
    mylist.add_task(4, 30, "Playingkabbadi");
    mylist.add_task(4, 40, "Playingkabbadi");
    mylist.add_task(3, 60, "Playingkabbadi");
    mylist.add_task(2, 30, "Playingkabbadi");
    mylist.add_task(1, 10, "Playingkabbadi");
    mylist.display();
//  mylist.remove_task();
//  mylist.display();
    mylist.task_measure();
    mylist.taskmeasure_priority();
//  mylist.update_task("Playingchess");
    mylist.search_task("Playingcricket");
   
   cout << "THanks for using.\n";
   
    return 0;
}


void to_do_list :: display(){
    if(!head){
        cout << "No task added yet\n";
        return ;
    }
    node *p = head;
    while(p)
    {
        cout << p->Priority << " " << p->Task_name << " " << p->time << " minute\n";
        p= p -> next;
    }
    return;
}


void to_do_list :: add_task(int Priority, int time, string Task_name){
    node *nn = new node;
    if(!nn) return ;
    nn -> Priority = Priority;
    nn -> Task_name = Task_name;
    nn -> time = time;
   
    //node *ptr = head;
    if (!head) {
        head = nn;
        nn -> next = NULL;
        tail = nn;
        return;
    }
    else if(Priority == 5){
        nn -> next = head;
        head = nn;
    }
    else if(Priority == 1){
        nn -> next = NULL;
        tail -> next = nn;
        tail = nn;
    }  
    else {
        node *p = head;
        while (p->next && p->next->Priority >= Priority)
            p = p->next;


        nn->next = p->next;
        p->next = nn;
    if (nn->next == NULL)
        tail = nn;
}}


/*void to_do_list :: remove_task(){
    node *ptr1;
    ptr1 = head;
    if(!head){
        cout << "No task to removed";
    }


    node *ptr2;
    ptr2 = NULL;
    node *temp = head->next;
    node *temp_prev = head;
   
    while(temp){
        if(ptr1->Priority == temp->Priority){
            if(temp->time < ptr1->time){
                ptr2 = ptr1;
                ptr1 = temp;
                temp_prev=temp;
            }
        temp = temp->next;
        }
    }
    delete ptr1;
    cout << "Task deleted succefully\n";
    }*/


    void to_do_list::remove_task() {
    node *ptr1;
    ptr1 = head;


    if (!head) {
        cout << "No task to remove\n";
        return;
    }


    node *ptr2 = NULL;        
    node *temp = head->next;    
    node *temp_prev = head;    


    while (temp) {
        if (temp->Priority > ptr1->Priority ||
           (temp->Priority == ptr1->Priority && temp->time < ptr1->time)) {
            ptr1 = temp;      
            ptr2 = temp_prev;  
        }
        temp_prev = temp;      
        temp = temp->next;    
    }


    if (ptr2) {
        ptr2->next = ptr1->next;
    } else {
        head = ptr1->next;      
    }


    delete ptr1;
    cout << "Task deleted successfully\n";
}


    void to_do_list :: task_measure(){
        node *ptr = head;
         if (!head) {
        cout << "No task to measure\n";
        return;
        }
        int count=0,time=0;
        while(ptr != NULL){
            count += 1;
            time += ptr->time;
            ptr = ptr-> next;
        }
        cout << "Total Pending task are : " << count << " and total esimated Time is " << time << " minute\n";
    }
    void to_do_list :: taskmeasure_priority(){
        node *p = head;
        int c=0,c1=0,c2=0,c3=0,c4=0;
        if(!head){
            cout << "No task to count";
        }
        while(p){
            if(p->Priority == 5){
                c++;
            }
            else if(p->Priority == 4){
                c1++;
            }
            else if(p->Priority == 3){
                c2++;
            }
            else if(p->Priority == 2){
                c3++;
            }
            else if(p->Priority == 1){
                c4++;
            }
            p = p->next;
        }
        cout << "\n5: "<<c<<", 4:"<<c1<<" ,3:"<<c2<<" ,2:"<<c3<<" ,1:"<<c4<<"\n";
    }
    void to_do_list :: update_task(string key){
        node *p = head;
        if(!head){
            cout << "No task to update";
        }
    while (p) {
        if (p->Task_name == key) {
            cout << "Enter new task name: ";
            getline(cin, p->Task_name);
            cout << "Enter new priority: ";
            cin >> p->Priority;
            cout << "Enter new time: ";
            cin >> p->time;
            cout << "Update successful!\n";
            return;
        }
        p = p->next;
    }


    cout << "Task not found.\n";
}
    void to_do_list :: search_task(string key){
        node *p = head;
        int index=0;
        if(!p){
            cout << "No task added";
            return;
        }
        while(p){
            if(p->Task_name == key){
                cout << "Task " << key << " Found at index : " << index+1;
                return ;
            }
            p = p->next;
            index+=1;
        }
        cout << "Task not found!";
    }
    /*if( head->Task_name==key && head->next==NULL){
        delete ptr1;
    */
    /*  Delete specific node *ptr2;
    ptr2 = NULL;
    while(ptr1){
        if(ptr1->Task_name == key){
            break;
        }
    ptr2 = ptr1;
    ptr1 = ptr1->next;}
    ptr2->next = ptr1->next;
    delete ptr1;*/


    
    /*else {
        node *ptr = head;
        while(ptr){
            if(ptr->next->Priority >= Priority)
                ptr->next;
                //ptr->next=nn;
        }
        nn->next= ptr->next;
        ptr->next = nn;
    }*/
    /*else {
            tail->next = nn;
            tail = nn;
        return;
        }*/
    /*while(ptr->next) {
        ptr = ptr -> next;
        //ptr -> next = nn;
    }
    ptr->next = nn;*/





