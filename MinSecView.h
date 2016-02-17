#ifndef MINSECVIEW_H
#define MINSECVIEW_H
#include "Timer.h"
#include "iostream"
#include "iomanip"
class MinSecView: public TimerView{
	public:
		MinSecView(Timer * timer): TimerView (timer){
			
		}
		virtual void display(std::ostream& os) const {

			int seconds = this->timer_->get();
			int mins = seconds/60;
			int sec = seconds%60;
			os<<mins<<":"<<std::setw(2)<<std::setfill('0')<<sec<<std::endl;
		}
};


#endif