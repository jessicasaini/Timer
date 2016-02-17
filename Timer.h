#ifndef TIMER_H
#define TIMER_H
#include "Observer.h"
#include "Subject.h"
#include <atomic>
#include <iostream>
#include <string>
#include <thread>
#include <unistd.h>
#include "KeyBoardController.h"
class Timer: public Observer, public Subject{
	public:
		
		Timer(): sec_(0), ticking_(0){
			std::thread t(&Timer::run, this);
			t.detach();
		}
		void start(){
			ticking_ = 1;
		} //start the timer
		void stop(){
			ticking_ = 0;
		}//stop the timer
		void reset(){
			sec_ = 0;
		}// reset to 0
		unsigned long get() const{
			return sec_;
		} //returns number of elapsed seconds 
		void update (Subject * s){
			std::string command = ((KeyBoardController*)s)->getCommand();
			switch (command[0]){
				case 'r':
					this->reset();
					break;
				case 's':
					this->start();
					break;
				case 'h':
					this->stop();
					break;
			}
		}
		// inherited method
		
		Timer(const Timer&) = delete;
		Timer& operator=(const Timer&) = delete;
	private:
		std::atomic_ulong sec_; //seconds elapsed
		std::atomic_bool ticking_; //is timer ticking or not
		void run(){
			while(1){
				sleep(1);
				if(ticking_ == 1){
					sec_++;
					this->notify();
					//std::cout<<"*"<<std::endl;
				}
			}
		} //function executed by thread
};


#endif




