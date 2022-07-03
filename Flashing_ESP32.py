import Jetson.GPIO as GPIO

class FlashingESP32:
    def __init__(
        self,
        PICO_BOOT = 11,
        PICO_RESET = 18,
    ):
        """
        @param PICO_BOOT, the Jetson Nano board pin number used for the toggling the BOOT pin (GPIO0) on the ESP32-PICO-D4
        @param PICO_RESET, the Jetson Nano board pin number used for toggling the EN pin on the ESP32-PICO-D4
        """

        self.PICO_BOOT = PICO_BOOT
        self.PICO_RESET = PICO_RESET

    def setup(self):
        """Initialize GPIO pins"""
        #Set the GPIO mode if it has not been set yet
        if not GPIO.getmode():
            GPIO.setmode(GPIO.BOARD)

        GPIO.setup(self.PICO_BOOT, GPIO.OUT, initial = GPIO.HIGH) #set initial state to high to prevent ESP32 from entering bootloader mode
        GPIO.setup(self.PICO_RESET, GPIO.OUT, initial = GPIO.HIGH) #set initial state to high to prevent ESP32 from reseting
    
    def enter_bootloader_mode(self):
        GPIO.output(self.PICO_BOOT,GPIO.HIGH)
        GPIO.output(self.PICO_RESET,GPIO.HIGH)
        #TODO add delay
        GPIO.output(self.PICO_BOOT,GPIO.LOW)
        #TODO add delay
        GPIO.output(self.PICO_RESET,GPIO.LOW)
        #TODO add delay
        GPIO.output(self.PICO_RESET,GPIO.HIGH)
        #TODO add delay
        GPIO.output(self.PICO_BOOT,GPIO.HIGH)
    
    def reset_ESP32(self):
        GPIO.output(self.PICO_BOOT,GPIO.HIGH)
        GPIO.output(self.PICO_RESET,GPIO.HIGH)
        #TODO add delay
        GPIO.output(self.PICO_RESET,GPIO.LOW)
        #TODO add delay
        GPIO.output(self.PICO_RESET,GPIO.HIGH)
        