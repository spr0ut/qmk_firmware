# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
ENCODER_ENABLE = yes        # Enable rotary encoder
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes        # Mouse keys
EXTRAKEY_ENABLE = yes        # Audio control and System control
OLED_ENABLE = yes     # OLED display
LTO_ENABLE = yes 		   # significantly reduce the compiled size, but disable the legacy TMK Macros and Functions features
CONSOLE_ENABLE = no
OLED_BRIGHTNESS = 10
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend

# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
		./encoder.c \
		./oled.c \
		./process_records.c \
		# ./lib/render_logo.c \
		# ./lib/logo_reader.c \
        # ./lib/keylogger.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \
