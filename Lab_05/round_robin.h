#include <iostream>

using namespace std;

class Process {
public:
    int time;
    Process* next;
    Process* prev;

    Process(int t) {
        time = t;
        next = prev = NULL;
    }
};

class RoundRobinScheduler {
private:
    Process* head;
    int timeSlice;

public:
    RoundRobinScheduler(int ts) {
        head = NULL;
        timeSlice = ts;
    }

    int Insert_end(int time);
    int Execute();
    void Display();
};
