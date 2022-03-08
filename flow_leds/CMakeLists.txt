add_executable(
  flow_leds
  flow_leds.c
)

# pull in common dependencies
target_link_libraries(flow_leds pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(flow_leds)

# add url via pico_set_program_url
example_auto_set_url(flow_leds)
