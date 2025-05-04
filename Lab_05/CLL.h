#include <iostream>

using namespace std;
class node
{
    public:
        int data;
        node* prev;
        node* next;
        node()
        {
            next=prev=NULL;
        }
};
class List
{
    private:
        node* head;
    public:
        List()
        {
            head = NULL;
        }
        int Insert_beginning(int num);
        int Insert_pos(int num, int pos);
        int Insert_end(int num);
        int Delete_begining();
        int Delete_position(int pos);
        int Delete_end();
        void Display();
        int Search(int num);
        int count();
};