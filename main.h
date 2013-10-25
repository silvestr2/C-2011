#ifndef _MAIN_H_
#define _MAIN_H_
#include "navigation.h"

 typedef struct time{
		short day;
		short month;
		short year;
		short hour;
		short minute;
		short second;
		}time;
		
typedef struct ships{
		char ais_id[10];
		location shiplocation;
	//	double latitude;
	//	double longitude;
		double direction;
		double speed;
		struct ships *next;
	}ships;
		
ships *create_ship(char ais_id[], location shiplocation ,double direction,double speed);
void insert_ship(ships *temporary_ship);
void update_all();
void print_all();
	
#endif
