#ifndef CLIBS_H
#define CLIBS_H

#include <stddef.h>

typedef struct {
  char *data;
  size_t size;
} data_t;

typedef void (*singleDataCallback)(data_t *data);
extern void singleData(data_t *data);

typedef void (*arrayDataCallback)(data_t *data, size_t size);
extern void arrayData(data_t *data, size_t size);

void getSingleData(singleDataCallback callback);

void getArrayData(arrayDataCallback callback);

data_t getItem(data_t *data, int index);

#endif /* CLIBS_H */