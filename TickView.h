#ifndef TICKVIEW_H
#define TICKVIEW_H
#include "Timer.h"
#include "iostream"
class TickView: public TimerView{
	public:
		TickView(Timer * timer): TimerView (timer){}
		virtual void display(std::ostream& os) const{
			os<<"*"<<std::endl;
		}
};


#endif