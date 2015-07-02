#ifndef VIRUS_H
#define VIRUS_H

#define KNOB_NAME_LEN	64
#define KNOB_TABLE_LEN	64

#define SENSOR_NAME_LEN	64
#define SENSOR_TABLE_LEN	16

#define RULE_TABLE_LEN	64


typedef void (*setter)( int );
typedef int (*getter)( void );
typedef int (*maxlvl)( void );

typedef struct {
	char name[KNOB_NAME_LEN];
	setter s;
	getter g; 
	maxlvl m;
} v_knob;

typedef struct {
	char name[SENSOR_NAME_LEN];
	float curr_value;
} v_sensor;

typedef struct {
	v_knob *k;
	v_sensor *s;
	int priority;
	float s_min;
	float s_max;
	int q_min;
	int q_max;		
} v_rule;



void v_register_knob(const char* name, setter s, getter g, maxlvl m);
void v_parse_config(const char* filename);
void v_register_sensors();
void v_trigger_mutations();


v_knob * v_find_knob(const char* name);
v_sensor * v_find_sensor(const char* name);

#endif // VIRUS_H
