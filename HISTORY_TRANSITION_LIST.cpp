//
// Created by minhn on 11/2/2023.
//

#include "HISTORY_TRANSITION_LIST.h"
#include <iostream>
void HISTORY_TRANSITION_LIST::createTransitionNode() {
    history* p =new history;
    if (tail)
        head = tail = p;
    else {
        tail->next = p;
        tail = p;
    }
    p = nullptr;
    delete p;
}
void  HISTORY_TRANSITION_LIST::addTime(){
    if(tail) return;
    string date;
    string d_time;
    time_t now;
    struct tm nowLocal;
    now = time(NULL);
    nowLocal = *localtime(&now);
    date += to_string(nowLocal.tm_mday) + "/" + to_string(nowLocal.tm_mon+1) +"/" + to_string(nowLocal.tm_year+1900);
    cout <<date<<endl;
    int hour = nowLocal.tm_hour;
    d_time += to_string(hour) + ":" + to_string(nowLocal.tm_min);
    if(hour > 12){
        d_time+=" PM";
    } else{
        d_time+=" AM";
    }
    tail->date_transaction = date;
    tail->time_transaction = d_time;
}
void HISTORY_TRANSITION_LIST::fill_In_History_info(float change,string status) {
    addTime();
    tail->change = change;
    tail->status = status;
    tail->next = nullptr;
    createTransitionNode();
}
HISTORY_TRANSITION_LIST::HISTORY_TRANSITION_LIST(float change_prmt, string status_prmt){
    head = tail = nullptr;
    createTransitionNode();
    fill_In_History_info(change_prmt,status_prmt);
}
