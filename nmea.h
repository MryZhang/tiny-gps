#define NMEA_MINUTE_FRACTS 4
#define NMEA_ALTITUDE_FRACTS 4

#define NMEA_RMC_FLAGS_STATUS_OK 0
#define NMEA_RMC_FLAGS_LAT_NORTH 1
#define NMEA_RMC_FLAGS_LON_EAST 2

struct coord {
	/* degrees, 0-180 or 0-90 */
	uint8_t deg;
	/* minutes, 0-60 */
	uint8_t min;
	/* fractions of minutes saved as BCD */
	uint8_t frac[(NMEA_MINUTE_FRACTS+1)/2];
};

struct altitude_t {
	int16_t m;
	uint8_t frac[(NMEA_ALTITUDE_FRACTS+1)/2];
};

struct clock_t {
	uint8_t hour;
	uint8_t minute;
	uint8_t second;
};

struct date_t {
	uint8_t day;
	uint8_t month;
	uint8_t year;
};

struct nmea_rmc_t {
	/* flag bits (lsb to msb):
	 * 0 status (1 == OK, 0 == warning)
	 * 1 latitude alignment (1 == N, 0 == S)
	 * 2 longitude alignment (1 == E, 0 == W)
	 */
	uint8_t flags;
	struct date_t date;
	struct clock_t clock;
	struct coord lat;
	struct coord lon;
};

struct nmea_gga_t {
	struct altitude_t alt;
	uint8_t quality;
	uint8_t sats;
};

struct nmea_data_t {
	uint8_t flags;
	struct date_t date;
	struct clock_t clock;
	struct coord lat;
	struct coord lon;
	struct altitude_t alt;
	uint8_t quality;
	uint8_t sats;
};

void nmea_process_character(char c);

