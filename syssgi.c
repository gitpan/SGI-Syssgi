#include <stdio.h>
#include <stdlib.h>
#include <sys/syssgi.h>
#include <time.h>

#define 	PROM_BUFFER_SIZE	256
#define		NVRAM_INITSTATE		"initstate"
#define		NVRAM_PATH		"path"
#define		NVRAM_SHOWCONFIG	"showconfig"
#define		NVRAM_SWAP		"swap"
#define		NVRAM_VERBOSE		"verbose"


/*  -------------------------------------------------------------------------- */
/*  Function definitions                                                       */ 
/*  -------------------------------------------------------------------------- */
char *_SGI_SYSID (void);
char *_SGI_RDNAME (int process_id, unsigned int buf_space);
char *_SGI_GETNVRAM (char *prom_variable);
int   _SGI_SETLED (int led_state);
int   _SGI_SETNVRAM (char *prom_variable, char *prom_value);
int   _SGI_SSYNC (void);
int   _SGI_BDFLUSHCNT (unsigned int kern_write_delay);
int   _SGI_SET_AUTOPWRON (double power_on);
int   _SGI_GETTIMETRIM (void);
int   _SGI_SETTIMETRIM (signed int timetrim_value);

/*  -------------------------------------------------------------------------- */
/*  _SGI_SYSID                                                                 */
/*  Returns the unique system identifier.                                      */
/*  -------------------------------------------------------------------------- */
char *_SGI_SYSID (void) {
char *sysid_buffer = "";
	
	if ((sysid_buffer = (char *)malloc(MAXSYSIDSIZE)) != NULL) {

		if ((syssgi(SGI_SYSID, sysid_buffer)) < 0) {
			sprintf(sysid_buffer, "");
		}
	}

	return(sysid_buffer);
	free(sysid_buffer);
}


/*  -------------------------------------------------------------------------- */
/*  _SGI_SETLED                                                                */
/*  Turns on or off the led on the machine, this only works for some machines. */
/*  Platforms reported to work sofar is: Indigo2 and O2.                       */
/*  -------------------------------------------------------------------------- */
int _SGI_SETLED (int led_state)  {
signed int return_value = -1;

	if ((led_state == 1) || (led_state == 0)) {
		return_value = syssgi(SGI_SETLED, led_state);
	}

	return(return_value);
}


/*  -------------------------------------------------------------------------- */
/*  _SGI_RDNAME                                                                */
/*  Returns the process name for the process id specified in <process_id>.     */
/*  -------------------------------------------------------------------------- */
char *_SGI_RDNAME (int process_id, unsigned int buffer_space) {
char *proc_buffer = "";
	
	if ((process_id > 0) && (buffer_space)) {
		if ((proc_buffer = (char *)malloc(buffer_space)) != NULL) {
			if ((syssgi(SGI_RDNAME, process_id, proc_buffer, buffer_space)) < 0) {
				sprintf(proc_buffer, "");
			}
		}
	}

	return(proc_buffer);
	free(proc_buffer);
}


/* -------------------------------------------------------------------------- */
/* _SGI_GETNVRAM                                                              */
/* Retrieves the value associated with the by <prom_variable> specified prom  */
/* environment variable.                                                      */
/* -------------------------------------------------------------------------- */
char *_SGI_GETNVRAM (char *prom_variable) {
char *prom_result_buffer = "", *prom_variable_buffer = "";

	if (((prom_result_buffer = (char *)malloc(PROM_BUFFER_SIZE)) != NULL) && ((prom_variable_buffer = (char *)malloc(PROM_BUFFER_SIZE)) != NULL)) {
		sprintf(prom_variable_buffer, "%s", prom_variable);

		if ((syssgi(SGI_GETNVRAM, prom_variable_buffer, prom_result_buffer)) < 0) {
			sprintf(prom_result_buffer,"-1");
		}
	}

	return(prom_result_buffer);
	free(prom_result_buffer);
	free(prom_variable_buffer);
}


/* -------------------------------------------------------------------------- */
/* _SGI_SETNVRAM                                                              */
/* Alters the value associated with the by <prom_variable> specified prom     */
/* environment variable to the by <prom_value> specified value.               */
/* -------------------------------------------------------------------------- */
int _SGI_SETNVRAM (char *prom_variable, char *prom_value) {
char *prom_variable_buffer = "", *prom_value_buffer = "";
int return_value = -1;

	if (((prom_variable_buffer = (char *)malloc(PROM_BUFFER_SIZE)) != NULL) && ((prom_value_buffer = (char *)malloc(PROM_BUFFER_SIZE)) != NULL)) {
		sprintf(prom_variable_buffer, "%s", prom_variable);
		sprintf(prom_value_buffer, "%s", prom_value);
		
		return_value = syssgi(SGI_SETNVRAM, prom_variable_buffer, prom_value_buffer);
	}

	return(return_value);
}


/* -------------------------------------------------------------------------- */
/* _SGI_SSYNC                                                                 */
/* Synchronously flush out all delayed write buffers.                         */
/* -------------------------------------------------------------------------- */
int _SGI_SSYNC (void) {
int return_value = -1;

	return_value = syssgi(SGI_SSYNC);
	return(return_value);
}


/* -------------------------------------------------------------------------- */
/* _SGI_BDFLUSHCNT                                                            */
/* Delays the kernel from writing for <kern_write_delay> seconds and returns  */
/* the previous flush delay. The normal flush delay will be applied after     */
/* this call.                                                                 */
/* -------------------------------------------------------------------------- */
int _SGI_BDFLUSHCNT (unsigned int kern_write_delay) {
int return_value = -1;

	if (kern_write_delay > 0) {
		return_value = syssgi(SGI_BDFLUSHCNT, kern_write_delay);
	}
	
	return(return_value);
}


/* -------------------------------------------------------------------------- */
/* _SGI_SET_AUTOPWRON                                                         */
/* Sets the time at when the system is to automatically power up again. This  */
/* only works if the machine is powered off at this time. It is also only     */
/* implemented on the following: platforms: Octane (2?), Indy, Indigo2 and    */
/* Challenge M.                                                               */
/* -------------------------------------------------------------------------- */
int _SGI_SET_AUTOPWRON (double power_on) {
int return_value = -1;

	if ((power_on != 0) && ((time_t)power_on > time(NULL))) {
		return_value = syssgi(SGI_SET_AUTOPWRON, (time_t)power_on);
	}
	
	return(return_value);
}


/* -------------------------------------------------------------------------- */
/* _SGI_GETTIMETRIM                                                           */
/* Returns the current timetrim value. The system clock is adjusted every     */
/* second by the signed number of nanoseconds specified by this parameter.    */
/* -------------------------------------------------------------------------- */
int _SGI_GETTIMETRIM (void) {
int time_trim = 0, return_value = NULL;

	if ((return_value = syssgi(SGI_GETTIMETRIM, &time_trim)) != -1) {
		return_value = time_trim;
	}

	return(return_value);
}


/* -------------------------------------------------------------------------- */
/* _SGI_SETTIMETRIM                                                           */
/* Change the timetrim value from the value originally configued in:          */
/* /var/sysgen/mtune/kernel.                                                  */
/* -------------------------------------------------------------------------- */
int _SGI_SETTIMETRIM (signed int timetrim_value) {
int return_value = -1;

	return_value = syssgi(SGI_SETTIMETRIM, timetrim_value);
	return(return_value);
}


void main (void) {
	
	exit(0);
}
