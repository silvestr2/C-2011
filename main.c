#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <string.h>
#include "navigation.h"
#include <math.h>
 
/*
 *
 */
 
ships *head=NULL;
 
int main(int argc, char** argv) {
    time *current_time = (time *)malloc(sizeof(time));
    ships *current_ships = (ships *)malloc(sizeof(ships));
    
        char path[30];
        double time;
        double step;
    FILE *file;
    printf("chuj: ");
    scanf("%s",&path);
	file=fopen(path,"r");
	printf("time: ");
   	scanf("%lf",&time);
   	printf("step: ");
   	scanf(" %lf",&step);
    	fscanf (file, "%d", &current_time->day);
        fscanf (file, "%d", &current_time->month);
        fscanf (file, "%d", &current_time->year);
        fscanf (file, "%d", &current_time->hour);
        fscanf (file, "%d", &current_time->minute);
        fscanf (file, "%d", &current_time->second);
       
        while (!feof(file)){
        fscanf (file, "%s", current_ships->ais_id);
        fscanf (file, " %lf", &current_ships->shiplocation.lat);
        fscanf (file, " %lf", &current_ships->shiplocation.lng);
        fscanf (file, " %lf", &current_ships->direction);
        fscanf (file, " %lf", &current_ships->speed);
        insert_ship(create_ship(current_ships->ais_id,current_ships->shiplocation,current_ships->direction,current_ships->speed));
        //printf("-> %s %d %d %7.3f %7.3f\n", current_ships->ais_id, current_ships->shiplocation.lat, current_ships->shiplocation.lng, current_ships->direction,current_ships->speed);
        }
        fclose(file);
       
       // print_all();
        update_all(time,step);
		
        getch();
    return (EXIT_SUCCESS);
}
ships *create_ship(char ais_id[],location shiplocation,double direction,double speed){
        ships *new_ship;
        new_ship=(ships *)malloc(sizeof(ships));
        strcpy(new_ship->ais_id,ais_id);
        new_ship->shiplocation=shiplocation;
        new_ship->direction=direction;
        new_ship->speed=speed;
        new_ship->next = NULL;
        return new_ship;
}
void insert_ship(ships *temporary_ship){
        if (head == NULL){  
        head=temporary_ship;  
        head->next=NULL;  
   }else  
   {  
      temporary_ship->next=head;  
      head=temporary_ship;  
   }  
}
 
void print_all(int time, int step){

        
		ships *current;
       
       
        current=head;
       
        if(current==NULL){
                printf("The list is empty");
        }else{
                printf("Elements of the list:\n");
                //traverse the entire linked list
                
				while(current!=NULL){
                        printf("* %s %7.3f %7.3f %7.3f %7.3f\n", current->ais_id, current->shiplocation.lat, current->shiplocation.lng, current->direction,current->speed);
                        current=current->next;
        }
        printf("\n");  
}
}

void update_all(double time,double timestep){
       	int i;
       	double howmanytimes;
       	howmanytimes=time*60/timestep;
	    ships *current;
        for(i=0;i<(int)howmanytimes;i++){
		current=head;
       
        if(current==NULL){
                printf("The list is empty");
        }else{
                
				while(current!=NULL){
                       double radians=current->direction*M_PI/180;
                       current->shiplocation.lat= current->shiplocation.lat+(current->speed*cos(radians)*timestep)/3600;
					    current->shiplocation.lng= current->shiplocation.lng+(current->speed*sin(radians)*timestep)/(cos(current->shiplocation.lng*M_PI/180))/3600;
						printf("* %s %7.3f %7.3f %7.3f %7.3f\n", current->ais_id, current->shiplocation.lat, current->shiplocation.lng, current->direction,current->speed);
                        current=current->next;
        }
        printf("\n");  
}
}
}
