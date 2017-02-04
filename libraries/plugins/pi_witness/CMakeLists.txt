file(GLOB HEADERS "include/graphene/pi_witness/*.hpp")

add_library( pi_witness 
             pi_witness.cpp
           )

target_link_libraries( pi_witness graphene_chain graphene_app graphene_time )
target_include_directories( pi_witness
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   pi_witness

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
