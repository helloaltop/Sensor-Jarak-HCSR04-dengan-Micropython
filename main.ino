import machine
import time

# Inisialisasi pin untuk sensor HC-SR04
trigger_pin = machine.Pin(4, machine.Pin.OUT)  # Ganti dengan pin yang sesuai
echo_pin = machine.Pin(5, machine.Pin.IN)     # Ganti dengan pin yang sesuai

def measure_distance():
    # Mengatur trigger pin
    trigger_pin.value(0)
    time.sleep_us(2)
    trigger_pin.value(1)
    time.sleep_us(10)
    trigger_pin.value(0)
    
    # Mengukur waktu dari echo pin
    while echo_pin.value() == 0:
        pulse_start = time.ticks_us()
    
    while echo_pin.value() == 1:
        pulse_end = time.ticks_us()
    
    pulse_duration = time.ticks_diff(pulse_end, pulse_start)
    
    # Hitung jarak dalam cm
    distance = pulse_duration * 0.0343 / 2
    
    return distance

while True:
    try:
        distance = measure_distance()
        print('Jarak: {:.2f} cm'.format(distance))
    except Exception as e:
        print('Gagal mengukur jarak:', e)
    
    time.sleep(1)  # Delay sebelum pengukuran berikutnya

