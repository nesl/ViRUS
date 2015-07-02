#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#include "virus.h" 

/*
#define VAR_SOCKET_PATH		"/mnt/varsock"
#define VAR_SENSOR_DES_PATH		"/mnt/varsensordes"
#define VAR_SENSOR_VAL_PATH		"/mnt/varsensorval"
*/

#define VAR_SOCKET_PATH		"//home/lucas/qemuout/varsock"
#define VAR_SENSOR_DES_PATH		"//home/lucas/qemuout/varsensordes"
#define VAR_SENSOR_VAL_PATH		"//home/lucas/qemuout/varsensorval"


v_sensor sensor_table[SENSOR_TABLE_LEN];
int sensor_table_idx = 0;

v_sensor * v_find_sensor(const char* name) {
	int idx;
	for(idx = 0; idx < sensor_table_idx; idx++) {
		if(strcmp(name, sensor_table[idx].name) == 0) {
			return &sensor_table[idx];
		}
	}
	return NULL;	
}

void v_register_pid() {
  
	char buf[16];
	int fd, mypid, len;

	struct sockaddr_un addr;
	memset(&addr, 0, sizeof(addr));
	addr.sun_family = AF_UNIX;
	strncpy(addr.sun_path, VAR_SOCKET_PATH, sizeof(addr.sun_path)-1);	

	fd = socket(AF_UNIX, SOCK_STREAM, 0);

	if (connect(fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
		perror("Can't connect to variability monitor server");
		return;
	}

	mypid = getpid();
	sprintf(buf,"%d",mypid);
	len = strlen(buf)+1;
	
	if (write(fd, buf, len) != len) {
		perror("Can't write to variability monitor server");
        return;
    }
    
    close(fd);

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

typedef void (*tokenparser)( char* token, int idx );

void v_parse_file(char *filename, tokenparser cb) {
    char line[1024];
	FILE *file = fopen ( filename, "r" );
	if ( file != NULL )
	{
		if ( fgets ( line, sizeof line, file ) != NULL )
		{
            int tidx = 0;
            char* token = strtok(line, " ");
            while (token) {
                if(strlen(token) > 1) {
                    cb(token, tidx);
                }
                tidx++;
                token = strtok(NULL, " ");
            }
		}
	}
    fclose(file);
}

void v_parse_sensor_descriptor() {
	printf("Parsing sensor desc\n");
    v_parse_file(VAR_SENSOR_DES_PATH, v_register_sensor);
}

void v_parse_sensor_values() {
	printf("Parsing sensor values\n");
    v_parse_file(VAR_SENSOR_VAL_PATH, v_update_sensor);
}

void __attribute__ ((constructor)) vmoninit(void);

void sighandler(int signal) {
	printf("Caught USR1 Signal: parsing sensor values and triggering mutations\n");
    v_parse_sensor_values();	
	v_trigger_mutations();
}

void vmoninit(void) {
	v_register_pid();
    v_parse_sensor_descriptor();
    v_parse_sensor_values();
    
	printf("Registering signal\n");
	
	signal(SIGUSR1,sighandler);
}





