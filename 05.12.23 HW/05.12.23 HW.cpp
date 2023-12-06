#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


//Task 1
class Count {
    int min;
    int max;
    int now;


// Мы вроде не учили this на прошлой паре, но я учил его и знаю как использовать, поэтому использовал ниже.
public:
    Count(int min, int max) {
        this->min = min;
        this->max = max;
        this->now = min;
    }

    void setMin(int min) {
        this->min = min;
    }

    void setMax(int max) {
        this->max = max;
    }

    void Increase() {
        now++;
        if (now > max) {
            now = min;
        }
    }

    int Get() {
        return now;
    }

    void Running(int iterations) {
        for (int i = 0; i < iterations; i++) {
            Increase();
            cout << "Current value: " << Get() << endl;
        }
    }
};


//Task 2
class Elevator {
    int Floor;
    int minFloor;
    int maxFloor;

public:
    Elevator(int minFloor, int maxFloor) {
        this->minFloor = minFloor;
        this->maxFloor = maxFloor;
        this->Floor = minFloor;
    }

    void MinFloor(int minFloor) {
        this->minFloor = minFloor;
    }

    void MaxFloor(int maxFloor) {
        this->maxFloor = maxFloor;
    }

    void RandomFloor() {
        srand(time(0));
        int randomFloor = rand() % (maxFloor - minFloor + 1) + minFloor;
        moveFloor(randomFloor);
    }

    void moveFloor(int floor) {
        if (floor >= minFloor && floor <= maxFloor) {
            Floor = floor;
            cout << "Elevator moved on floor: " << Floor << endl;
        }
        else {
            cout << "impermissible floor: " << floor << Floor << endl;
        }
    }

    int GetFloor() {
        return Floor;
    }
};


int main()
{
    //Task 1
    /*Count count(0, 100);
    count.Running(101);
    return 0;*/

    //Task 2
    Elevator elevator(1, 10);
    elevator.RandomFloor();
    return 0;
}
