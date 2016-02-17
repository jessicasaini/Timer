#ifndef SUBJECT_H
#define SUBJECT_H
#include "Observer.h"
#include <list>
#include <iterator>
class Subject {
	public:
		virtual ~Subject(){}
		virtual void subscribe(Observer *obs);
		virtual void unsubscribe (Observer *obs);
		virtual void notify();
	protected: 
		Subject(){}
	private: 
		std::list<Observer *> observers_;
};

inline void Subject::subscribe(Observer *obs){
	observers_.push_back(obs);
}
inline void Subject::unsubscribe (Observer *obs){
	for (auto it = observers_.begin(); it != observers_.end(); it++ ){
		if (*it == obs){
			observers_.erase(it);
		}
	}
}
inline void Subject::notify(){

	for (auto x: observers_){
		x->update(this);
	}
}
#endif