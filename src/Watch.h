/*
  Watch.h - Library for interfacing with NN:nn watches and clocks (Ex: MM:SS or HH:MM) where the
  main focus is in counting capabilities 
  Created by Sebastian R Alterman, April 21, 2019.
  Released into the public domain.
*/
#ifndef Watch_h
#define  Watch_h
#include <Arduino.h>

// Constants
#define V_MSD 99 //overflow MSD
#define Z_MSD 0

#define V_LSD 59//overflow LSD
#define Z_LSD 0

class Watch{
	private:
		int _MSD; // two Most significant digits. Range 0-99
		int _LSD; // two Least significant digits. Range 0-60
	public:
		Watch();//default constructor
		Watch( Watch const &); //constructor by Copy 
		Watch (int const &, int const & = 0); //Constructor by parameters
		~Watch();
		//setters and getters
		void setMSD (int const &);
		void setLSD (int const &);
		void setWatch (int const &l, int const &m=0);
		int getMSD() const;
		int getLSD() const;
		int getWatch() const;
		//counting functions
		//void SetUp(char const & , int const &); // select a timer and sets up clock frequency
		void countUp();
		void countDown();
};
#endif
