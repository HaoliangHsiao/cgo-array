.PHONY: all c go run env

all: c go run

c:
	cmake -S ./clibs -B ./build
	make -C ./build

go:
	go build -o app ./cmd/server/*.go

run:
	./app
