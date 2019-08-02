#!/bin/bash

mkdir -p build

pushd build >& /dev/null
cmake .. ${MOOSDAWG_CMAKE_FLAGS} -Dbuild_state_machine=OFF -Dbuild_goby_graphs=ON
make $@ ${MOOSDAWG_MAKE_FLAGS} -j`nproc`
popd >& /dev/null
