

HEADERS:=$(shell find src -type f -name '*.h')

all: | clean extern configure build

clean:
	@rm -rf bin build
	@rm -f $(shell grep -ls '// Generated by dia2code' main.h ${HEADERS})

distclean: clean
	@rm -rf bin
	@make -s -C extern clean

extern: bin/dia2code

bin/dia2code:
	@make -s -j4 -C extern dia2code

configure:
	@mkdir -p build
	@cd build && cmake ..

build: bin/client

bin/client:
	@make -s -j4 -C build client

bin/server:
	@make -s -j4 -C build server

test:
	docker build -t plt-initial -f docker/plt-initial .
	./docker/validate.sh plt-test
	./docker/run_docker_bash.sh plt-test

diapdf: rapport/state.pdf rapport/render.pdf rapport/engine.pdf rapport/ai.pdf rapport/module.pdf

rapport/state.pdf: src/state.dia
	dia -e rapport/state.ps $<
	ps2pdf rapport/state.ps $@
	rm -f rapport/state.ps

rapport/render.pdf: src/render.dia
	dia -e rapport/render.ps $<
	ps2pdf rapport/render.ps $@
	rm -f rapport/render.ps

rapport/engine.pdf: src/engine.dia
	dia -e rapport/engine.ps $<
	ps2pdf rapport/engine.ps $@
	rm -f rapport/engine.ps

rapport/ai.pdf: src/ai.dia
	dia -e rapport/ai.ps $<
	ps2pdf rapport/ai.ps $@
	rm -f rapport/ai.ps

rapport/module.pdf: src/module.dia
	dia -e rapport/module.ps $<
	ps2pdf rapport/module.ps $@
	rm -f rapport/module.ps

.PHONY: configure build clean extern test
