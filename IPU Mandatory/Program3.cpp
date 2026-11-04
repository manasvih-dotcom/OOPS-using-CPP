/*PROBLEM STATEMENT
  A system has current CPU and memory utilization.
  If CPU utilization is below memory utilization, a CPU-intensive task may be started. 
  If memory utilization is below CPU utilization, a memory-intensive task may be started.
  Write a program using a friend function to determine which type of task should be started based on the current CPU
  and memory utilization (that are part of CPU and Memory classes respectively)*/

#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

class MEM;

class CPU {
private:
    float cpu_utilization;

public:
    CPU(float cpu) {
        cpu_utilization = cpu;
    }

    friend void task(CPU, MEM);
};

class MEM {
private:
    float mem_utilization;

public:
    MEM(float mem) {
        mem_utilization = mem;
    }

    friend void task(CPU, MEM);
};

void task(CPU c, MEM m) {
    if (c.cpu_utilization < m.mem_utilization) {
        cout << "CPU intensive task started" << endl;
    }
    else if (c.cpu_utilization > m.mem_utilization) {
        cout << "Memory intensive task started" << endl;
    }
    else {
        cout << "CPU and Memory intensive task are equivalent" << endl;
    }
}

int main() {
    float cpu, mem;

    cout << "Enter CPU utilization: " << endl;
    cin >> cpu;

    cout << "Enter MEM utilization: " << endl;
    cin >> mem;

    CPU c(cpu);
    MEM m(mem);

    task(c, m);

    return 0;
}
