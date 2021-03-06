/**
 * \author Hyoung Min Suh
 */

#ifndef _CSTREAM_H_
#define _CSTREAM_H_

#include "config.h"

#define CSTREAM_FAILURE -1
#define CSTREAM_SUCCESS 0
#define CSTREAM_NO_DATA 1

typedef struct cstream cstream_t;

typedef void (*generic_func_t)(sensor_data_t);

/**
 * Allocates and initializes a new Stream-Like Buffer with all the necessery locks
 * and garbage collector thread. 
 * \param buffer a double pointer to the buffer that needs to be initialized
 * \param streamJobs kind of job functions that will be attatched to the stream
 * \param threadCount number of total functional thread that will be attatched to the stream 
 * \return CSTREAM_SUCCESS on success and CSTREAM_FAILURE if an error occurred
 */
int cstream_init(cstream_t **buffer, int streamJobs,int threadCount);

/**
 * All allocated resources are freed and cleaned up
 * \param buffer a double pointer to the buffer that needs to be freed
 * \return CSTREAM_SUCCESS on success and CSTREAM_FAILURE if an error occurred
 */
int cstream_free(cstream_t **buffer);


/**
 * Inserts the sensor data in 'data' at the end of 'buffer' (at the 'tail')
 * \param buffer a pointer to the buffer that is used
 * \param func a pointer to the generic function that will be applied to the data element of the stream
 * \param job_nr a designated job number that user will assign to the function, should start from 1 and increase consecutively
 * \return CSTREAM_SUCCESS on success and CSTREAM_FAILURE if an error occured
*/
void stream_function_init(cstream_t * buffer, generic_func_t func, int job_nr);

/**
 * Inserts the sensor data in 'data' that will be processed by stream_function at the end of the stream
 * \param buffer a pointer to the buffer that is used
 * \param data a pointer to sensor_data_t data, that will be copied into the buffer
 * \return CSTREAM_SUCCESS on success and CSTREAM_FAILURE if an error occured
*/
int cstream_insert(cstream_t *buffer, sensor_data_t *data);


#endif  //_CSTREAM_H_
