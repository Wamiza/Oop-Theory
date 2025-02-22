#include <iostream>
#include <string>
using namespace std;

 // 24K-0010 WAMIZA NOMAN

class Mentor;
class Sport;
class Skill;

class Student {
public:
    string name;
    int studentId;
    int age;
    string sportsInterests[5];
    int interestCount;
    Mentor* mentorAssigned;

    Student(string n, int id, int a, string sport) {
        name = n;
        studentId = id;
        age = a;
        sportsInterests[0] = sport;
        interestCount = 1;
        mentorAssigned = nullptr;
    }

    void registerForMentorship(Mentor &m);
    void viewMentorDetails();
    void updateSportsInterest(Sport &s);
};

class Mentor {
public:
    string name;
    int mentorId;
    string sportsExpertise[5];
    int expertiseCount;
    int maxLearners;
    Student* assignedLearners[5];
    int assignedCount;

    Mentor(string n, int id, string sport, int max) {
        name = n;
        mentorId = id;
        sportsExpertise[0] = sport;
        expertiseCount = 1;
        maxLearners = max;
        assignedCount = 0;
    }

    void assignLearner(Student &s);
    void removeLearner(Student &s);
    void viewLearners();
    void provideGuidance();
};

class Sport {
public:
    string name;
    int sportId;
    string description;
    string requiredSkills[5];
    int skillCount;

    Sport(string n, int id, string desc, string skill) {
        name = n;
        sportId = id;
        description = desc;
        requiredSkills[0] = skill;
        skillCount = 1;
    }

    void addSkill(Skill &s);
    void removeSkill(Skill &s);
};

class Skill {
public:
    string skillName;
    int skillId;
    string description;

    Skill(string n, int id, string desc) {
        skillName = n;
        skillId = id;
        description = desc;
    }

    void showSkillDetails();
    void updateSkillDescription(string newDescription);
};

void Student::registerForMentorship(Mentor &m) {
    m.assignLearner(*this);
}

void Student::viewMentorDetails() {
    if (mentorAssigned) {
        cout << "Mentor Name: " << mentorAssigned->name << endl;
    } 
	else {
        cout << "No mentor assigned." << endl;
    }
}

void Student::updateSportsInterest(Sport &s) {
    if (interestCount < 5) {
        sportsInterests[interestCount++] = s.name;
        cout << "Sport interest updated to: " << s.name << endl;
    }
}

void Mentor::assignLearner(Student &s) {
    if (assignedCount < maxLearners) {
        assignedLearners[assignedCount++] = &s;
        s.mentorAssigned = this;
        cout << s.name << " assigned to " << name << endl;
    } else {
        cout << "Mentor limit exceeded." << endl;
    }
}

void Mentor::removeLearner(Student &s) {
    for (int i = 0; i < assignedCount; i++) {
        if (assignedLearners[i] == &s) {
            for (int j = i; j < assignedCount - 1; j++) {
                assignedLearners[j] = assignedLearners[j + 1];
            }
            assignedCount--;
            s.mentorAssigned = nullptr;
            cout << s.name << "removed from mentorship." << endl;
            return;
        }
    }
    cout << "Student not found under this mentor." << endl;
}

void Mentor::viewLearners() {
    cout << "Mentor: " << name << endl << "Assigned Learners: " << assignedCount << endl;
    for (int i = 0; i < assignedCount; i++) {
        cout << " - " << assignedLearners[i]->name << endl;
    }
}

void Mentor::provideGuidance() {
    cout << "GUIDE : Practice wisely, not just hard." << endl;
}

void Sport::addSkill(Skill &s) {
    if (skillCount < 5) {
        requiredSkills[skillCount++] = s.skillName;
        cout << "Skill added: " << s.skillName << endl;
    }
}

void Sport::removeSkill(Skill &s) {
    for (int i = 0; i < skillCount; i++) {
        if (requiredSkills[i] == s.skillName) {
            for (int j = i; j < skillCount - 1; j++) {
                requiredSkills[j] = requiredSkills[j + 1];
            }
            skillCount--;
            cout << "Skill removed: " << s.skillName << endl;
            return;
        }
    }
    cout << "Skill not found." << endl;
}

void Skill::showSkillDetails() {
    cout << "Skill Name: " << skillName << endl << "ID: " << skillId << endl << "Description: " << description << endl;
}

void Skill::updateSkillDescription(string newDescription) {
    description = newDescription;
    cout << "Skill description updated." << endl;
}

int main() {
    Student s1("Saad", 1, 18, "Tennis");
    Mentor m1("Ali", 100, "Tennis", 3);
    Sport sp1("Tennis", 10, "Physical Game", "Physical Health");
    Skill sk1("Physical Health", 200, "For Athletes");
    
    cout<<"WAMIZA NOMAN 24K-0010\n"<<endl;

    s1.registerForMentorship(m1);
    s1.viewMentorDetails();
    sk1.showSkillDetails();
    s1.updateSportsInterest(sp1);
    m1.provideGuidance();
    m1.removeLearner(s1);
    m1.viewLearners();
    return 0;
}
