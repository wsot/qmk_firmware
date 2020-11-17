# MCU name
MCU = STM32F303

# Build Options
#   comment out to disable the options.
#
BACKLIGHT_ENABLE = no
BOOTMAGIC_ENABLE = yes      # Virtual DIP switch configuration (+1000)
STENO_ENABLE = yes
MOUSEKEY_ENABLE = no	    # Mouse keys (+4700)
EXTRAKEY_ENABLE = yes       # Audio control and System control (+450)
CONSOLE_ENABLE = no         # Console for debug (+400)
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # USB Nkey Rollover
AUDIO_ENABLE = no
RGBLIGHT_ENABLE = no
#LAYOUTS = ortho_4x12
MIDI_ENABLE = no            # MIDI support (+2400 to 4200, depending on config)
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches
NO_SUSPEND_POWER_DOWN = yes
UNICODEMAP_ENABLE = no
SWAP_HANDS_ENABLE = yes

# WS2812_DRIVER = spi
