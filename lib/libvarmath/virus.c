#include "virus.h" 
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdint.h>

v_knob knob_table[KNOB_TABLE_LEN];
int knob_table_idx = 0;

v_rule rule_table[RULE_TABLE_LEN];
int rule_table_idx = 0;

void v_register_knob(const char* name, setter s, getter g, maxlvl m) {
	if (knob_table_idx == KNOB_TABLE_LEN-1) {
		return;
	}
	strcpy(knob_table[knob_table_idx].name, name);
	knob_table[knob_table_idx].s = s;
	knob_table[knob_table_idx].g = g;
	knob_table[knob_table_idx].m = m;
	printf("%s is registered: %p, %p, %p\n", knob_table[knob_table_idx].name, knob_table[knob_table_idx].s, knob_table[knob_table_idx].g, knob_table[knob_table_idx].m);
	fflush(stdout);
	knob_table_idx++;
}


void v_add_config(v_knob *k, int p, v_sensor *s, float s_min, float s_max, int q_min, int q_max) {
	
	rule_table[rule_table_idx].k = k;
	rule_table[rule_table_idx].priority = p;
	rule_table[rule_table_idx].s = s;
	rule_table[rule_table_idx].s_min = s_min;
	rule_table[rule_table_idx].s_max = s_max;
	rule_table[rule_table_idx].q_min = q_min;
	rule_table[rule_table_idx].q_max = q_max;
	rule_table_idx++;
	printf("Registered rule for %s: %s [%.0f,%.0f) --> {%i,%i}\n", k->name, s->name, s_min, s_max, q_min, q_max);
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
			
			k = v_find_knob(method_name);
			if (k == NULL) 
				continue;
				
			s = v_find_sensor(sensor_name);
			if (s == NULL) 
				continue;
		
			v_add_config(k, priority, s, s_min, s_max, q_min, q_max);
			
			
		}
	}
    fclose(file);
}

v_knob * v_find_knob(const char* name) {
	int idx;
	for(idx = 0; idx < knob_table_idx; idx++) {
		if(strcmp(name, knob_table[idx].name) == 0) {
			return &knob_table[idx];
		}
	}
	return NULL;	
}



void v_mutate(v_knob *k, int lvl)
{
	if (lvl != k->g()) {
		k->s(lvl);
		//printf("Switched method %s to quality %i\n", k->name, k->g());
	}
}

void v_trigger_mutations() {
	int i;
	int q_max = 0;
	int q_min = 0;
	float s_val;
	v_rule *prev = NULL;
	for (i = 0; i < rule_table_idx; i++) {
		if((prev != NULL) & (strcmp(rule_table[i].k->name, prev->k->name)!=0)) {
			v_mutate(prev->k, q_max);
			q_max = 0;
			q_min = 0;	
		}
		// Priority is implied by the order of the file
		s_val = rule_table[i].s->curr_value;
		if ((s_val >= rule_table[i].s_min) & (s_val < rule_table[i].s_max)) {
			if (rule_table[i].q_max > q_max) {
				q_max = rule_table[i].q_max; 
			} 
			if (rule_table[i].q_min > q_min) {
				q_min = rule_table[i].q_min; 
			} 			
		}
		prev = &rule_table[i];

	}
	v_mutate(prev->k, q_max);
}

void __attribute__ ((constructor)) virusinit(void);

void virusinit(void) {
	v_parse_config("/home/lucas/qemuout/virus.conf");
}
