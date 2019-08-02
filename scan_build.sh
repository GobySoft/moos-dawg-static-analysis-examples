#!/bin/bash

rm -rf /tmp/scan-build-moos-dawg
rm -rf build

mkdir -p build

pushd build >& /dev/null
scan-build --use-cc=/usr/bin/clang --use-c++=/usr/bin/clang++ cmake .. -Dbuild_clang_analyzer=ON ${MOOSDAWG_CMAKE_FLAGS}
scan-build -o /tmp/scan-build-moos-dawg --use-cc=/usr/bin/clang --use-c++=/usr/bin/clang++ --status-bugs cmake --build . -- $@ ${MOOSDAWG_MAKE_FLAGS} -j`nproc`
scan-view /tmp/scan-build-moos-dawg/*
popd >& /dev/null
