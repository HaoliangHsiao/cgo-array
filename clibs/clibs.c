#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "clibs.h"

void getSingleData(singleDataCallback callback) {
    printf("sgetSingleData()\n");
    if(!callback) {
        printf("sgetSingleData() call back is null\n");
        return;
    }

    data_t *data = NULL;
    data = (data_t *) malloc(sizeof(data_t));
    data->data = "Single data 1";
    data->size = 1;
    callback(data);
}

void getArrayData(arrayDataCallback callback) {
    printf("arrayDataCallback()\n");
    int count = 3;
    if(!callback) {
        printf("arrayDataCallback() call back is null\n");
        return;
    }
    data_t *array = NULL;
    array = (data_t *) malloc(sizeof(data_t) * count);
    memset(array, 0, sizeof(data_t) * count);

    for(int i = 0; i < count; i++) {
        array[i].data = "Array data";
        array[i].size = i+1;
    }
    callback(array, count);
}

data_t getItem(data_t *data, int index) {
    return data[index];
}