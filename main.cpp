/** Jagjot Saini ---------- A00891437 -------- Set 3S --------- c++ Assignment 2 **/
#include "Subject.h"
#include"Observer.h"
#include "Subject.h"
#include"Timer.h"
#include"TimerView.h"
#include"KeyBoardController.h"
#include"TickView.h"
#include "MinSecView.h"
#include "SecView.h"
using namespace std;
int main(){
	KeyBoardController * k = new KeyBoardController();
	Timer * t = new Timer();
	k->subscribe(t);
	TickView * tv = new TickView(t);
	MinSecView * msv = new MinSecView(t);
	SecView * sv = new SecView(t);
	t->subscribe(tv);
	t->subscribe(msv);
	t->subscribe(sv);
	k->start();
}