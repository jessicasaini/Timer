#ifndef SECVIEW_H
#define SECVIEW_H
#include "Timer.h"
#include "iostream"
class SecView: public TimerView{
	public:
		SecView(Timer * timer): TimerView (timer){
		}
		virtual void display(std::ostream& os) const{
			os<<this->timer_->get()<<std::endl;
		}
};


#endif