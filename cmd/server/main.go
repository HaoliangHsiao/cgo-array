package main

/*
#cgo CFLAGS: -I${SRCDIR}/../../clibs
#cgo LDFLAGS: -L${SRCDIR}/../../build -ldemosdk
#include "../../clibs/clibs.h"
*/
import "C"
import "log"

func main() {
	log.Printf("Server init ...")
	C.getSingleData(C.singleDataCallback(C.singleData))
	C.getArrayData(C.arrayDataCallback(C.arrayData))
}

//export singleData
func singleData(data *C.data_t) {
	log.Printf("singleData() ...")

	log.Printf("data = %v", C.GoString(data.data))
	log.Printf("size = %v", data.size)
}

//export arrayData
func arrayData(data *C.data_t, size C.size_t) {
	log.Printf("singleData(), count %v", size)

	log.Printf("data = %v", C.GoString(data.data))
	log.Printf("size = %v", data.size)

	item := C.getItem(data, 0)

	log.Printf("item.data= %v", C.GoString(item.data))
	log.Printf("item.size = %v", item.size)

}
