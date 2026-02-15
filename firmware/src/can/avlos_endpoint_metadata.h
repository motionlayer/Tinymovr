/*
* This file was automatically generated using Avlos.
* https://github.com/tinymovr/avlos
*
* Any changes to this file will be overwritten when
* content is regenerated.
*
* Endpoint type metadata for type-aware UART/ASCII parsing and formatting.
* No dependency on UART; consumed by the firmware layer.
*/

#pragma once
#include <stdint.h>

typedef enum {
    AVLOS_DTYPE_UINT8,
    AVLOS_DTYPE_UINT32,
    AVLOS_DTYPE_INT32,
    AVLOS_DTYPE_FLOAT,
    AVLOS_DTYPE_BOOL,
    AVLOS_DTYPE_STRING,
    AVLOS_DTYPE_VOID
} Avlos_Dtype;

typedef enum {
    AVLOS_EP_KIND_READ_ONLY,
    AVLOS_EP_KIND_WRITE_ONLY,
    AVLOS_EP_KIND_READ_WRITE,
    AVLOS_EP_KIND_CALL_NO_ARGS,
    AVLOS_EP_KIND_CALL_WITH_ARGS
} Avlos_EndpointKind;

#define AVLOS_MAX_CALL_ARGS 4

typedef struct {
    Avlos_EndpointKind kind;
    Avlos_Dtype value_dtype;
    uint8_t num_args;
    Avlos_Dtype arg_dtypes[AVLOS_MAX_CALL_ARGS];
} Avlos_EndpointMeta;

extern const Avlos_EndpointMeta avlos_endpoint_meta[];
extern const uint8_t avlos_endpoint_meta_count;
