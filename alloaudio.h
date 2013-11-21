#ifndef ALLOAUDIO_H
#define ALLOAUDIO_H

#include <jack/jack.h>

typedef enum {
    BASSMODE_NONE = 0,
    BASSMODE_MIX = 1,
    BASSMODE_LOWPASS = 2,
    BASSMODE_HIGHPASS = 3,
    BASSMODE_FULL = 4,
    BASSMODE_COUNT
} bass_mgmt_mode_t;

typedef struct connection_data connection_data_t;

connection_data_t *jack_initialize (int num_chnls);

void jack_close (connection_data_t *pp);

void set_filters(connection_data_t *pp, double **irs, int filter_len);


/* variable setters */
void set_global_gain(connection_data_t *pp, float gain);
void set_gain(connection_data_t *pp, int channel_index, float gain);
void set_mute_all(connection_data_t *pp, int mute_all);
void set_clipper_on(connection_data_t *pp, int clipper_on);
void set_room_compensation_on(connection_data_t *pp, int room_compensation_on);

/* set frequency to 0 to skip bass management cross-over filters, but still have signals added to subwoofers.
   set to -1 skip bass_management completely */
void set_bass_management_freq(connection_data_t *pp, double frequency);
void set_bass_management_mode(connection_data_t *pp, bass_mgmt_mode_t mode);
void set_sw_indeces(connection_data_t *pp, int i1, int i2, int i3, int i4);
void set_meter(connection_data_t *pp, int meter_on);

/* value getters */

int get_meter_values(connection_data_t *pp, float *values);
int get_num_chnls(connection_data_t *pp);
int is_closing(connection_data_t *pp);

#endif //ALLOAUDIO_H
