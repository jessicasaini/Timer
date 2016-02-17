#ifndef KEYBOARDCONTROLLER_H
#define KEYBOARDCONTROLLER_H
#include "Subject.h"
#include <sstream>
#include <string>

class KeyBoardController: public Subject{
		public: 
			void start(){
			std::string line;
				while (getline(std::cin, line)){
					std::string s;
					std::istringstream iss(line);
					if(iss>>s){
						switch (s[0]){
							case 's':
								cmd_ = "s";
								this->notify();
								break;
							case 'h':
								cmd_ = "h";
								this->notify();
								break;
							case 'r':
								cmd_ = "r";
								this->notify();
								break;
						}
					}
					line.clear();
				}
			} //start the loop to get commands
			std::string getCommand() const{
				return cmd_;
			} //return command
		private:
			std::string cmd_;

};
#endif
