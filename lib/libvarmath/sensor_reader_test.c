#include "virus.h" 
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdint.h>

#define VAR_SOCKET_PATH		"/tmp/varsock"
#define VAR_SENSOR_DES_PATH		"/tmp/varsensordes"
#define VAR_SENSOR_VAL_PATH		"/tmp/varsensorval"

v_sensor sensor_table[SENSOR_TABLE_LEN];
int sensor_table_idx = 0;

float v_null_sensor()
{
	return 0;
}

void v_register_sensor(char *name, int idx)
{
    if (idx != sensor_table_idx) {
        printf("Registering sensor with incorrect index, %i != %i\n", idx,sensor_table_idx);
    }
	strcpy(sensor_table[sensor_table_idx].name, name);
	sensor_table[sensor_table_idx].curr_value = 0;
	sensor_table_idx++;
    printf("Registered sensor for %s\n", name);
}

void v_update_sensor(char *v, int idx)
{
    sensor_table[idx].curr_value = atof(v);
}

void v_parse_config(const char* filename) {
	char line[1024];	
	char method_name[256];
	int priority;
	char sensor_name[256];
	float s_min;
	float s_max;
	int q_min;
	int q_max;
	int r;
	v_knob *k;
	v_sensor *s;
	FILE *file = fopen ( filename, "r" );
	if ( file != NULL ) 
	{
		while ( fgets ( line, sizeof line, file ) != NULL )
		{		
			r=sscanf(line, "%s %i %s %f %f %i %i\n", method_name, &priority, sensor_name, &s_min, &s_max, &q_min, &q_max);
			if (r != 7)
				continue;
			
			
			if (k == NULL) 
				continue;
				
			s = v_find_sensor(sensor_name);
			if (s == NULL) 
				continue;
			
			
		}
	}
}

v_sensor * v_find_sensor(const char* name) {
	int idx;
	for(idx = 0; idx < sensor_table_idx; idx++) {
		if(strcmp(name, sensor_table[idx].name) == 0) {
			return &sensor_table[idx];
		}
	}
	return NULL;
}



int main()
{
    v_parse_sensor_descriptor();
    v_parse_sensor_values();
}
