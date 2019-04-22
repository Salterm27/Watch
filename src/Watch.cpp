/*
  Watch.h - Library for interfacing with NN:nn watches and clocks (Ex: MM:SS or HH:MM) where the
  main focus is in counting capabilities 
  Created by Sebastian R Alterman, April 21, 2019.
  Released into the public domain.
*/

#include "Watch.h"
#include "Arduino.h"


//Constructor
Watch::Watch(){
	_LSD=Z_LSD;
	_MSD=Z_LSD;
}
Watch::Watch(Watch const &Src){
	_LSD = Src._LSD;
	_MSD = Src._MSD;
}
Watch::Watch(int const &L, int const &H = 0 ){
	_LSD=L;
	_MSD=H;
}

Watch::~Watch(){}

//Access operators
//This section is under developement
void Watch::setLSD(int const & sexa){
	_LSD = sexa;
}
void Watch::setMSD(int const & dec){
	_MSD = dec;
}
void Watch::setWatch(int const & sec, int const & dec = 0){
	_LSD = sec;
	_MSD = dec;
}

int Watch::getLSD () const{
	return _LSD;
}

int Watch::getMSD () const{
	return _MSD;
}

int Watch::getWatch() const{ // tbd if this is actually useful or not
	return _MSD*100+_LSD;
}

//counters
//This section is under developement
//WATCH COUNTERS
//This functions are meant to be run within a timer interrupt
void Watch::countUp(){
	_LSD++;
	if (_LSD>V_LSD){
		_LSD=Z_LSD;
		_MSD++;
	}

}

void Watch::countDown(){
  _LSD--;
  if(_LSD<Z_LSD){
    _LSD=V_LSD;
    _MSD--;
  }
}
