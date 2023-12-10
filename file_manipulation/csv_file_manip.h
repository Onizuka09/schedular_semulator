#ifndef _CSV_FILE_MANIP_H_
#define _CSV_FILE_MANIP_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../process_def.h"
#include "../process_config/global_config.h"
#include "../dataStruct/linkedlist.h"
#include "../display_manger/display_conf.h"

bool Create_CSV_file(char *filename,char* header);
int generate_num_proc(void) ;
bool fill_csv_file(char *file_name);
node* Read_csv_file(char *file_name,int *nbr);
bool is_file_exits(char *file_name);
void print_csv_file_processes(char *file_name);
bool remove_file();

#endif