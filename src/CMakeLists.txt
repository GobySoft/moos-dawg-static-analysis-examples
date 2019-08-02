option(build_clang_analyzer "Build clang analyzer example" OFF)
option(build_state_machine "Build state machine examples" OFF)
option(build_goby_graphs "Build Goby pub/sub connection examples" OFF)

# only build the clang_analyzer example to save time when using scan-build
if(build_clang_analyzer)  
  add_subdirectory(clang_analyzer)
else()
  add_subdirectory(messages)

  if(build_state_machine)
    add_subdirectory(state_machine)
  endif()
  
  if(build_goby_graphs)
    add_subdirectory(gps_driver)
  endif()
  
endif()
