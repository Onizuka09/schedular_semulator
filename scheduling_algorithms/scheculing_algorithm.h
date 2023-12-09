#ifndef _SCHEDULING_ALGO__ 
#define _SCHEDULING_ALGO__

#include <stdio.h>		
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>
#include "../dataStruct/queue.h"
#include "../display_manger/display_conf.h" 
#include "../process_config/global_config.h"
#include "../process_def.h"
#include "../file_manipulation/csv_file_manip.h"
#include "../dataStruct/linkedlist.h"

void FIFO_algo(void);
void SRT_algo(void);
void Round_Robin_algo(void);
void Priority_algo(void);
#endif