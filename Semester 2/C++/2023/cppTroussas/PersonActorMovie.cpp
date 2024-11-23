#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Person {
protected:
    std::string name;
    int age;

public:
    Person( const std::string& n, int a) : name(n), age(a) {}

    virtual void printInfo() const {
        std::cout << "Name: " << name << " Age: " << age << std::endl;
    }
};

class Actor : public Person {

private:
    int salary;

public:
    Actor( const std::string& name, int age, int salary) : Person(name, age), salary(salary) {}

    int getSalary() const {
        return salary;
    }

    void printInfo() const {
        Person::printInfo();
        std::cout << "Salary: " << salary << std::endl;
    }


};

// struct ActorSalaryComparator {
//     bool operator()(const Actor* a, const Actor* b) const {
//         return a->getSalary() < b->getSalary();
//     }
// };

class Movie {
private:
    std::string title;
    std::vector<Actor*> actors;

public:
    Movie(const std::string& title) : title(title) {}

    void addActor(Actor* actor) {
        actors.push_back(actor);
    }

    void sortActorsBySalary() {
        // std::sort(actors.begin(), actors.end(), ActorSalaryComparator());
        std::sort(actors.begin(), actors.end(), 
        [] (Actor* a, Actor* b) -> bool 
        { 
            return a->getSalary() < b->getSalary();
        }); 
        }

    void printCast() const {
        std::cout << "The cast of " << title << std::endl;
        for (std::vector<Actor*>::const_iterator it = actors.begin(); it != actors.end(); ++it) {
            (*it)->printInfo();
        }

        // for (Actor* actor : actors){
        //     actor->printInfo();          //? Εναλλακτικές
        // }

        // for (int i = 0; i<actors.size(); i++){
        //     actors[i]->printInfo();
        // }
    }


};

int main() {
    Actor* actor1 = new Actor("Leo", 40, 3000);
    Actor* actor2 = new Actor("Antita", 35, 11000);
    Actor* actor3 = new Actor("Aris", 20, 6000);


    Movie* movie1 = new Movie("titanic");
    movie1->addActor(actor1);
    movie1->addActor(actor2);
    movie1->addActor(actor3);

    movie1->sortActorsBySalary();
    movie1->printCast();

    // Cleanup
    delete actor1;
    delete actor2;
    delete actor3;
    delete movie1;

    return 0;
}