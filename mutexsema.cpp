#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <semaphore.h>
#include<bits/stdc++.h>
class RW {
public:
    sem_t readlock;
    sem_t writelock;
    static int readcount;

    RW() {
        sem_init(&readlock, 0, 1);
        sem_init(&writelock, 0, 1);
    }

    class Read {
    public:
        void operator()() {
            try {
                sem_wait(&rw.readlock);
                rw.readcount++;
                if (rw.readcount == 1) {
                    sem_wait(&rw.writelock);
                }
                sem_post(&rw.readlock);

                std::cout << "Thread " << std::this_thread::get_id() << " is reading." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2500));
                std::cout << "Thread " << std::this_thread::get_id() << " has finished reading." << std::endl;

                sem_wait(&rw.readlock);
                rw.readcount--;
                if (rw.readcount == 0) {
                    sem_post(&rw.writelock);
                }
                sem_post(&rw.readlock);
            } catch (std::exception &e) {
                std::cerr << e.what() << std::endl;
            }
        }
    };

    class Write {
    public:
        void operator()() {
            try {
                sem_wait(&rw.writelock);
                std::cout << "Thread " << std::this_thread::get_id() << " is writing." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                std::cout << "Thread " << std::this_thread::get_id() << " has finished writing." << std::endl;
                sem_post(&rw.writelock);
            } catch (std::exception &e) {
                std::cerr << e.what() << std::endl;
            }
        }
    };

    void fun() {
        Read read;
        Write write;

        std::cout << "Enter the number of read & write processes : ";
        int n;
        std::cin >> n;

        int seq[n];
        std::cout << "Enter the sequence: 1 for reading & 0 for writing." << std::endl;
        for (int i = 0; i < n; i++) {
            std::cin >> seq[i];
        }

        std::thread processes[n];

        for (int i = 0; i < n; i++) {
            if (seq[i] == 1) {
                processes[i] = std::thread(read);
                processes[i].detach();
            } else if (seq[i] == 0) {
                processes[i] = std::thread(write);
                processes[i].detach();
            }
        }

        // Allow some time for threads to complete
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    static RW rw; // Static instance for access in static methods
};

int RW::readcount = 0;
RW RW::rw;

int main() {
    RW rw;
    rw.fun();

    return 0;
}
