

#ifndef BANKINGSYSTEM_HISTORY_TRANSITION_LIST_H
#define BANKINGSYSTEM_HISTORY_TRANSITION_LIST_H
#include <string>
#include <ctime>

using namespace  std;
typedef struct history {
    std::string date_transaction;
    std::string time_transaction;
    float change;
    std::string status;
    history *next;
}hs;

class HISTORY_TRANSITION_LIST{
private:
   history *head;
   history *tail;
public:
    void addTime();
     void createTransitionNode();
    void fill_In_History_info(float change,string status);
    HISTORY_TRANSITION_LIST(float change,string status);
};




#endif //BANKINGSYSTEM_HISTORY_TRANSITION_LIST_H
