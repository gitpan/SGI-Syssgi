/* syssgi */

%module syssgi

#define		NVRAM_INITSTATE		"initstate"
#define		NVRAM_PATH		"path"
#define		NVRAM_SHOWCONFIG	"showconfig"
#define		NVRAM_SWAP		"swap"
#define		NVRAM_VERBOSE		"verbose"

extern char 	*_SGI_SYSID (void);
extern char 	*_SGI_RDNAME (int process_id, unsigned int buf_space);
extern char 	*_SGI_GETNVRAM (char *prom_variable);
extern int 	 _SGI_SETLED (int led_state);
extern int 	 _SGI_SETNVRAM (char *prom_variable, char *prom_value);
extern int 	 _SGI_SSYNC (void);
extern int 	 _SGI_BDFLUSHCNT (unsigned int kern_write_delay);
extern int	 _SGI_SET_AUTOPWRON (double power_on);
extern int   	 _SGI_GETTIMETRIM (void);
extern int   	 _SGI_SETTIMETRIM (signed int timetrim_value);
