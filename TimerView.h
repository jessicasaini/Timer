#ifndef TIMERVIEW_H
#define TIMERVIEW_H
#include "Timer.h"
#include "Observer.h"
#include <iostream>
class TimerView: public Observer {
	public:
		~TimerView(){
			timer_->unsubscribe(this);
		}
		TimerView(Timer *timer): timer_(timer){
		}
		
		TimerView(const TimerView&) = delete;
		TimerView & operator=(const TimerView&) = delete;
		
		virtual void update(Subject *){
			this->display(std::cout);
		}
		virtual void display(std::ostream& os) const = 0; //from observer class
	protected:
		Timer *timer_;
};
#endif
